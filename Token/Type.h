//
// This file is licensed under MPL 2.0, GNU GPL v2.0+ and GNU LGPL v2.1+
// For more information about the licensing, see the LICENSE file in the project root
// Copyright (c) 2021 - 2021 fami-com
//

#ifndef WUNJO_TYPE_H
#define WUNJO_TYPE_H

#include <optional>
#include <map>
#include <string>

namespace Token {
    /**
     * The enum that hold all possible types of a Token
     */
    enum class Type {
        // Brackets
        PAREN_OPEN, //!< (
        PAREN_CLOSE, //!< )
        BRACE_OPEN, //!< {
        BRACE_CLOSE, //!< }
        BRACKET_OPEN, //!< [
        BRACKET_CLOSE, //!< ]

        // Punctuation
        SEMICOLON, //!< ;
        COLON, //!< :
        PERIOD, //!< .
        PERIOD_DOUBLE, //!< ..
        PERIOD_TRIPLE, //!< ...
        COMMA, //!< ,
        QUESTION, //!< ?
        AT, //!< @
        DOLLAR, //!< $
        BACKSlASH, //!< \

        // Arrows
        ARROW_LEFT, //!< <-
        ARROW_RIGHT, //!< ->
        ARROW_RIGHT_DOUBLE, //!< =>

        // ASSIGNMENT
        ASSIGN, //!< =
        ASSIGN_EXPR, //!< :=

        // Comparison
        EQUAL, //!< ==
        NOT_EQUAL, //!< !=
        GREATER, //!< >
        LESS, //!< <
        GREATER_EQUAL, //!< >=
        LESS_EQUAL, //!< <=
        LESS_EQUAL_GREATER, //!< <=>

        // Operators
        PLUS, //!< +
        PLUS_DOUBLE, //!< ++
        MINUS, //!< -
        STAR, //!< *
        STAR_DOUBLE, //!< **
        SLASH, //!< /
        SLASH_DOUBLE, //!< //
        PERCENT, //!< %
        PERCENT_DOUBLE, //!< %%
        CARET, //!< ^
        AMPERSAND, //!< &
        AND, //!< and
        PIPE, //!< |
        OR, //!< or
        SHIFT_LEFT, //!< <<
        SHIFT_RIGHT, //!< >>
        TILDE, //!< ~
        NOT, //!< not
        IS, //!< is
        IN, //!< in

        // Special values
        IDENTIFIER,
        INTEGER,
        FLOAT,
        STRING,
        //BYTESTRING,
        //SYMBOL,
        //IMAGINARY,

        // Keywords
        FUNC, //!< func
        TYPE, //!< Type
        SHAPE, //!< shape
        RETURN, //!< return
        IF, //!< if
        ELIF, //!< elif
        ELSE, //!< else
        FOR, //!< for
        LOOP, //!< loop
        WHILE, //!< while
        MATCH, //!< match
        TRUE, //!< true
        FALSE, //!< false
        NIL, //!< nil
        WITH, //!< with
        BREAK, //!< break
        CONTINUE, //!< continue
        LET, //!< let
    };

    std::optional<Type> decode(const std::string& input);
    std::string encode(Type input);

}
#endif //WUNJO_TYPE_H
