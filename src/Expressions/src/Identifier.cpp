//
// Created by ryanm on 12/21/2025.
//

#include "../include/Identifier.hpp"

#include "../include/Environment.hpp"
Identifier::Identifier(const std::string& name) : name(name) { type = ExpressionType::Identifier; }
std::unique_ptr<Expression> Identifier::evaluate() { return Environment::getInstance().get(name)->clone(); }
std::unique_ptr<Expression> Identifier::clone() const { return std::make_unique<Identifier>(name); }
const std::string&          Identifier::getName() const { return name; }
