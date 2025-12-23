//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_UNARYOPSTRATEGY_HPP
#define EXPRESSION_LIBRARY_UNARYOPSTRATEGY_HPP
#include <memory>
#include "ExpressionType.hpp"

class OpStrategy {
public:
    virtual                             ~OpStrategy() = default;
    virtual std::unique_ptr<Expression> eval(const std::unique_ptr<Expression>& expression) = 0;
};

class BinaryOpStrategy {
public:
    virtual                                           ~BinaryOpStrategy() = default;
    [[nodiscard]] virtual std::unique_ptr<Expression> eval(std::unique_ptr<Expression> left,
                                                           std::unique_ptr<Expression> right) const = 0;
};

#endif //EXPRESSION_LIBRARY_UNARYOPSTRATEGY_HPP
