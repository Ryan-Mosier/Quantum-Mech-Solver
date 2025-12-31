//
// Created by ryanm on 12/21/2025.
//
module;
#include <memory>

export module Expression.OpStrategy;

import Expression.Expression;

export class UnaryOpStrategy {
public:
    virtual                           ~UnaryOpStrategy() = default;
    [[nodiscard]] virtual Value       eval(const std::shared_ptr<Expression>& expression) const = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
};

export class BinaryOpStrategy {
public:
    virtual                     ~BinaryOpStrategy() = default;
    [[nodiscard]] virtual Value eval(std::shared_ptr<Expression> left,
                                     std::shared_ptr<Expression> right) const = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
};

