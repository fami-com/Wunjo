//
// Created by V on 2021-01-22.
//

#include "token.h"

#include <utility>
namespace Token {
    bool token::operator==(const type rhs) const noexcept {
        return type == rhs;
    }

    bool token::operator!=(const type rhs) const noexcept {
        return type != rhs;
    }

    token::token(const type type) noexcept : type(type), data(std::monostate()) {}

    token::token(const type type, std::any data) noexcept : type(type), data(std::move(data)) {}

    template <typename T>
    T token::get_data() const {
        return std::any_cast<T>(data);
    }
}
