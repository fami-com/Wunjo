//
// Created by V on 2021-01-25.
//
#include <stdexcept>
#include "Rational.h"
#include "Integer.h"

namespace Types {
    constexpr Rational::Rational() noexcept : numerator(0), denominator(1) {

    }

    constexpr Rational::Rational(int64_t num, int64_t denom) : numerator(num), denominator(denom) {
        if(denom == 0){
            throw std::invalid_argument{"Division by zero"};
        }
        simplify();
    }

    constexpr Rational::Rational(const Integer& data) noexcept : numerator(data.number), denominator(1) {

    }

    constexpr Rational::Rational(const Rational& data) noexcept : numerator(data.numerator), denominator(data.denominator) {

    }

    void Rational::simplify() {
        // TODO: implement
    }
}