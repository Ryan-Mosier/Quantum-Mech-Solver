//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_BINARYOPSTRATEGY_HPP
#define EXPRESSION_LIBRARY_BINARYOPSTRATEGY_HPP
#include "ExpressionType.hpp"

class BinaryOpStrategy {
public:
    virtual                                           ~BinaryOpStrategy() = default;
    [[nodiscard]] virtual std::unique_ptr<Expression> eval(std::unique_ptr<Expression> left,
                                                           std::unique_ptr<Expression> right) const = 0;
};


#endif //EXPRESSION_LIBRARY_BINARYOPSTRATEGY_HPP
