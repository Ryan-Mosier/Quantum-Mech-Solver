//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"

UnaryExpression::UnaryExpression(const std::unique_ptr<Expression>&      expression,
                                 const std::shared_ptr<UnaryOpStrategy>& strategy) : expression(expression->clone()),
    strategy(strategy) {}

std::unique_ptr<Expression> UnaryExpression::evaluate() { return strategy->eval(expression); }

std::unique_ptr<Expression> UnaryExpression::clone() const {
    return std::make_unique<UnaryExpression>(expression, strategy);
    // if the overhead here is large, consider using shared pointers
}
