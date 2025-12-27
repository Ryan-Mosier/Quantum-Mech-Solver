//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_UNARYOPSTRATEGY_HPP
#define EXPRESSION_LIBRARY_UNARYOPSTRATEGY_HPP
#include <memory>
#include "ExpressionType.hpp"

class UnaryOpStrategy {
public:
    virtual                           ~UnaryOpStrategy() = default;
    [[nodiscard]] virtual Value       eval(const std::shared_ptr<Expression>& expression) const = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
};

class BinaryOpStrategy {
public:
    virtual                     ~BinaryOpStrategy() = default;
    [[nodiscard]] virtual Value eval(std::shared_ptr<Expression> left,
                                     std::shared_ptr<Expression> right) const = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
};

#endif //EXPRESSION_LIBRARY_UNARYOPSTRATEGY_HPP
