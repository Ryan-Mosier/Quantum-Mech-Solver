//
// Created by ryanm on 12/21/2025.
//

#include "BinaryStrategyFactory.hpp"

#include <stdexcept>

#include "BinaryOperators.hpp"

auto plus     = Plus();
auto minus    = Minus();
auto multiply = Multiply();
auto divide   = Divide();

inline ExpressionType getExpressionType(TokenType type) {
    switch (type) {
        case TokenType::Plus: return ExpressionType::Plus;
        case TokenType::Minus: return ExpressionType::Minus;
        case TokenType::Star: return ExpressionType::Multiply;
        case TokenType::Slash: return ExpressionType::Divide;
        default: throw std::invalid_argument("invalid token type");
    }
}

std::shared_ptr<BinaryOpStrategy> BinaryStrategyFactory::createStrategy(TokenType type) {
    return createStrategy(getExpressionType(type));
}

std::shared_ptr<BinaryOpStrategy> BinaryStrategyFactory::createStrategy(ExpressionType type) {
    switch (type) {
        default:
            throw std::invalid_argument("invalid expression type");
        case ExpressionType::Plus:
            return std::shared_ptr<BinaryOpStrategy>(&plus);
        case ExpressionType::Minus:
            return std::shared_ptr<BinaryOpStrategy>(&minus);
        case ExpressionType::Multiply:
            return std::shared_ptr<BinaryOpStrategy>(&multiply);
        case ExpressionType::Divide:
            return std::shared_ptr<BinaryOpStrategy>(&divide);
    }
}
