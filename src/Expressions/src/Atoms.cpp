//
// Created by ryanm on 12/21/2025.
//

#include <utility>

#include "Expressions.hpp"

/// Number
Number::Number(const double& value) : value(value) { type = ExpressionType::Number; }
Number::Number(const std::string& value) : value(std::stod(value)) { type = ExpressionType::Number; }
Value                       Number::evaluate() const { return value; }
std::shared_ptr<Expression> Number::clone() const { return std::make_shared<Number>(value); }

/// Identifier
Identifier::Identifier(std::string name) : name(std::move(name)) { type = ExpressionType::Identifier; }
Value                       Identifier::evaluate() const { return *Environment::getInstance().get(name); }
std::shared_ptr<Expression> Identifier::clone() const { return std::make_shared<Identifier>(name); }
const std::string&          Identifier::getName() const { return name; }
