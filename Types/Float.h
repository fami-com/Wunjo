//
// Created by V on 2021-01-25.
//

#ifndef WUNJO_FLOAT_H
#define WUNJO_FLOAT_H

#include <type_traits>

#include "Common.h"

namespace Types {
    class Float {
        const double number;

        friend class Integer;
        friend class Rational;
        friend class Complex;
    public:
        constexpr Float() noexcept;
        constexpr Float(double data);

        constexpr Float(const Integer& data);
        constexpr Float(const Rational& data);

        constexpr Float(const Float& data);


        [[nodiscard]] bool is_zero() const noexcept {
            return number == 0.0;
        }
    };
}

#endif //WUNJO_FLOAT_H
