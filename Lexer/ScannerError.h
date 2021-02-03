//
// Created by V on 2021-01-28.
//

#ifndef WUNJO_SCANNERERROR_H
#define WUNJO_SCANNERERROR_H

#include <tuple>
#include <variant>
#include <iosfwd>

namespace Lexer {

    /**
     * The base class for all scanner errors. Should never be constructed directly.
     */
    struct Error {
        /**
         * Gets the location in which the error has occurred.
         * @return The tuple with the line in the first position and the column in the second position
         */
        [[nodiscard]] std::tuple<int, int> get_location() const;

    protected:
        /**
         * The constructor for the error.
         * @param line The line on which the error has occurred
         * @param column The column on which the error has occurred
         */
        Error(int line, int column);

        int line; //!< The line of the error
        int column; //!< The column of the error
    };

    /**
     * The error that gets created when an invalid character is encountered
     */
    struct InvalidCharacter : public Error {
        char c; //!< The invalid character

        /**
         * The constructor for the struct
         * @param line The line on which the error has occurred
         * @param column The column on which the error has occurred
         * @param c The character
         */
        InvalidCharacter(int line, int column, char c);

        /**
         * An operator to enable printing the error to streams
         * @param os The stream to which the error will be printed
         * @param e The error to be printed
         * @return The stream to which the error was printed
         */
        friend std::ostream& operator<<(std::ostream& os, const InvalidCharacter& e);
    };

    struct UnterminatedString : public Error {
        /**
         * The constructor for the struct
         * @param line The line on which the error has occurred
         * @param column The column on which the error has occurred
         */
        UnterminatedString(int line, int column);

        /**
         * An operator to enable printing the error to streams
         * @param os The stream to which the error will be printed
         * @param e The error to be printed
         * @return The stream to which the error was printed
         */
        friend std::ostream& operator<<(std::ostream& os, const UnterminatedString& e);
    };

    struct InvalidBase : public Error {
        int base; //!< The base value that caused the error

        /**
         * The constructor for the base
         * @param line The line on which the error has occurred
         * @param column The line on which the error has occurred
         * @param base The base value
         */
        InvalidBase(int line, int column, int base);

        /**
         * An operator to enable printing the error to streams
         * @param os The stream to which the error will be printed
         * @param e The error to be printed
         * @return The stream to which the error was printed
         */
        friend std::ostream& operator<<(std::ostream& os, const InvalidBase& e);
    };

    struct InvalidNumericLiteral : public Error {
        char c; //!< The character that was invalid for the base
        int base; //!< The base of the integer literal

        /**
         *
         * @param line The line on which the error has occurred
         * @param column The line on which the error has occurred
         * @param c The character that caused the error
         * @param base The base of the literal
         */
        InvalidNumericLiteral(int line, int column, char c, int base);

        /**
         * An operator to enable printing the error to streams
         * @param os The stream to which the error will be printed
         * @param e The error to be printed
         * @return The stream to which the error was printed
         */
        friend std::ostream& operator<<(std::ostream& os, const InvalidNumericLiteral& e);
    };

    /**
     * A convenience declaration to make adding new errors easier
     */
    using ScannerError = std::variant<InvalidCharacter,UnterminatedString,InvalidBase,InvalidNumericLiteral>;
}
#endif //WUNJO_SCANNERERROR_H
