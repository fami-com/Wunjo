//
// Created by V on 2021-01-25.
//

#ifndef WUNJO_COMPLEX_H
#define WUNJO_COMPLEX_H

#include "Number.h"

class Complex : public Number {
    double real;
    double imag;

    friend Integer;
    friend Rational;
    friend Float;
public:
    constexpr Complex() noexcept;

    template <typename TReal, typename TImag>
    constexpr Complex(TReal num, TImag denom)
    requires(std::is_floating_point_v<TReal> && std::is_floating_point_v<TImag> &&
            std::numeric_limits<TReal>::max <= std::numeric_limits<double>::max &&
            std::numeric_limits<TReal>::min >= std::numeric_limits<double>::min &&
            std::numeric_limits<TImag>::max <= std::numeric_limits<int64_t>::max &&
            std::numeric_limits<TImag>::min >= std::numeric_limits<int64_t>::min);

    constexpr Complex(Integer& data) noexcept;
    constexpr Complex(Rational& data) noexcept;
    constexpr Complex(Float& data) noexcept;

    constexpr Complex(Complex& data) noexcept;

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

    [[nodiscard]] bool is_zero() const noexcept override {
        return real == 0.0 && imag == 0.0;
    }
};


#endif //WUNJO_COMPLEX_H
