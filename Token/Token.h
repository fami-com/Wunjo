//
// Created by V on 2021-01-22.
//

#ifndef WUNJO_TOKEN_H
#define WUNJO_TOKEN_H
#include <any>
#include <string>
#include "TokenType.h"

struct Token {
private:
    std::any _data;
    TokenType _type;
    int _column;
    int _row;

public:
    bool operator==(TokenType& rhs) const noexcept;
    bool operator!=(TokenType& rhs) const noexcept;

    [[nodiscard]] int column() const noexcept{
        return _column;
    }

    [[nodiscard]] int row() const noexcept{
        return _row;
    }

    [[nodiscard]] TokenType type() const noexcept{
        return _type;
    }

    template<typename T>
    [[nodiscard]] T data() const{
        return std::any_cast<T>(_data);
    }

    Token(std::string& input, int column, int row);
};


#endif //WUNJO_TOKEN_H
