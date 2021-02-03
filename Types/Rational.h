//
// This file is licensed under MPL 2.0, GNU GPL v2.0+ and GNU LGPL v2.1+
// For more information about the licensing, see the LICENSE file in the project root
// Copyright (c) 2021 - 2021 fami-com
//

#ifndef WUNJO_RATIONAL_H
#define WUNJO_RATIONAL_H

#include "Common.h"

namespace Types {
    class Rational {
        const int64_t numerator;
        const int64_t denominator;

        friend class Integer;
        friend class Float;
        friend class Complex;

    public:
        constexpr Rational() noexcept;
        constexpr Rational(int64_t num, int64_t denom);

        constexpr Rational(const Integer& data) noexcept;

        constexpr Rational(const Rational& data) noexcept;

        void simplify();
    };
}

#endif //WUNJO_RATIONAL_H
