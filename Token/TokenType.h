//
// Created by V on 2021-01-22.
//

#ifndef WUNJO_TOKENTYPE_H
#define WUNJO_TOKENTYPE_H

enum class TokenType {
    // Brackets
    PAREN_OPEN, // (
    PAREN_CLOSE, // )
    BRACE_OPEN, // {
    BRACE_CLOSE, // }
    BRACKET_OPEN, // [
    BRACKET_CLOSE, // ]

    // Punctuation
    SEMICOLON, // ;
    COLON, // :
    PERIOD, // .
    PERIOD_DOUBLE, // ..
    PERIOD_TRIPLE, // ...
    COMMA, // ,
    QUESTION, // ?
    BACKSlASH, // \

    // Arrows
    ARROW_LEFT, // <-
    ARROW_RIGHT, // ->
    ARROW_DOUBLE_RIGHT, // =>

    // Comparison
    EQUAL, // ==
    NOT_EQUAL, // !=
    GREATER, // >
    LESS, // <
    GREATER_EQUAL, // >=
    LESS_EQUAL, // <=
    LESS_EQUAL_GREATER, // <=>

    // Operators
    PLUS, // +
    PLUS_DOUBLE, // ++
    MINUS, // -
    MINUS_DOUBLE, // --
    STAR, // *
    STAR_DOUBLE, // **
    SLASH, // /
    SLASH_DOUBLE, // //
    PERCENT, // %
    PERCENT_DOUBLE, // %%
    AT, // @
    AT_DOUBLE, // @@
    CARET, // ^
    AMPERSAND, // &
    AND, // and
    PIPE, // |
    OR, // or
    SHIFT_LEFT, // <<
    SHIFT_RIGHT, // >>
    TILDE, // ~
    NOT, // not
    IS, // is
    ISNT, // isnt
    ARE, // are
    ARENT, // arent
    HAS, // has
    HASNT, // hasnt
    HAVE, // have
    HAVENT, // havent

    // Assignment
    ASSIGN, // =
    ASSIGN_PLUS, // +=
    ASSIGN_PLUS_DOUBLE, // ++=
    ASSIGN_MINUS, // -=
    ASSIGN_MINUS_DOUBLE, // --=
    ASSIGN_STAR, // *=
    ASSIGN_STAR_DOUBLE, // **=
    ASSIGN_SLASH, // /=
    ASSIGN_SLASH_DOUBLE, // //=
    ASSIGN_PERCENT, // %=
    ASSIGN_PERCENT_DOUBLE, // %%=
    ASSIGN_AT, // @=
    ASSIGN_AT_DOUBLE, // @@=
    ASSIGN_CARET, // ^=
    ASSIGN_PIPE, // |=
    ASSIGN_AMPERSAND, // &=
    ASSIGN_SHIFT_LEFT, // <<=
    ASSIGN_SHIFT_RIGHT, // >>=

    // Special values
    IDENTIFIER,
    INTEGER,
    FLOAT,
    STRING,
    BYTESTRING,
    CHARACTER,

    // Keywords
    FUNC, // func
    TYPE, // type
    IF, // if
    UNLESS, // unless
    ELIF, // elif
    ELSE, // else
    END, // end
    FOR, // for
    IN, // in
    LOOP, // loop
    WHILE, // while
    UNTIL, // until
    MATCH, // match
    TRUE, // true
    FALSE, // false
    NIL, // nil
    WITH, // with
    TRY, // try
    CATCH, // on
    BREAK, // break
    CONTINUE, // continue
    LET, // let
};

#endif //WUNJO_TOKENTYPE_H
