//
// Created by ryanm on 12/21/2025.
//

module;
#include <string>
#include <memory>

module Expression.Atoms;

/// Number
Number::Number(const double& value) : Expression(ExpressionType::Number), value(value) {}
Number::Number(const std::string& value) : Expression(ExpressionType::Number), value(std::stod(value)) {}
Value                       Number::evaluate() const { return value; }
std::shared_ptr<Expression> Number::clone() const { return std::make_shared<Number>(value); }

std::string Number::toString() const {
    std::string s = std::to_string(value);
    s.erase(s.find_last_not_of('0') + 1, std::string::npos);
    if (s.back() == '.') s.pop_back();
    return s;
}

/// Identifier
Identifier::Identifier(std::string name) : Expression(ExpressionType::Identifier), name(std::move(name)) {}
Value                       Identifier::evaluate() const { return *Environment::getInstance().get(name); }
std::shared_ptr<Expression> Identifier::clone() const { return std::make_shared<Identifier>(name); }
std::string                 Identifier::toString() const { return name; }
const std::string&          Identifier::getName() const { return name; }