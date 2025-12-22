//
// Created by ryanm on 12/21/2025.
//

#include "../include/Number.hpp"
Number::Number(double value): value(value) {}
std::unique_ptr<Expression> Number::evaluate() { return clone(); }
std::unique_ptr<Expression> Number::clone() const { return std::make_unique<Number>(value); }
double                      Number::getValue() const {return value;}
