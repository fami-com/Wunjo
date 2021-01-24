//
// Created by V on 2021-01-24.
//

#ifndef WUNJO_PREDICATES_H
#define WUNJO_PREDICATES_H

#include <string>
#include <vector>
#include <optional>

bool is_identifier(std::string &input) noexcept;

std::optional<int> is_integer(std::string &input) noexcept;

std::optional<int> is_based_integer(std::string &input) noexcept;

std::optional<double> is_float(std::string &input) noexcept;

std::optional<double> is_based_float(std::string &input) noexcept;

std::optional<std::string> is_string(std::string &input) noexcept;

std::optional<std::string> is_raw_string(std::string &input) noexcept;

std::optional<std::vector<uint8_t>> is_byte_string(std::string &input) noexcept;

std::optional<std::vector<uint8_t>> is_raw_byte_string(std::string &input) noexcept;

std::optional<int32_t> is_character(std::string &input) noexcept;
#endif //WUNJO_PREDICATES_H
