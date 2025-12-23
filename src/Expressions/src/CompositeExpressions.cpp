//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"
#include "strategies/BinaryStrategyFactory.hpp"

UnaryExpression::UnaryExpression(const std::unique_ptr<Expression> &expression,
                                 const std::shared_ptr<OpStrategy> &strategy) : expression(expression->clone()),
                                                                                strategy(strategy) {
}

std::unique_ptr<Expression> UnaryExpression::evaluate() { return strategy->eval(expression); }

std::unique_ptr<Expression> UnaryExpression::clone() const {
    return std::make_unique<UnaryExpression>(expression, strategy);
    // if the overhead here is large, consider using shared pointers
}


BinaryExpression::BinaryExpression(const std::unique_ptr<Expression> &left, const std::unique_ptr<Expression> &right,
                                   const BinaryOpStrategy *strategy) : left(left->clone()),
                                                                       right(right->clone()), strategy(strategy) {
    type = BinaryStrategyFactory::getType(strategy);
}

std::unique_ptr<Expression> BinaryExpression::evaluate() { return strategy->eval(left->clone(), right->clone()); }

std::unique_ptr<Expression> BinaryExpression::clone() const {
    return std::make_unique<BinaryExpression>(left, right, strategy);
    // if the overhead here is large, should swap to shared pointers
}
