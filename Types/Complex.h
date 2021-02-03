//
// Created by V on 2021-01-25.
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
