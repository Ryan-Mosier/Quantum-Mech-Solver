//
// Created by ryanm on 12/21/2025.
//

#include "BinaryStrategyFactory.hpp"

#include <stdexcept>

#include "BinaryOperators.hpp"

// These provide a static location for the strategies, each instance will actually just reference this.
static auto plus     = new Plus();
static auto minus    = new Minus();
static auto multiply = new Multiply();
static auto divide   = new Divide();
static auto assign   = new Assign();

inline ExpressionType getExpressionType(TokenType type) {
    switch (type) {
        case TokenType::Plus: return ExpressionType::Plus;
        case TokenType::Minus: return ExpressionType::Minus;
        case TokenType::Star: return ExpressionType::Multiply;
        case TokenType::Slash: return ExpressionType::Divide;
        case TokenType::Assignment: return ExpressionType::Assignment;
        default: throw std::invalid_argument("invalid token type" + std::to_string(static_cast<int>(type)));
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
        case ExpressionType::Assignment:
            return assign;
    }
}

ExpressionType BinaryStrategyFactory::getType(const BinaryOpStrategy* strategy) {
    if (strategy == plus) return ExpressionType::Plus;
    if (strategy == minus) return ExpressionType::Minus;
    if (strategy == multiply) return ExpressionType::Multiply;
    if (strategy == divide) return ExpressionType::Divide;
    throw std::invalid_argument("invalid strategy");
}
