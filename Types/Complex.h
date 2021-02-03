//
// This file is licensed under MPL 2.0, GNU GPL v2.0+ and GNU LGPL v2.1+
// For more information about the licensing, see the LICENSE file in the project root
// Copyright (c) 2021 - 2021 fami-com
//

#ifndef WUNJO_COMPLEX_H
#define WUNJO_COMPLEX_H

#include "Common.h"
#include "Float.h"
#include "Rational.h"


namespace Types {
    class Complex {
        const double real;
        const double imag;

        friend class Integer;
        friend class Rational;
        friend class Float;
    public:
        constexpr Complex() noexcept;
        constexpr Complex(double real, double imag) noexcept;

        constexpr Complex(const Integer& data) noexcept;
        constexpr Complex(const Rational& data) noexcept;
        constexpr Complex(const Float& data) noexcept;

        constexpr Complex(const Complex& data) noexcept;

        [[nodiscard]] bool is_zero() const noexcept {
            return real == 0.0 && imag == 0.0;
        }
    };
}

#endif //WUNJO_COMPLEX_H
