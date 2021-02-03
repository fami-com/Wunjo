//
// Created by V on 2021-01-22.
//

#ifndef WUNJO_TOKEN_H
#define WUNJO_TOKEN_H
#include <any>
#include <variant>
#include <iosfwd>
#include <tuple>

#include "Type.h"
namespace Token {
    using TokenData = std::variant<std::monostate,int64_t,double,std::string>;
    /**
     * The struct that describes the Token and its related data
     */
    struct Token {
        /**
         * An implementation of the operator == to ease the identification of tokens
         * @param rhs The Type to match against
         * @return True if the Type of the Token matches the supplied Type, false otherwise
         * @see operator!=()
         */
        bool operator==(enum Type rhs) const noexcept;

        /**
         * An implementation of the operator != to ease the identification of tokens
         * @param rhs The Type to match against
         * @return False if the Type of the Token matches the supplied Type, true otherwise
         * @see operator==()
         */
        bool operator!=(enum Type rhs) const noexcept;

        /**
         * An overload for the operator << that allows to print the Token
         * @param os The stream to which the Token should be printed
         * @param data The Token to print
         * @return The reference to the stream to which the Token was printed
         */
        friend std::ostream& operator<<(std::ostream& os, const Token& token);

        /**
         * The constructor for a Token that doesn't hold any data
         * @param type The Type of the Token to be created
         */
        explicit Token(enum Type type, int line, int column) noexcept;

        /**
         * The constructor for a Token that holds some data
         * @param type The Type of the Token to be created
         * @param data The data held by the Token
         */
        Token(enum Type type, std::variant<std::monostate,int64_t,double,std::string> data, int line, int column) noexcept;

        /**
         * A helper method to get the data held by the Token in a Type-safe manner
         * @tparam T The Type of the data held by the Token determined by the Type of the Token
         * @return The data held by the Token if the Type is valid
         */
        template <typename T> T get_data() const;

        /**
         * A getter for the position of the Token in the source code
         * @return A tuple with the line as the first value and the column as the second value
         */
        [[nodiscard]] std::tuple<int, int> position() const noexcept;

    private:
        const TokenData data; //<! The data held by the Token
        const enum Type type; //<! The Type of the Token
        const int line; //<! The line in the source code
        const int column; //<! The column in the source code
    };
}
#endif //WUNJO_TOKEN_H
