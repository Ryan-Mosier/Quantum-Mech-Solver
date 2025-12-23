//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"

/// Number
Number::Number(double value) : value(value) { type = ExpressionType::Number; }
Number::Number(const std::string& value) : value(std::stod(value)) { type = ExpressionType::Number; }
std::unique_ptr<Expression> Number::evaluate() { return clone(); }
std::unique_ptr<Expression> Number::clone() const { return std::make_unique<Number>(value); }
double                      Number::getValue() const { return value; }

/// Identifier
Identifier::Identifier(const std::string& name) : name(name) { type = ExpressionType::Identifier; }
std::unique_ptr<Expression> Identifier::evaluate() { return Environment::getInstance().get(name)->clone(); }
std::unique_ptr<Expression> Identifier::clone() const { return std::make_unique<Identifier>(name); }
const std::string&          Identifier::getName() const { return name; }
