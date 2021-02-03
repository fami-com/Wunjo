//
// This file is licensed under MPL 2.0, GNU GPL v2.0+ and GNU LGPL v2.1+
// For more information about the licensing, see the LICENSE file in the project root
// Copyright (c) 2021 - 2021 fami-com
//

#include "Scanner.h"

namespace Lexer {
    Scanner::Scanner(std::string& input) noexcept : code(input), tokens(std::vector<Token::Token>{}) {
        start = 0;
        pos = 0;
        column = 0;
        line = 0;
        error = std::nullopt;
    }

    bool Scanner::end()  const noexcept {
        return pos >= code.length();
    }

    char Scanner::next() noexcept {
        if(end()) return '\0';
        auto c = code.at(pos++);
        if (c == '\n') {
            column = 0;
            line++;
        } else {
            column++;
        }
        return c;
    }

    bool Scanner::consume(char expect) noexcept {
        if (end()) return false;
        if (peek() != expect) return false;
        next();
        return true;
    }

    bool Scanner::match(char expect) noexcept {
        return !end() && peek() == expect;
    }

    bool Scanner::match(bool (*predicate)(char)) noexcept {
        return !end() && predicate(peek());
    }

    char Scanner::peek() noexcept {
        if (end()) return '\0';
        return code.at(pos);
    }

    void Scanner::add_token(type type) noexcept {
        tokens.emplace_back(type, line, column);
    }

    void Scanner::add_token(type type, const Token::TokenData& data) noexcept {
        tokens.emplace_back(type, data, line, column);
    }

    bool Scanner::scan_once() noexcept {
        start = column;
        auto c = next();
        switch (c) {
            case '\0': return false;
            case ' ':
            case '\t':
            case '\r':
            case '\n':
                break;
            case '(':
                add_token(type::PAREN_OPEN);
                break;
            case ')':
                add_token(type::PAREN_CLOSE);
                break;
            case '[':
                add_token(type::BRACKET_OPEN);
                break;
            case ']':
                add_token(type::BRACKET_CLOSE);
                break;
            case '{':
                add_token(type::BRACE_OPEN);
                break;
            case '}':
                add_token(type::BRACE_CLOSE);
                break;
            case ':':
                if(consume('=')){
                    add_token(type::ASSIGN_EXPR);
                } else {
                    add_token(type::COLON);
                }
                break;
            case ';':
                add_token(type::SEMICOLON);
                break;
            case '?':
                add_token(type::QUESTION);
                break;
            case ',':
                add_token(type::COMMA);
                break;
            case '\\':
                add_token(type::BACKSlASH);
                break;
            case '~':
                add_token(type::TILDE);
                break;
            case '@':
                add_token(type::AT);
                break;
            case '$':
                add_token(type::DOLLAR);
                break;
            case '+':
                if(consume('+')){
                    add_token(type::PLUS_DOUBLE);
                } else {
                    add_token(type::PLUS);
                }
                break;
            case '-':
                if(consume('>')){
                    add_token(type::ARROW_RIGHT);
                } else {
                    add_token(type::MINUS);
                }
                break;
            case '<':
                if (consume('-')){
                    add_token(type::ARROW_LEFT);
                } else if (consume('=')){
                    if (consume('>')){
                        add_token(type::LESS_EQUAL_GREATER);
                    } else {
                        add_token(type::LESS_EQUAL);
                    }
                } else if (consume('<')){
                    add_token(type::SHIFT_LEFT);
                } else {
                    add_token(type::LESS);
                }
                break;
            case '>':
                if(consume('=')){
                    add_token(type::GREATER_EQUAL);
                } else if (consume('>')){
                    add_token(type::SHIFT_RIGHT);
                } else {
                    add_token(type::GREATER);
                }
            case '=':
                if (consume('=')){
                    add_token(type::EQUAL);
                } else if (consume('>')){
                    add_token(type::ARROW_RIGHT_DOUBLE);
                } else {
                    add_token(type::ASSIGN);
                }
                break;
            case '!':
                if (consume('=')){
                    add_token(type::NOT_EQUAL);
                    break;
                } else {
                    set_error(InvalidCharacter{line, start, c});
                    return false;
                }
            case '.':
                if (consume('.')){
                    if (consume('.')){
                        add_token(type::PERIOD_TRIPLE);
                    } else {
                        add_token(type::PERIOD_DOUBLE);
                    }
                } else {
                    add_token(type::PERIOD);
                }
            case '*':
                if(consume('*')){
                    add_token(type::STAR_DOUBLE);
                } else {
                    add_token(type::STAR);
                }
                break;
            case '/':
                if(consume('/')){
                    add_token(type::SLASH_DOUBLE);
                } else {
                    add_token(type::SLASH);
                }
                break;
            case '%':
                if(consume('%')){
                    add_token(type::PERCENT_DOUBLE);
                } else {
                    add_token(type::PERCENT);
                }
                break;
            case '^':
                add_token(type::CARET);
                break;
            case '&':
                add_token(type::AMPERSAND);
                break;
            case '|':
                add_token(type::PIPE);
                break;
            case '#':
                while(peek() != '\n' && !end()) next();
                break;
            case '"': {
                if(auto v = match_string()) {
                    add_token(type::STRING, *v);
                } else {
                    return false;
                }
                break;
            }
            default:
                if(is_digit(c)){
                    if(auto v = match_number(c)){
                        auto idx = (*v).index();
                        if(idx == 0){
                            add_token(type::INTEGER, std::get<int64_t>(*v));
                        } else {
                            add_token(type::FLOAT, std::get<double>(*v));
                        }
                    } else {
                        return false;
                    }
                } else if(is_id_start(c)){
                    auto v = match_identifier(c);
                    auto idx = v.index();
                    if(idx == 0){
                        add_token(std::get<type>(v));
                    } else {
                        add_token(type::IDENTIFIER, std::get<std::string>(v));
                    }
                } else {
                    set_error(InvalidCharacter{line, start, c});
                    return false;
                }
                break;
        }
        return true;
    }

