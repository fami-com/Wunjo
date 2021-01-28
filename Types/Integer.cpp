//
// Created by V on 2021-01-25.
//

#include <stdexcept>
#include <limits>

#include "Integer.h"
#include "Rational.h"
#include "Float.h"
#include "Complex.h"

constexpr Integer::Integer() noexcept : number(0) { }

constexpr Integer::Integer(const Integer &data) noexcept : number(data.number) {}

template <class T>
constexpr Integer::Integer(const T data) noexcept
    requires(std::is_integral_v<T> &&
        std::numeric_limits<T>::max <= std::numeric_limits<int64_t>::max &&
        std::numeric_limits<T>::min >= std::numeric_limits<int64_t>::min)
    : number(static_cast<int64_t>(data)) {

}

unique_ptr<Number> Integer::operator+() const noexcept {
    return make_unique<Integer>(*this);
}

unique_ptr<Number> Integer::operator-() const noexcept {
    return make_unique<Integer>(-number);
}

unique_ptr<Number> Integer::operator~() const noexcept {
    return make_unique<Integer>(-number);
}

unique_ptr<Number> Integer::operator+(unique_ptr<Number> rhs) const noexcept {
    auto raw = rhs.get();
    if(auto v = dynamic_cast<Integer*>(raw)){
        return make_unique<Integer>(number + v->number);
    } else if (auto v = dynamic_cast<Rational*>(raw)){
        return make_unique<Rational>(number * v->denominator + v->numerator, v->denominator);
    } else if (auto v = dynamic_cast<Float*>(raw)){
        throw std::invalid_argument{"Can't operate on Float yet"};
    } else if (auto v = dynamic_cast<Complex*>(raw)){
        throw std::invalid_argument{"Can't operate on Complex yet"};
    }
}

unique_ptr<Number> Integer::operator-(unique_ptr<Number> rhs) const noexcept {
    auto raw = rhs.get();
    if(auto v = dynamic_cast<Integer*>(raw)){
        return make_unique<Integer>(number - v->number);
    } else if (auto v = dynamic_cast<Rational*>(raw)){
        return make_unique<Rational>(number * v->denominator - v->numerator, v->denominator);
    } else if (auto v = dynamic_cast<Float*>(raw)){
        throw std::invalid_argument{"Can't operate on Float yet"};
    } else if (auto v = dynamic_cast<Complex*>(raw)){
        throw std::invalid_argument{"Can't operate on Complex yet"};
    }
}

unique_ptr<Number> Integer::operator*(unique_ptr<Number> rhs) const noexcept {
    auto raw = rhs.get();
    if(auto v = dynamic_cast<Integer*>(raw)){
        return make_unique<Integer>(number * v->number);
    } else if (auto v = dynamic_cast<Rational*>(raw)){
        return make_unique<Rational>(number * v->numerator, v->denominator);
    } else if (auto v = dynamic_cast<Float*>(raw)){
        throw std::invalid_argument{"Can't operate on Float yet"};
    } else if (auto v = dynamic_cast<Complex*>(raw)){
        throw std::invalid_argument{"Can't operate on Complex yet"};
    }
}

unique_ptr<Number> Integer::operator/(unique_ptr<Number> rhs) const {
    if(rhs->is_zero()) throw std::invalid_argument{"Division by zero"};

    auto raw = rhs.get();
    if(auto v = dynamic_cast<Integer*>(raw)){
        return make_unique<Rational>(number, v->number);
    } else if (auto v = dynamic_cast<Rational*>(raw)){
        return make_unique<Rational>(number * v->denominator, v->numerator);
    } else if (auto v = dynamic_cast<Float*>(raw)){
        throw std::invalid_argument{"Can't operate on Float yet"};
    } else if (auto v = dynamic_cast<Complex*>(raw)){
        throw std::invalid_argument{"Can't operate on Complex yet"};
    }
}

unique_ptr<Number> Integer::operator%(unique_ptr<Number> rhs) const {
    // TODO: make actually work
    throw std::exception{};
    if(rhs->is_zero()) throw std::invalid_argument{"Division by zero"};

    auto raw = rhs.get();
    if(auto v = dynamic_cast<Integer*>(raw)){
        return make_unique<Integer>(number % v->number);
    } else if (auto v = dynamic_cast<Rational*>(raw)){
        return make_unique<Rational>(number * v->denominator, v->numerator);
    } else if (auto v = dynamic_cast<Float*>(raw)){
        throw std::invalid_argument{"Can't operate on Float yet"};
    } else if (auto v = dynamic_cast<Complex*>(raw)){
        throw std::invalid_argument{"Can't operate on Complex yet"};
    }
}

