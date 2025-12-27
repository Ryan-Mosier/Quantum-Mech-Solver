//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"
#include "strategies/OperatorStrategyFactory.hpp"

UnaryExpression::UnaryExpression(const std::shared_ptr<Expression>& expression,
                                 const UnaryOpStrategy* strategy, const ExpressionType& type) : Expression(type),
    expression(expression),
    strategy(strategy) {}

Value UnaryExpression::evaluate() const { return strategy->eval(expression); }

std::shared_ptr<Expression> UnaryExpression::clone() const {
    return std::make_shared<UnaryExpression>(expression, strategy, type);
}

std::string UnaryExpression::toString() const {
    return "(" + strategy->toString() + " " + expression->toString() + " )";
}


BinaryExpression::BinaryExpression(const std::shared_ptr<Expression>& left, const std::shared_ptr<Expression>& right,
                                   const BinaryOpStrategy* strategy, const ExpressionType& type) : Expression(type),
    left(left),
    right(right), strategy(strategy) {
    if (left == nullptr || right == nullptr) throw std::invalid_argument("null expression");
}

Value BinaryExpression::evaluate() const { return strategy->eval(left, right); }

std::shared_ptr<Expression> BinaryExpression::clone() const {
    return std::make_shared<BinaryExpression>(left, right, strategy, type);
}

std::string BinaryExpression::toString() const {
    return "(" + strategy->toString() + " " + left->toString() + " " + right->toString() + " )";
}