    void Scanner::run() noexcept {
        while(!end() && error) scan_once();
    }

    bool Scanner::is_digit(char c) noexcept {
        return c >= '0' && c <= '9';
    }

    bool Scanner::is_alpha(char c) noexcept {
        return is_upper(c) || is_lower(c);
    }

    bool Scanner::is_upper(char c) noexcept {
        return c >= 'A' && c <= 'Z';
    }

    bool Scanner::is_lower(char c) noexcept {
        return c >= 'a' && c <= 'z';
    }

    bool Scanner::is_alnum(char c) noexcept {
        return is_digit(c) || is_alpha(c);
    }

    bool Scanner::is_id_start(char c) noexcept {
        return is_alpha(c) || c == '_';
    }

    bool Scanner::is_id_cont(char c) noexcept {
        return is_alnum(c) || c == '_';
    }

    int Scanner::numeric_value(char c) noexcept {
        if(is_digit(c)){
            return c - 48;
        } else if (is_upper(c)){
            return c - 55;
        } else if (is_lower(c)){
            return c - 87;
        }
        return -1;
    }

    std::optional<std::variant<int64_t, double>> Scanner::match_number(char in) noexcept {
        std::string scanned{};
        bool is_decimal{};
        bool is_based{};
        int base = 10;

        for(;;) {
            if (is_digit(in)) {
                scanned.push_back(in);
            } else if (is_alnum(in) && is_based) {
                if (numeric_value(in) > base - 1) {
                    set_error(InvalidNumericLiteral{line, column, in, base});
                    return std::nullopt;
                }
                scanned.push_back(in);
            } else if (in == '.' && !is_based) {
                scanned.push_back(in);
                is_decimal = true;
            } else if (in == 'r' || in == 'R') {
                is_based = true;
                base = std::stoi(scanned);
                if (base < 2 || base > 36) {
                    set_error(InvalidBase{line, column, base});
                    return std::nullopt;
                }
                scanned.clear();
            }

            if (match(is_digit) || match('.') || match('r') || match('R') || (match(is_alpha) && is_based)) {
                in = next();
            } else {
                break;
            }
        }

        if(is_decimal){
            return std::stod(scanned, nullptr);
        } else {
            return std::stoll(scanned, nullptr, base);
        }
    }

    std::optional<std::string> Scanner::match_string() noexcept {
        std::string scanned{};

        while(!match('"') && !end()){
            scanned.push_back(next());
        }

        if(end()) {
            error = UnterminatedString{line, column};
            return std::nullopt;
        }

        return scanned;
    }

    std::variant<type,std::string> Scanner::match_identifier(char in) noexcept {
        std::string scanned{};

        while(is_id_cont(in)){
            scanned.push_back(in);
            in = next();
        }

        if (auto v = Token::decode(scanned)){
            return *v;
        } else {
            return scanned;
        }
    }

    void Scanner::set_error(ScannerError err) noexcept {
        error = err;
    }

    std::optional<ScannerError> Scanner::get_error() const noexcept {
        return error;
    }
}
