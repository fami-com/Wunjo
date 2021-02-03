//
// Created by V on 2021-01-22.
//

#include "Token.h"
#include <iostream>
#include <utility>
namespace Token {
    bool Token::operator==(const enum Type rhs) const noexcept {
        return type == rhs;
    }

    bool Token::operator!=(const enum Type rhs) const noexcept {
        return type != rhs;
    }

    Token::Token(const enum Type type, int line, int column) noexcept :
            type(type), data(std::monostate()), line(line), column(column) {}

    Token::Token(const enum Type type, TokenData data, int line, int column) noexcept :
            type(type), data(std::move(data)), line(line), column(column) {}

    template <typename T> T Token::get_data() const {
        return std::any_cast<T>(data);
    }

    std::tuple<int, int> Token::position() const noexcept {
        return std::make_tuple(line, column);
    }

    std::ostream& operator<<(std::ostream& os, const Token& token) {
        auto idx = token.data.index();
        if(idx == 0) {
            os << "Token(" << encode(token.type) << ", [line: " << token.line << ", column: "
               << token.column << "]";
        } else if (idx == 1){
            auto data = std::get<int64_t>(token.data);
            os << "Token(" << encode(token.type) << ", " << data << ", [line: " << token.line << ", column: "
               << token.column << "]";
        }else if (idx == 2){
            auto data = std::get<double>(token.data);
            os << "Token(" << encode(token.type) << ", " << data << ", [line: " << token.line << ", column: "
               << token.column << "]";
        }else if (idx == 3) {
            auto data = std::get<std::string>(token.data);
            os << "Token(" << encode(token.type) << ", " << data << ", [line: " << token.line << ", column: "
               << token.column << "]";
        } else {
            os << "invalid token index: " << idx;
        }
        return os;
    }
}
