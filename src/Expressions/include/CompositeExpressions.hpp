//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_UNARYEXPRESSION_HPP
#define EXPRESSION_LIBRARY_UNARYEXPRESSION_HPP

#include "OpStrategy.hpp"
#include "ExpressionType.hpp"


class UnaryExpression : public Expression {
    std::unique_ptr<Expression> expression;
    std::shared_ptr<OpStrategy> strategy;

public:
    ~UnaryExpression() override = default;

    UnaryExpression(const std::unique_ptr<Expression> &expression, const std::shared_ptr<OpStrategy> &strategy);

    [[nodiscard]] std::unique_ptr<Expression> evaluate() override;

    [[nodiscard]] std::unique_ptr<Expression> clone() const override;
};

class BinaryExpression : public Expression {
    // may want to consider shared pointers to save on clone overhead if it turns out to be large
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
    const BinaryOpStrategy *strategy;

public:
    ~BinaryExpression() override = default;

    BinaryExpression(const std::unique_ptr<Expression> &left, const std::unique_ptr<Expression> &right,
                     const BinaryOpStrategy *strategy);

    [[nodiscard]] std::unique_ptr<Expression> evaluate() override;

    [[nodiscard]] std::unique_ptr<Expression> clone() const override;
};


#endif //EXPRESSION_LIBRARY_UNARYEXPRESSION_HPP
