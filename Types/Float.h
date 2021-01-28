//
// Created by V on 2021-01-25.
//

#ifndef WUNJO_FLOAT_H
#define WUNJO_FLOAT_H

#include <type_traits>

#include "Number.h"

class Float : public Number {
    double number;

    friend Integer;
    friend Rational;
    friend Complex;
public:
    constexpr Float() noexcept;

    template <typename T>
    constexpr Float(T data)
        requires(std::is_floating_point_v<T> &&
                std::numeric_limits<T>::max <= std::numeric_limits<double>::max &&
                std::numeric_limits<T>::min >= std::numeric_limits<double>::min);

    constexpr Float(const Integer& data);
    constexpr Float(const Rational& data);

    constexpr Float(const Float& data);

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
        return number == 0.0;
    }
};


#endif //WUNJO_FLOAT_H
