//
// Created by V on 2021-01-25.
//

#ifndef WUNJO_NUMBER_H
#define WUNJO_NUMBER_H

#include <compare>
#include <memory>

using std::unique_ptr;
using std::make_unique;

class Integer;
class Rational;
class Float;
class Complex;

class Number {
public:
    virtual unique_ptr<Number> operator+() const noexcept = 0;
    virtual unique_ptr<Number> operator-() const noexcept = 0;
    virtual unique_ptr<Number> operator~() const noexcept = 0;

    virtual unique_ptr<Number> operator+(unique_ptr<Number> rhs) const noexcept = 0;
    virtual unique_ptr<Number> operator-(unique_ptr<Number> rhs) const noexcept = 0;
    virtual unique_ptr<Number> operator*(unique_ptr<Number> rhs) const noexcept = 0;
    virtual unique_ptr<Number> operator/(unique_ptr<Number> rhs) const = 0;
    virtual unique_ptr<Number> operator%(unique_ptr<Number> rhs) const = 0;
    /*
    virtual const Number& operator&(const Number& rhs) const noexcept = 0;
    virtual const Number& operator|(const Number& rhs) const noexcept = 0;
    virtual const Number& operator^(const Number& rhs) const noexcept = 0;
    */

    virtual std::strong_ordering operator<=>(unique_ptr<Number> rhs) const noexcept = 0;

    [[nodiscard]] virtual unique_ptr<Number> div(unique_ptr<Number> rhs) const noexcept = 0;
    [[nodiscard]] virtual unique_ptr<Number> mod(unique_ptr<Number> rhs) const noexcept = 0;
    [[nodiscard]] virtual unique_ptr<Number> pow(unique_ptr<Number> rhs) const noexcept = 0;

    [[nodiscard]] virtual bool is_zero() const noexcept = 0;

    [[nodiscard]] virtual unique_ptr<Number> floor() const noexcept = 0;
    [[nodiscard]] virtual unique_ptr<Number> ceil() const noexcept = 0;
    [[nodiscard]] virtual unique_ptr<Number> round() const noexcept = 0;
};


#endif //WUNJO_NUMBER_H