unique_ptr<Integer> Integer::operator&(unique_ptr<Integer> rhs) const noexcept {
    return std::make_unique<Integer>(number & rhs->number);
}

unique_ptr<Integer> Integer::operator|(unique_ptr<Integer> rhs) const noexcept {
    return std::make_unique<Integer>(number | rhs->number);
}

unique_ptr<Integer> Integer::operator^(unique_ptr<Integer> rhs) const noexcept {
    return std::make_unique<Integer>(number ^ rhs->number);
}

unique_ptr<Integer> Integer::operator<<(unique_ptr<Integer> rhs) const noexcept {
    return std::make_unique<Integer>(number << rhs->number);
}

unique_ptr<Integer> Integer::operator>>(unique_ptr<Integer> rhs) const noexcept {
    return std::make_unique<Integer>(number >> rhs->number);
}

std::strong_ordering Integer::operator<=>(unique_ptr<Number> rhs) const noexcept {
    auto raw = rhs.get();
    if(auto v = dynamic_cast<Integer*>(raw)){
        return number <=> v->number;
    } else if (auto v = dynamic_cast<Rational*>(raw)){
        throw std::invalid_argument{"Can't operate on Rational yet"};
    } else if (auto v = dynamic_cast<Float*>(raw)){
        throw std::invalid_argument{"Can't operate on Float yet"};
    } else if (auto v = dynamic_cast<Complex*>(raw)){
        throw std::invalid_argument{"Can't operate on Complex yet"};
    }
}

unique_ptr<Number> Integer::div(unique_ptr<Number> rhs) const noexcept {
    return unique_ptr<Number>();
}

unique_ptr<Number> Integer::mod(unique_ptr<Number> rhs) const noexcept {
    return unique_ptr<Number>();
}

unique_ptr<Number> Integer::pow(unique_ptr<Number> rhs) const noexcept {
    return unique_ptr<Number>();
}

unique_ptr<Number> Integer::floor() const noexcept {
    return std::make_unique<Integer>(number);
}

unique_ptr<Number> Integer::ceil() const noexcept {
    return std::make_unique<Integer>(number);
}

unique_ptr<Number> Integer::round() const noexcept {
    return std::make_unique<Integer>(number);
}

/*
constexpr Integer Integer::operator+() const noexcept {
    return Integer(*this);
}

constexpr Integer Integer::operator-() const noexcept {
    return -number;
}

constexpr Integer Integer::operator~() const noexcept {
    return ~number;
}

constexpr Integer Integer::operator<<(const Integer &rhs) const noexcept {
    return number << rhs.number;
}

constexpr Integer Integer::operator>>(const Integer &rhs) const noexcept {
    return number >> rhs.number;
}

constexpr Integer Integer::operator+(const Integer &rhs) const noexcept {
    return number + rhs.number;
}

constexpr Integer Integer::operator-(const Integer &rhs) const noexcept {
    return number - rhs.number;
}

constexpr Integer Integer::operator*(const Integer &rhs) const noexcept {
    return number * rhs.number;
}

constexpr Number Integer::operator/(const Integer &rhs) const {
    if (number % rhs.number == 0) return Integer{number / rhs.number};
    else return Rational{number, rhs.number};
}

constexpr Integer Integer::operator%(const Integer &rhs) const {
    if (rhs.number == 0)
        throw std::domain_error{"Division by zero"};
    return number % rhs.number;
}

constexpr Integer Integer::operator&(const Integer &rhs) const noexcept {
    return number & rhs.number;
}

constexpr Integer Integer::operator|(const Integer &rhs) const noexcept {
    return number | rhs.number;
}

constexpr Integer Integer::operator^(const Integer &rhs) const noexcept {
    return number ^ rhs.number;
}

constexpr int64_t Integer::operator<=>(const Integer &rhs) const noexcept {
    return number - rhs.number;
}

constexpr Integer Integer::div(const Integer &rhs) const noexcept {
    return number / rhs.number;
}

constexpr Integer Integer::mod(const Integer &rhs) const noexcept {
    int64_t t = number % rhs.number;
    if (t < 0) t = rhs.number + t;
    return t;
}

constexpr Number Integer::pow(const Integer &rhs) const noexcept {
    int64_t result{1};
    int64_t times = rhs.number;
    bool flip{};
    if(times < 0){
        times = -times;
        flip = true;
    }
    for(int i = 0; i < times; i++) result *= number;
    if(flip) return Rational{1L,result};
    return Integer{result};
}
*/
