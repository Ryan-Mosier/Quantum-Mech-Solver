//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_UNARYEXPRESSION_HPP
#define EXPRESSION_LIBRARY_UNARYEXPRESSION_HPP

#include "UnaryOpStrategy.hpp"
#include "ExpressionType.hpp"


class UnaryExpression : public Expression {
    std::unique_ptr<Expression>      expression;
    std::shared_ptr<UnaryOpStrategy> strategy;

public:
    ~UnaryExpression() override = default;
    UnaryExpression(const std::unique_ptr<Expression>& expression, const std::shared_ptr<UnaryOpStrategy>& strategy);
    [[nodiscard]] std::unique_ptr<Expression> evaluate() override;
    [[nodiscard]] std::unique_ptr<Expression> clone() const override;
};


#endif //EXPRESSION_LIBRARY_UNARYEXPRESSION_HPP
