//
// This file is licensed under MPL 2.0, GNU GPL v2.0+ and GNU LGPL v2.1+
// For more information about the licensing, see the LICENSE file in the project root
// Copyright (c) 2021 - 2021 fami-com
//

#ifndef WUNJO_INTEGER_H
#define WUNJO_INTEGER_H

#include "Common.h"

namespace Types {
    class Integer {
        const int64_t number;

        friend Rational;
        friend Float;
        friend Complex;
    public:

        constexpr Integer() noexcept;
        constexpr Integer(int64_t data) noexcept;

        constexpr Integer(const Integer& data) noexcept;

        Integer operator+() const noexcept;
        Integer operator-() const noexcept;
        Integer operator~() const noexcept;

        Integer operator&(const Integer& rhs) const noexcept;
        Integer operator|(const Integer& rhs) const noexcept;
        Integer operator^(const Integer& rhs) const noexcept;
        Integer operator<<(const Integer& rhs) const noexcept;
        Integer operator>>(const Integer& rhs) const noexcept;

        Integer operator+(const Integer& rhs) const noexcept;
        Integer operator-(const Integer& rhs) const noexcept;
        Integer operator*(const Integer& rhs) const noexcept;
        Integer operator%(const Integer& rhs) const;
        Rational operator/(const Integer& rhs) const;

        Rational operator+(const Rational& rhs) const noexcept;
        Rational operator-(const Rational& rhs) const noexcept;
        Rational operator*(const Rational& rhs) const noexcept;
        Rational operator%(const Rational& rhs) const;
        Rational operator/(const Rational& rhs) const;

        Float operator+(const Float& rhs) const noexcept;
        Float operator-(const Float& rhs) const noexcept;
        Float operator*(const Float& rhs) const noexcept;
        Float operator%(const Float& rhs) const;
        Float operator/(const Float& rhs) const;

        Complex operator+(const Complex& rhs) const noexcept;
        Complex operator-(const Complex& rhs) const noexcept;
        Complex operator*(const Complex& rhs) const noexcept;
        Complex operator%(const Complex& rhs) const;
        Complex operator/(const Complex& rhs) const;

        std::strong_ordering operator<=>(const Integer& rhs) const noexcept;

        [[nodiscard]] Integer div(const Integer& rhs) const noexcept;
        [[nodiscard]] Integer mod(const Integer& rhs) const noexcept;
        [[nodiscard]] std::variant<Integer,Rational> pow(const Integer& rhs) const;

        [[nodiscard]] Integer div(const Rational& rhs) const noexcept;
        [[nodiscard]] Rational mod(const Rational& rhs) const noexcept;
        [[nodiscard]] Float pow(const Rational& rhs) const;

        [[nodiscard]] Integer div(const Float& rhs) const noexcept;
        [[nodiscard]] Float mod(const Float& rhs) const noexcept;
        [[nodiscard]] Float pow(const Float& rhs) const;

        //[[nodiscard]] Integer div(Complex rhs) const noexcept;
        //[[nodiscard]] Float mod(Complex rhs) const noexcept;
        [[nodiscard]] Complex pow(const Complex& rhs) const;

        [[nodiscard]] Integer floor() const noexcept;
        [[nodiscard]] Integer ceil() const noexcept;
        [[nodiscard]] Integer round() const noexcept;

        [[nodiscard]] bool is_zero() const noexcept {
            return number == 0;
        }
    };
}
#endif //WUNJO_INTEGER_H
