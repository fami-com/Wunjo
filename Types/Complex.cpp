//
// This file is licensed under MPL 2.0, GNU GPL v2.0+ and GNU LGPL v2.1+
// For more information about the licensing, see the LICENSE file in the project root
// Copyright (c) 2021 - 2021 fami-com
//

#include "Complex.h"
#include "Integer.h"
#include "Rational.h"
#include "Float.h"

namespace Types {

    constexpr Complex::Complex() noexcept : real(0.0), imag(0.0) { }
    constexpr Complex::Complex(double real, double imag) noexcept : real(real), imag(imag) { }

    constexpr Complex::Complex(const Integer& data) noexcept : real(data.number), imag(0.0) { }

    constexpr Complex::Complex(const Rational& data) noexcept : real((double)data.numerator/data.denominator), imag(0.0) { }

    constexpr Complex::Complex(const Float& data) noexcept : real(data.number), imag(0.0) { }

    constexpr Complex::Complex(const Complex& data) noexcept : real(data.real), imag(data.imag) { }
}