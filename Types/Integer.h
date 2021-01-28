//
// Created by V on 2021-01-25.
//

#ifndef WUNJO_INTEGER_H
#define WUNJO_INTEGER_H

#include <cstdint>

#include "Number.h"

class Integer : public Number {
    int64_t number;

    friend Rational;
    friend Float;
    friend Complex;
public:
    [[nodiscard]] constexpr int64_t get_number() const noexcept {
        return number;
    }

    constexpr Integer() noexcept;

    template <class T>
    constexpr Integer(T data) noexcept
        requires(std::is_integral_v<T> &&
                 std::numeric_limits<T>::max <= std::numeric_limits<int64_t>::max &&
                 std::numeric_limits<T>::min >= std::numeric_limits<int64_t>::min);

    constexpr Integer(const Integer& data) noexcept;

    unique_ptr<Number> operator+() const noexcept override;
    unique_ptr<Number> operator-() const noexcept override;
    unique_ptr<Number> operator~() const noexcept override;

    unique_ptr<Integer> operator&(unique_ptr<Integer> rhs) const noexcept;
    unique_ptr<Integer> operator|(unique_ptr<Integer> rhs) const noexcept;
    unique_ptr<Integer> operator^(unique_ptr<Integer> rhs) const noexcept;
    unique_ptr<Integer> operator<<(unique_ptr<Integer> rhs) const noexcept;
    unique_ptr<Integer> operator>>(unique_ptr<Integer> rhs) const noexcept;

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
        return number == 0;
    }
};

#endif //WUNJO_INTEGER_H
