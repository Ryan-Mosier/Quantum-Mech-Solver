//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"
#include <stdexcept>

std::unique_ptr<Expression> ExpressionFactory::createExpression(const Token& token) {
    return nullptr;
}

std::unique_ptr<Expression>
ExpressionFactory::createExpression(const Token& token, Expression* left, Expression* right) {
    return nullptr;
}

std::unique_ptr<Expression> ExpressionFactory::createExpression(const Token& token, Expression* expression) {
    return nullptr;
}

std::unique_ptr<Expression> ExpressionFactory::createExpression(const std::string& type, const std::string& string) {
    return nullptr;
}
