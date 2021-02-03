//
// This file is licensed under MPL 2.0, GNU GPL v2.0+ and GNU LGPL v2.1+
// For more information about the licensing, see the LICENSE file in the project root
// Copyright (c) 2021 - 2021 fami-com
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