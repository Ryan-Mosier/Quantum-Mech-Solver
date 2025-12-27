//
// Created by ryanm on 12/21/2025.
//

#include "OperatorStrategyFactory.hpp"

#include <stdexcept>

#include "BinaryOperators.hpp"
#include "UnaryOperators.hpp"

// These provide a static location for the strategies, each instance will actually just reference this.
//Unary
static auto neg = new Neg();
//Binary
static auto plus     = new Plus();
static auto minus    = new Minus();
static auto multiply = new Multiply();
static auto divide   = new Divide();
static auto assign   = new Assign();


const UnaryOpStrategy* UnaryStrategyFactory::createStrategy(TokenType type) {
    return createStrategy(mapToUnaryExpression(type));
}

const UnaryOpStrategy* UnaryStrategyFactory::createStrategy(ExpressionType type) {
    switch (type) {
        default:
            throw std::invalid_argument("invalid token type");
        case ExpressionType::Neg:
            return neg;
    }
}

ExpressionType UnaryStrategyFactory::getType(const UnaryOpStrategy* strategy) {
    if (strategy == neg) return ExpressionType::Neg;
    throw std::invalid_argument("invalid strategy");
}

const BinaryOpStrategy* BinaryStrategyFactory::createStrategy(TokenType type) {
    return createStrategy(mapToBinaryExpression(type));
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
