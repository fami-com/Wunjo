//
// Created by V on 2021-01-25.
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