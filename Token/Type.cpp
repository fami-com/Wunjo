//
// Created by V on 2021-02-02.
//

#include "Type.h"

namespace Token {
    std::optional<Type> decode(const std::string& input) {
        if (input == "in") return Type::IN;
        else if (input == "not") return Type::NOT;
        else if (input == "or") return Type::OR;
        else if (input == "and") return Type::AND;
        else if (input == "is") return Type::IS;
        else if (input == "func") return Type::FUNC;
        else if (input == "Type") return Type::TYPE;
        else if (input == "shape") return Type::SHAPE;
        else if (input == "return") return Type::RETURN;
        else if (input == "if") return Type::IF;
        else if (input == "elif") return Type::ELIF;
        else if (input == "else") return Type::ELSE;
        else if (input == "for") return Type::FOR;
        else if (input == "loop") return Type::LOOP;
        else if (input == "while") return Type::WHILE;
        else if (input == "match") return Type::MATCH;
        else if (input == "true") return Type::TRUE;
        else if (input == "false") return Type::FALSE;
        else if (input == "nil") return Type::NIL;
        else if (input == "with") return Type::WITH;
        else if (input == "break") return Type::BREAK;
        else if (input == "continue") return Type::CONTINUE;
        else if (input == "let") return Type::LET;
        else return std::nullopt;
    }

    std::string encode(Type input) {
        switch (input) {
            // symbol
            case Type::BRACE_OPEN: return "{";
            case Type::BRACE_CLOSE: return "}";
            case Type::BRACKET_OPEN: return "[";
            case Type::BRACKET_CLOSE: return "]";
            case Type::PAREN_OPEN: return "(";
            case Type::PAREN_CLOSE: return ")";
            case Type::SEMICOLON: return ";";
            case Type::COLON: return ":";
            case Type::PERIOD: return ".";
            case Type::PERIOD_DOUBLE: return "..";
            case Type::PERIOD_TRIPLE: return "...";
            case Type::COMMA: return ",";
            case Type::QUESTION: return "?";
            case Type::DOLLAR: return "$";
            case Type::AT: return "@";
            case Type::BACKSlASH: return "\\";
            case Type::ARROW_LEFT: return "<-";
            case Type::ARROW_RIGHT: return "->";
            case Type::ARROW_RIGHT_DOUBLE: return "=>";
            case Type::ASSIGN: return "=";
            case Type::ASSIGN_EXPR: return ":=";
            case Type::EQUAL: return "==";
            case Type::NOT_EQUAL: return "!=";
            case Type::GREATER: return ">";
            case Type::GREATER_EQUAL: return ">=";
            case Type::LESS: return "<";
            case Type::LESS_EQUAL: return "<=";
            case Type::LESS_EQUAL_GREATER: return "<=>";
            case Type::PLUS: return "+";
            case Type::PLUS_DOUBLE: return "++";
            case Type::MINUS: return "-";
            case Type::STAR: return "*";
            case Type::STAR_DOUBLE: return "**";
            case Type::SLASH: return "/";
            case Type::SLASH_DOUBLE: return "//";
            case Type::PERCENT: return "%";
            case Type::PERCENT_DOUBLE: return "%%";
            case Type::CARET: return "^";
            case Type::AMPERSAND: return "&";
            case Type::PIPE: return "|";
            case Type::SHIFT_LEFT: return "<<";
            case Type::SHIFT_RIGHT: return ">>";
            case Type::TILDE: return "~";
            // keywords
            case Type::AND: return "and";
            case Type::OR: return "or";
            case Type::NOT: return "not";
            case Type::IS: return "is";
            case Type::IN: return "in";
            case Type::FUNC: return "func";
            case Type::TYPE: return "type";
            case Type::SHAPE: return "shape";
            case Type::RETURN: return "return";
            case Type::IF: return "if";
            case Type::ELIF: return "elif";
            case Type::ELSE: return "else";
            case Type::FOR: return "for";
            case Type::LOOP: return "loop";
            case Type::WHILE: return "while";
            case Type::MATCH: return "match";
            case Type::WITH: return "with";
            case Type::TRUE: return "true";
            case Type::FALSE: return "false";
            case Type::NIL: return "nil";
            case Type::BREAK: return "break";
            case Type::CONTINUE: return "continue";
            case Type::LET: return "let";
            // special data
            case Type::IDENTIFIER: return "identifier";
            case Type::INTEGER: return "integer";
            case Type::FLOAT: return "float";
            case Type::STRING: return "string";
            default: return "INVALID";
        }
    }
}