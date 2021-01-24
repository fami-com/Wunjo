//
// Created by V on 2021-01-22.
//

#include <stdexcept>

#include "Token.h"
#include "TokenType.h"
#include "predicates.h"

bool Token::operator==(TokenType &rhs) const noexcept {
    return this->_type == rhs;
}

bool Token::operator!=(TokenType &rhs) const noexcept {
    return this->_type != rhs;
}

Token::Token(std::string &input, int column, int row) {
    _column = column;
    _row = row;
    _data = 0;

    if (input == "(") _type = TokenType::PAREN_OPEN;
    else if (input == ")")_type = TokenType::PAREN_CLOSE;
    else if (input == "[")_type = TokenType::BRACKET_OPEN;
    else if (input == "]")_type = TokenType::BRACKET_CLOSE;
    else if (input == "{")_type = TokenType::BRACE_OPEN;
    else if (input == "}")_type = TokenType::BRACE_CLOSE;
    else if (input == ".")_type = TokenType::PERIOD;
    else if (input == "..")_type = TokenType::PERIOD_DOUBLE;
    else if (input == "...")_type = TokenType::PERIOD_TRIPLE;
    else if (input == ",")_type = TokenType::COMMA;
    else if (input == ";")_type = TokenType::SEMICOLON;
    else if (input == ":")_type = TokenType::COLON;
    else if (input == "\\")_type = TokenType::BACKSlASH;
    else if (input == "?")_type = TokenType::QUESTION;
    else if (input == "<-")_type = TokenType::ARROW_LEFT;
    else if (input == "->")_type = TokenType::ARROW_RIGHT;
    else if (input == "=>")_type = TokenType::ARROW_DOUBLE_RIGHT;
    else if (input == "==")_type = TokenType::EQUAL;
    else if (input == "!=")_type = TokenType::NOT_EQUAL;
    else if (input == "<")_type = TokenType::LESS;
    else if (input == "<=")_type = TokenType::LESS_EQUAL;
    else if (input == ">")_type = TokenType::GREATER;
    else if (input == ">=")_type = TokenType::GREATER_EQUAL;
    else if (input == "<=>")_type = TokenType::LESS_EQUAL_GREATER;
    else if (input == "+")_type = TokenType::PLUS;
    else if (input == "++")_type = TokenType::PLUS_DOUBLE;
    else if (input == "-")_type = TokenType::MINUS;
    else if (input == "--")_type = TokenType::MINUS_DOUBLE;
    else if (input == "*")_type = TokenType::STAR;
    else if (input == "**")_type = TokenType::STAR_DOUBLE;
    else if (input == "/")_type = TokenType::SLASH;
    else if (input == "//")_type = TokenType::SLASH_DOUBLE;
    else if (input == "%")_type = TokenType::PERCENT;
    else if (input == "%%")_type = TokenType::PERCENT_DOUBLE;
    else if (input == "^")_type = TokenType::CARET;
    else if (input == "&")_type = TokenType::AMPERSAND;
    else if (input == "|")_type = TokenType::PIPE;
    else if (input == "~")_type = TokenType::TILDE;
    else if (input == "<<")_type = TokenType::SHIFT_LEFT;
    else if (input == ">>")_type = TokenType::SHIFT_RIGHT;
    else if (input == "=")_type = TokenType::ASSIGN;
    else if (input == "+=")_type = TokenType::ASSIGN_PLUS;
    else if (input == "++=")_type = TokenType::ASSIGN_PLUS_DOUBLE;
    else if (input == "-=")_type = TokenType::ASSIGN_MINUS;
    else if (input == "--=")_type = TokenType::ASSIGN_MINUS_DOUBLE;
    else if (input == "*=")_type = TokenType::ASSIGN_STAR;
    else if (input == "**=")_type = TokenType::ASSIGN_STAR_DOUBLE;
    else if (input == "/=")_type = TokenType::ASSIGN_SLASH;
    else if (input == "//=")_type = TokenType::ASSIGN_SLASH_DOUBLE;
    else if (input == "%=")_type = TokenType::ASSIGN_PERCENT;
    else if (input == "%%=")_type = TokenType::ASSIGN_PERCENT_DOUBLE;
    else if (input == "@=")_type = TokenType::ASSIGN_AT;
    else if (input == "@@=")_type = TokenType::ASSIGN_AT_DOUBLE;
    else if (input == "^=")_type = TokenType::ASSIGN_CARET;
    else if (input == "&=")_type = TokenType::ASSIGN_AMPERSAND;
    else if (input == "|=")_type = TokenType::ASSIGN_PIPE;
    else if (input == "<<=")_type = TokenType::ASSIGN_SHIFT_LEFT;
    else if (input == ">>=")_type = TokenType::ASSIGN_SHIFT_RIGHT;
    else if (input == "and")_type = TokenType::AND;
    else if (input == "or")_type = TokenType::OR;
    else if (input == "not")_type = TokenType::NOT;
    else if (input == "is")_type = TokenType::IS;
    else if (input == "isnt")_type = TokenType::ISNT;
    else if (input == "are")_type = TokenType::ARE;
    else if (input == "arent")_type = TokenType::ARENT;
    else if (input == "has")_type = TokenType::HAS;
    else if (input == "hasnt")_type = TokenType::HASNT;
    else if (input == "have")_type = TokenType::HAVE;
    else if (input == "havent")_type = TokenType::HAVENT;
    else if (input == "func")_type = TokenType::FUNC;
    else if (input == "type")_type = TokenType::TYPE;
    else if (input == "if")_type = TokenType::IF;
    else if (input == "elif")_type = TokenType::ELIF;
    else if (input == "else")_type = TokenType::ELSE;
    else if (input == "end")_type = TokenType::END;
    else if (input == "unless")_type = TokenType::UNLESS;
    else if (input == "for")_type = TokenType::FOR;
    else if (input == "while")_type = TokenType::WHILE;
    else if (input == "loop")_type = TokenType::LOOP;
    else if (input == "in")_type = TokenType::IN;
    else if (input == "until")_type = TokenType::UNTIL;
    else if (input == "match")_type = TokenType::MATCH;
    else if (input == "true")_type = TokenType::TRUE;
    else if (input == "false")_type = TokenType::FALSE;
    else if (input == "nil")_type = TokenType::NIL;
    else if (input == "with")_type = TokenType::WITH;
    else if (input == "try")_type = TokenType::TRY;
    else if (input == "catch")_type = TokenType::CATCH;
    else if (input == "break")_type = TokenType::BREAK;
    else if (input == "continue")_type = TokenType::CONTINUE;
    else if (input == "let")_type = TokenType::LET;
    else if(is_identifier(input)){
        _type=TokenType::IDENTIFIER;
        _data = input;
    } else if(auto v = is_float(input)){
        _type = TokenType::FLOAT;
        _data = v.value();
    } else if(auto v = is_based_float(input)){
        _type = TokenType::FLOAT;
        _data = v.value();
    } else if(auto v = is_integer(input)){
        _type = TokenType::INTEGER;
        _data = v.value();
    } else if(auto v = is_based_integer(input)){
        _type = TokenType::INTEGER;
        _data = v.value();
    } else if(auto v = is_string(input)){
        _type = TokenType::STRING;
        _data = v.value();
    } else if(auto v = is_raw_string(input)){
        _type = TokenType::STRING;
        _data = v.value();
    } else if(auto v = is_byte_string(input)){
        _type = TokenType::BYTESTRING;
        _data = v.value();
    } else if(auto v = is_raw_byte_string(input)){
        _type = TokenType::BYTESTRING;
        _data = v.value();
    } else if(auto v = is_character(input)){
        _type = TokenType::CHARACTER;
        _data = v.value();
    } else {
        throw std::invalid_argument("Invalid token: " + input);
    }
}
