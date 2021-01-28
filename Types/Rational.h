//
// Created by V on 2021-01-25.
//

#ifndef WUNJO_RATIONAL_H
#define WUNJO_RATIONAL_H

#include <cstdint>
#include <compare>

#include "Number.h"

class Rational : public Number {
    int64_t numerator;
    int64_t denominator;

    friend Integer;
    friend Float;
    friend Complex;

public:
    constexpr Rational() noexcept;

    template <typename TNum, typename TDenom> constexpr Rational(TNum num, TDenom denom)
        requires(std::is_integral_v<TNum> && std::is_integral_v<TDenom> &&
                std::numeric_limits<TNum>::max <= std::numeric_limits<int64_t>::max &&
                std::numeric_limits<TNum>::min >= std::numeric_limits<int64_t>::min &&
                std::numeric_limits<TDenom>::max <= std::numeric_limits<int64_t>::max &&
                std::numeric_limits<TDenom>::min >= std::numeric_limits<int64_t>::min);

    constexpr Rational(const Integer& data) noexcept;

    constexpr Rational(const Rational& data) noexcept;

    unique_ptr<Number> operator+() const noexcept override;
    unique_ptr<Number> operator-() const noexcept override;
    unique_ptr<Number> operator~() const noexcept override;

    unique_ptr<Number> operator+(unique_ptr<Number> rhs) const noexcept override;
    unique_ptr<Number> operator-(unique_ptr<Number> rhs) const noexcept override;
    unique_ptr<Number> operator*(unique_ptr<Number> rhs) const noexcept override;
    unique_ptr<Number> operator/(unique_ptr<Number> rhs) const override;
    unique_ptr<Number> operator%(unique_ptr<Number> rhs) const override;

    std::strong_ordering operator<=>(unique_ptr<Number> rhs) const noexcept override;

    [[nodiscard]] unique_ptr<Number> div(unique_ptr<Number> rhs) const noexcept override;
    [[nodiscard]] unique_ptr<Number> mod(unique_ptr<Number> rhs) const noexcept override;
    [[nodiscard]] unique_ptr<Number> pow(unique_ptr<Number> rhs) const noexcept override;

    [[nodiscard]] unique_ptr<Number> floor() const noexcept override;
    [[nodiscard]] unique_ptr<Number> ceil() const noexcept override;
    [[nodiscard]] unique_ptr<Number> round() const noexcept override;

    [[nodiscard]] virtual bool is_zero() const noexcept {
        return numerator == 0;
    }
};


#endif //WUNJO_RATIONAL_H
