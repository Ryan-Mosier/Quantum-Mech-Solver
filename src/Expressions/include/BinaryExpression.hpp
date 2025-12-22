//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_BINARYEXPRESSION_HPP
#define EXPRESSION_LIBRARY_BINARYEXPRESSION_HPP

#include "BinaryOpStrategy.hpp"
#include "ExpressionType.hpp"


class BinaryExpression : public Expression {
    std::unique_ptr<Expression>       left;
    std::unique_ptr<Expression>       right;
    std::shared_ptr<BinaryOpStrategy> strategy;

public:
    ~BinaryExpression() override = default;
    BinaryExpression(const std::unique_ptr<Expression>&       left, const std::unique_ptr<Expression>& right,
                     const std::shared_ptr<BinaryOpStrategy>& strategy);
    [[nodiscard]] std::unique_ptr<Expression> evaluate() override;
    [[nodiscard]] std::unique_ptr<Expression> clone() const override;
};


#endif //EXPRESSION_LIBRARY_BINARYEXPRESSION_HPP
