//
// Created by ryanm on 12/21/2025.
//

#include <utility>

#include "Expressions.hpp"

/// Number
Number::Number(const double& value) : Expression(ExpressionType::Number), value(value) {}
Number::Number(const std::string& value) : Expression(ExpressionType::Number), value(std::stod(value)) {}
Value                       Number::evaluate() const { return value; }
std::shared_ptr<Expression> Number::clone() const { return std::make_shared<Number>(value); }

/// Identifier
Identifier::Identifier(std::string name) : Expression(ExpressionType::Identifier), name(std::move(name)) {}
Value                       Identifier::evaluate() const { return *Environment::getInstance().get(name); }
std::shared_ptr<Expression> Identifier::clone() const { return std::make_shared<Identifier>(name); }
const std::string&          Identifier::getName() const { return name; }
