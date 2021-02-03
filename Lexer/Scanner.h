//
// Created by V on 2021-01-22.
//

#ifndef WUNJO_SCANNER_H
#define WUNJO_SCANNER_H

#include <string>
#include <vector>
#include <variant>
#include <optional>

#include "Token.h"
#include "ScannerError.h"

namespace Lexer {
    using type = Token::Type;
    /**
     * The class that represents a lexer
     */
    class Scanner {
        using Number = std::variant<int64_t, double>; //!< A useful alias for the variant
        const std::string code; //!< The string that holds the source code

        int start; //!< Position where the Token starts
        int pos; //!< Current position in the string
        int column; //!< Current column in the line
        int line; //!< Current line
        std::optional<ScannerError> error; //!< The error that may happen when lexing

        /**
         * A function to check if the scanner has reached the end of the input.
         * @return True if the scanner has reached the end
         */
        [[nodiscard]] bool end() const noexcept;

        /**
         * The function that contains the main logic for scanning. Sets the error field.
         * @return True if no error has occurred, false otherwise
         */
        bool scan_once() noexcept;

        /**
         * Advanced the position in the code by one.
         * @return The character at the current position
         */
        char next() noexcept;

        /**
         * Advances the input only if the current character matches the supplied one.
         * @param expect The character to match against the current one
         * @return True if the input was advanced
         */
        bool consume(char expect) noexcept;

        /**
         * Returns the character at the current position without advancing the input.
         * @return The character at the current position
         */
        char peek() noexcept;

        /**
         * Matches the current character against the supplied one without advancing the input
         * @param expect The character to match against the current one
         * @return True if the current character matches the supplied one
         */
        bool match(char expect) noexcept;

        /**
         * Matches the current character against a predicate without advancing the input.
         * @param predicate The predicate to match the current one against
         * @return True if the current character matches the predicate
         */
        bool match(bool predicate(char c)) noexcept;

        /**
         * Adds the token without data. The data of the token will be std::monostate.
         * @param type The type of the token to add
         */
        void add_token(type type) noexcept;

        /**
         * Adds the token with data.
         * @param type The type of the token to add
         * @param data The data of the token to add
         */
        void add_token(type type, const Token::TokenData& data) noexcept;

        /**
         * Sets the error of the lexer.
         * @param err The error
         */
        void set_error(ScannerError err) noexcept;

        /**
         * Matches a valid number in the current input. Sets the error if the input is incorrect.
         * @param c The already matched character
         * @return std::nullopt if the input was invalid, Number otherwise
         */
        std::optional<Number> match_number(char c) noexcept;

        /**
         * Matches a valid string in the current input. Sets the error if the input is incorrect.
         * @return std::nullopt if the input was invalid, std::string otherwise
         */
        std::optional<std::string> match_string() noexcept;

        /**
         * Matches a valid string in the current input. Doesn't set errors.
         * @param c The already matched character
         * @return The type of the token if it's a reserved keyword, a string with the matched identifier otherwise.
         */
        std::variant<type,std::string> match_identifier(char c) noexcept;

        /**
         * Tests if the character is an ASCII digit. Not unicode-aware.
         * @param c The character to test
         * @return True if the character is an ASCII digit
         */
        static inline bool is_digit(char c) noexcept;

        /**
         * Tests if the character is an ASCII uppercase letter. Not unicode-aware.
         * @param c The character to test
         * @return True if the character is an ASCII uppercase letter
         */
        static inline bool is_upper(char c) noexcept;

        /**
         * Tests if the character is an ASCII lowercase letter. Not unicode-aware.
         * @param c The character to test
         * @return True if the character is an ASCII lowercase letter
         */
        static inline bool is_lower(char c) noexcept;

        /**
         * Tests if the character is an ASCII letter. Not unicode-aware.
         * @param c The character to test
         * @return True if the character is an ASCII letter
         */
        static inline bool is_alpha(char c) noexcept;

        /**
         * Tests if the character is an ASCII letter or an ASCII digit. Not unicode-aware.
         * @param c The character to test
         * @return True if the character is an ASCII letter or an ASCII digit
         */
        static inline bool is_alnum(char c) noexcept;

        /**
         * Tests if the character can begin an identifier (ASCII A-Z, a-z and _). Not unicode-aware.
         * @param c The character to test
         * @return Tests if the character is can begin an identifier
         */
        static inline bool is_id_start(char c) noexcept;

        /**
         * Tests if the character can continue an identifier (ASCII 0-9, A-Z, a-z and _). Not unicode-aware.
         * @param c The character to test
         * @return Tests if the character is can continue an identifier
         */
        static inline bool is_id_cont(char c) noexcept;

        /**
         * Return the numeric value of an ASCII character in a base-36 case-insensitive manner where '0' = 0 and 'Z' or
         * 'z' = 36.
         * @param c The character to convert
         * @return The numeric value of the character
         */
        static inline int numeric_value(char c) noexcept;

    public:
        /**
         * Gets the error that occurred during scanning.
         * @return The error.
         */
        [[nodiscard]] std::optional<ScannerError> get_error() const noexcept;

        /**
         * The constructor for the scanner.
         * @param input The input to be tokenized
         */
        explicit Scanner(std::string& input) noexcept;

        /**
         * Starts the main loop of the scanner.
         */
        void run() noexcept;

        std::vector<Token::Token> tokens; //!< The lexed tokens
    };
}
#endif //WUNJO_SCANNER_H
