//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"
#include "strategies/BinaryStrategyFactory.hpp"

UnaryExpression::UnaryExpression(const std::shared_ptr<Expression>& expression,
                                 const OpStrategy*                  strategy) : expression(expression),
    strategy(strategy) {}

Value UnaryExpression::evaluate() const { return strategy->eval(expression); }

std::shared_ptr<Expression> UnaryExpression::clone() const {
    return std::make_shared<UnaryExpression>(expression, strategy);
}


BinaryExpression::BinaryExpression(const std::shared_ptr<Expression>& left, const std::shared_ptr<Expression>& right,
                                   const BinaryOpStrategy*            strategy) : left(left),
    right(right), strategy(strategy) {
    type = BinaryStrategyFactory::getType(strategy);
}

Value BinaryExpression::evaluate() const { return strategy->eval(left, right); }

std::shared_ptr<Expression> BinaryExpression::clone() const {
    return std::make_shared<BinaryExpression>(left, right, strategy);
}
