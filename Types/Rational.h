//
// Created by V on 2021-01-25.
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
