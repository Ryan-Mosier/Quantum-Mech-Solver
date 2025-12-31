//
// Created by ryanm on 12/21/2025.
//
module;
#include <variant>
#include <memory>

export module Expression.CompositeExpressions;

export import Expression.Expression;
export import Expression.OpStrategy;

export using leaf = std::variant<Value, std::shared_ptr<Expression>>;

export class UnaryExpression : public Expression {
    std::shared_ptr<Expression> expression;
    const UnaryOpStrategy*      strategy;

public:
    ~UnaryExpression() override = default;

    UnaryExpression(const std::shared_ptr<Expression>& expression, const UnaryOpStrategy* strategy,
                    const ExpressionType&              type);

    [[nodiscard]] Value evaluate() const override;

    [[nodiscard]] std::shared_ptr<Expression> clone() const override;

    [[nodiscard]] std::string toString() const override;
};

export class BinaryExpression : public Expression {
    // may want to consider shared pointers to save on clone overhead if it turns out to be large
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
    const BinaryOpStrategy*     strategy;

public:
    ~BinaryExpression() override = default;

    BinaryExpression(const std::shared_ptr<Expression>& left, const std::shared_ptr<Expression>& right,
                     const BinaryOpStrategy*            strategy, const ExpressionType&          type);

    [[nodiscard]] Value evaluate() const override;

    [[nodiscard]] std::shared_ptr<Expression> clone() const override;

    [[nodiscard]] std::string toString() const override;
};


