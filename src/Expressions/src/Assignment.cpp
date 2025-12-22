//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"

Assignment::Assignment(const std::unique_ptr<Expression>& identifier, const std::unique_ptr<Expression>& expression) :
    identifier(identifier->clone()), expression(expression->clone()) { type = ExpressionType::Assignment; }

std::unique_ptr<Expression> Assignment::clone() const { return std::make_unique<Assignment>(identifier, expression); }

std::unique_ptr<Expression> Assignment::evaluate() {
    auto evaled = expression->evaluate();
    const auto id    = dynamic_cast<Identifier*>(identifier.get());
    Environment::getInstance().set(id->getIdentifier(), evaled->clone());
    return evaled; //may want to return nothing here, stay tuned to find out
}
