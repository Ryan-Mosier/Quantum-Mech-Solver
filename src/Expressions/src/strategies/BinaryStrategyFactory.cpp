//
// Created by ryanm on 12/21/2025.
//

#include "BinaryStrategyFactory.hpp"

#include <stdexcept>

#include "BinaryOperators.hpp"

// These provide a static location for the strategies, each instance will actually just reference this.
auto plus     = new Plus();
auto minus    = new Minus();
auto multiply = new Multiply();
auto divide   = new Divide();

inline ExpressionType getExpressionType(TokenType type) {
    switch (type) {
        case TokenType::Plus: return ExpressionType::Plus;
        case TokenType::Minus: return ExpressionType::Minus;
        case TokenType::Star: return ExpressionType::Multiply;
        case TokenType::Slash: return ExpressionType::Divide;
        default: throw std::invalid_argument("invalid token type");
    }
}

const BinaryOpStrategy* BinaryStrategyFactory::createStrategy(TokenType type) {
    return createStrategy(getExpressionType(type));
}

const BinaryOpStrategy* BinaryStrategyFactory::createStrategy(ExpressionType type) {
    switch (type) {
        default:
            throw std::invalid_argument("invalid expression type");
        case ExpressionType::Plus:
            return plus;
        case ExpressionType::Minus:
            return minus;
        case ExpressionType::Multiply:
            return multiply;
        case ExpressionType::Divide:
            return divide;
    }
}
