//
// Created by V on 2021-01-25.
//

#include <stdexcept>
#include <variant>

#include "Integer.h"
#include "Rational.h"
#include "Float.h"
#include "Complex.h"

namespace Types {
    constexpr Integer::Integer() noexcept : number(0) {}

    constexpr Integer::Integer(const Integer& data) noexcept : number(data.number) {}

    constexpr Integer::Integer(const int64_t data) noexcept : number(static_cast<int64_t>(data)) {}


    Integer Integer::operator+() const noexcept {
        return number;
    }

    Integer Integer::operator-() const noexcept {
        return -number;
    }

    Integer Integer::operator~() const noexcept {
        return ~number;
    }


    Integer Integer::operator+(const Integer& rhs) const noexcept {
        return number + rhs.number;

    }

    Integer Integer::operator-(const Integer& rhs) const noexcept {
        return number - rhs.number;

    }

    Integer Integer::operator*(const Integer& rhs) const noexcept {
        return number * rhs.number;

    }

    Rational Integer::operator/(const Integer& rhs) const {
        if (rhs.is_zero()) throw std::invalid_argument{"Division by zero"};
        return Rational{number, rhs.number};
    }

    Integer Integer::operator%(const Integer& rhs) const {
        if (rhs.is_zero()) throw std::invalid_argument{"Division by zero"};
        return number % rhs.number;
    }


    Rational Integer::operator+(const Rational& rhs) const noexcept {
        return Rational{number * rhs.denominator + rhs.numerator, rhs.denominator};
    }

    Rational Integer::operator-(const Rational& rhs) const noexcept {
        return Rational{number * rhs.denominator - rhs.numerator, rhs.denominator};
    }

    Rational Integer::operator*(const Rational& rhs) const noexcept {
        return Rational{number * rhs.numerator, rhs.denominator};
    }

    Rational Integer::operator/(const Rational& rhs) const {
        return Rational{number * rhs.numerator, rhs.denominator};
    }

    Rational Integer::operator%(const Rational& rhs) const {
        return Rational();
    }


    Float Integer::operator+(const Float& rhs) const noexcept {
        return Float();
    }

    Float Integer::operator-(const Float& rhs) const noexcept {
        return Float();
    }

    Float Integer::operator*(const Float& rhs) const noexcept {
        return Float();
    }

    Float Integer::operator%(const Float& rhs) const {
        return Float();
    }

    Float Integer::operator/(const Float& rhs) const {
        return Float();
    }


    Complex Integer::operator+(const Complex& rhs) const noexcept {
        return Complex();
    }

    Complex Integer::operator-(const Complex& rhs) const noexcept {
        return Complex();
    }

    Complex Integer::operator*(const Complex& rhs) const noexcept {
        return Complex();
    }

    Complex Integer::operator%(const Complex& rhs) const {
        return Complex();
    }

    Complex Integer::operator/(const Complex& rhs) const {
        return Complex();
    }


    Integer Integer::operator&(const Integer& rhs) const noexcept {
        return number & rhs.number;
    }

    Integer Integer::operator|(const Integer& rhs) const noexcept {
        return number | rhs.number;
    }

    Integer Integer::operator^(const Integer& rhs) const noexcept {
        return number ^ rhs.number;
    }

    Integer Integer::operator<<(const Integer& rhs) const noexcept {
        return number << rhs.number;
    }

    Integer Integer::operator>>(const Integer& rhs) const noexcept {
        return number >> rhs.number;
    }


    std::strong_ordering Integer::operator<=>(const Integer& rhs) const noexcept {
        return number <=> rhs.number;
    }


    Integer Integer::floor() const noexcept {
        return number;
    }

    Integer Integer::ceil() const noexcept {
        return number;
    }

    Integer Integer::round() const noexcept {
        return number;
    }


    Integer Integer::div(const Integer& rhs) const noexcept {
        return number / rhs.number;
    }

    Integer Integer::mod(const Integer& rhs) const noexcept {
        auto k = number % rhs.number;
        if (k < 0) k = rhs.number - k;
        return k;
    }

    std::variant<Integer,Rational> Integer::pow(const Integer& rhs) const {
        int64_t result = 1;
        auto is_negative = rhs.number < 0;
        auto exp = number;
        auto base = rhs.number;
        for (;;)
        {
            if (exp & 1)
                result *= base;
            exp >>= 1;
            if (!exp)
                break;
            base *= base;
        }

        if (is_negative)
            return Rational{1L, result};
        else
            return Integer{result};
    }
}
