//
// Created by V on 2021-01-22.
//

#ifndef WUNJO_TOKEN_H
#define WUNJO_TOKEN_H
#include <any>
#include <string>
#include <variant>
#include "type.h"
namespace Token {
    struct token {
        bool operator==(type rhs) const noexcept;

        bool operator!=(type rhs) const noexcept;

        explicit token(type type) noexcept;

        token(type type, std::any data) noexcept;

        template <typename T>
        T get_data() const;

    private:
        const std::any data;
        const type type;
    };
}
#endif //WUNJO_TOKEN_H
