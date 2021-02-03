//
// Created by V on 2021-01-25.
//

#include "Float.h"
#include "Integer.h"
#include "Rational.h"

namespace Types {
    constexpr Float::Float() noexcept : number(0.0) { }

    constexpr Float::Float(const double data) : number(data) { }

    constexpr Float::Float(const Integer& data) : number(data.number) { }

    constexpr Float::Float(const Rational& data) : number((double)data.numerator/data.denominator) { }

    constexpr Float::Float(const Float& data) : number(data.number) { }
}