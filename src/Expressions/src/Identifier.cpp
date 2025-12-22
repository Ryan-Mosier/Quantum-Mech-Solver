#include "Identifier.hpp"
//
// Created by ryanm on 12/21/2025.
//
#include "Expressions.hpp"

Identifier::Identifier(const std::string& ident) : ident(ident) { type = ExpressionType::Identifier; }

std::unique_ptr<Expression> Identifier::evaluate() { return Environment::getInstance().get(ident)->clone(); }

std::string                 Identifier::getIdentifier() const { return ident; }
std::unique_ptr<Expression> Identifier::clone() const { return std::make_unique<Identifier>(ident); }
