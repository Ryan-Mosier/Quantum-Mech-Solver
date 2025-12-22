//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"
#include <stdexcept>

std::unique_ptr<Expression> ExpressionFactory::createExpression(const Token& token) {}

std::unique_ptr<Expression>
ExpressionFactory::createExpression(const Token& token, Expression* left, Expression* right) {}

std::unique_ptr<Expression> ExpressionFactory::createExpression(const Token& token, Expression* expression) {}

std::unique_ptr<Expression> ExpressionFactory::createExpression(const std::string& type, const std::string& string) {
    if (type == "number") { return std::make_unique<Number>(string); }
    if (type == "identifier") { return std::make_unique<Identifier>(string); }
    throw std::invalid_argument("Invalid expression type: " + type);
}
