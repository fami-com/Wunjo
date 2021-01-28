//
// Created by V on 2021-01-22.
//

#include "Lexer.h"
#include "../Common/Visitor.h"
#include <stdexcept>

namespace Lexer {
    Lexer::Lexer(std::u8string& input) noexcept : code(input), tokens(std::vector<token>{}) {
        start = 0;
        pos = 0;
        column = 0;
        line = 0;
    }

    bool Lexer::end() {
        return pos < code.length() - 1;
    }

    char8_t Lexer::advance() {
        auto c = code[pos++];
        if (c == u8'\n') {
            column = 0;
            line++;
        } else {
            column++;
        }
        return c;
    }

    bool Lexer::consume(char8_t expect) {
        if (end()) return false;
        if (peek() != expect) return false;
        advance();
        return true;
    }

    char8_t Lexer::peek() {
        if (end()) return u8'\0';

        return code[pos];
    }

    void Lexer::add_token(type type) {
        tokens.emplace_back(type);
    }

    void Lexer::add_token(type type, const std::any& data) {
        tokens.emplace_back(type, data);
    }

    LexerError Lexer::scan_once() {
        auto c = advance();
        start = column;
        switch (c) {
            case u8'(':
                add_token(type::PAREN_OPEN);
                break;
            case u8')':
                add_token(type::PAREN_CLOSE);
                break;
            case u8'[':
                add_token(type::BRACKET_OPEN);
                break;
            case u8']':
                add_token(type::BRACKET_CLOSE);
                break;
            case u8'{':
                add_token(type::BRACE_OPEN);
                break;
            case u8'}':
                add_token(type::BRACE_CLOSE);
                break;
            case u8':':
                if(consume(u8'=')){
                    add_token(type::ASSIGN_EXPR);
                } else {
                    add_token(type::COLON);
                }
                break;
            case u8';':
                add_token(type::SEMICOLON);
                break;
            case u8'?':
                add_token(type::QUESTION);
                break;
            case u8',':
                add_token(type::COMMA);
                break;
            case u8'\\':
                add_token(type::BACKSlASH);
                break;
            case u8'~':
                add_token(type::TILDE);
                break;
            case u8'@':
                add_token(type::AT);
                break;
            case u8'$':
                add_token(type::DOLLAR);
                break;
            case u8'+':
                if(consume(u8'+')){
                    add_token(type::PLUS_DOUBLE);
                } else {
                    add_token(type::PLUS);
                }
                break;
            case u8'-':
                if(consume(u8'>')){
                    add_token(type::ARROW_RIGHT);
                } else {
                    add_token(type::MINUS);
                }
                break;
            case u8'<':
                if (consume(u8'-')){
                    add_token(type::ARROW_LEFT);
                } else if (consume(u8'=')){
                    if (consume(u8'>')){
                        add_token(type::LESS_EQUAL_GREATER);
                    } else {
                        add_token(type::LESS_EQUAL);
                    }
                } else if (consume(u8'<')){
                    add_token(Token::type::SHIFT_LEFT);
                } else {
                    add_token(type::LESS);
                }
                break;
            case u8'>':
                if(consume(u8'=')){
                    add_token(type::GREATER_EQUAL);
                } else if (consume(u8'>')){
                    add_token(type::SHIFT_RIGHT);
                } else {
                    add_token(type::GREATER);
                }
            case u8'=':
                if (consume(u8'=')){
                    add_token(type::EQUAL);
                    break;
                } else {
                    return InvalidCharacter{c, line, start};
                }
            case u8'!':
                if (consume(u8'=')){
                    add_token(type::NOT_EQUAL);
                    break;
                } else {
                    return InvalidCharacter{c, line, start};
                }
            case u8'.':
                if (consume(u8'.')){
                    if (consume(u8'.')){
                        add_token(type::PERIOD_TRIPLE);
                    } else {
                        add_token(type::PERIOD_DOUBLE);
                    }
                } else {
                    add_token(type::PERIOD);
                }
            case u8'*':
                if(consume(u8'*')){
                    add_token(type::STAR_DOUBLE);
                } else {
                    add_token(type::STAR);
                }
                break;
            case u8'/':
                if(consume(u8'/')){
                    add_token(type::SLASH_DOUBLE);
                } else {
                    add_token(type::SLASH);
                }
                break;
            case u8'%':;
                if(consume(u8'%')){
                    add_token(type::PERCENT_DOUBLE);
                } else {
                    add_token(type::PERCENT);
                }
                break;
            case u8'^':
                add_token(type::CARET);
                break;
            case u8'&':
                add_token(type::AMPERSAND);
                break;
            case u8'|':
                add_token(type::PIPE);
                break;
            default:
                return InvalidCharacter{c, line, start};
        }
        return Ok{};
    }

    LexerError Lexer::run() {

    }

    bool Lexer::is_digit(char8_t c) {
        return c >= u8'0' && c <= u8'9';
    }

    bool Lexer::is_alpha(char8_t c) {
        return c >= u8'A' && c <= u8'Z' || c >= u8'a' && c <= u8'z';
    }

    bool Lexer::is_alnum(char8_t c) {
        return is_digit(c) || is_alpha(c) || c == u8'_';
    }

    bool Lexer::is_id_start(char8_t c) {
        return is_alpha(c) || c == u8'_';
    }

    bool Lexer::is_id_cont(char8_t c) {
        return is_alnum(c);
    }
}




