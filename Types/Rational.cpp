//
// This file is licensed under MPL 2.0, GNU GPL v2.0+ and GNU LGPL v2.1+
// For more information about the licensing, see the LICENSE file in the project root
// Copyright (c) 2021 - 2021 fami-com
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