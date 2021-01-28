//
// Created by V on 2021-01-22.
//

#ifndef WUNJO_TYPE_H
#define WUNJO_TYPE_H
namespace Token {
    enum class type {
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

        // ASSIGNMENT
        ARROW_LEFT, // <-
        ARROW_RIGHT, // ->
        AT, // @
        DOLLAR, // $
        ASSIGN_EXPR, // :=

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
        STAR, // *
        STAR_DOUBLE, // **
        SLASH, // /
        SLASH_DOUBLE, // //
        PERCENT, // %
        PERCENT_DOUBLE, // %%
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

        // Special values
        IDENTIFIER,
        INTEGER,
        FLOAT,
        STRING,
        BYTESTRING,
        //CHARACTER,
        //IMAGINARY,

        // Keywords
        FUNC, // func
        CLASS, // class
        SHAPE, // shape
        IF, // if
        THEN, // then
        UNLESS, // unless
        ELIF, // elif
        ELSE, // else
        END, // end
        FOR, // for
        IN, // in
        DO, // do
        LOOP, // loop
        WHILE, // while
        UNTIL, // until
        CASE, // match
        OF, // of
        ON, // on
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
}
#endif //WUNJO_TYPE_H
