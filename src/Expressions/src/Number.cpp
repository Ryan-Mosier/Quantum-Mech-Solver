//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"
#include <stdexcept>

Number::Number(const std::string& value) { this->value = std::stod(value); }
Number::Number(const double value) : value(value) {}

std::unique_ptr<Expression> Number::evaluate() { return std::make_unique<Number>(*this); }

std::unique_ptr<Expression> Number::clone() const { return std::make_unique<Number>(value); }
