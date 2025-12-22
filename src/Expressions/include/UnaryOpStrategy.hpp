//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_UNARYOPSTRATEGY_HPP
#define EXPRESSION_LIBRARY_UNARYOPSTRATEGY_HPP
#include <memory>

class UnaryOpStrategy {
public:
    virtual                                    ~UnaryOpStrategy() = default;
    virtual std::unique_ptr<Expression> eval(const std::unique_ptr<Expression>& expression) = 0;
};


#endif //EXPRESSION_LIBRARY_UNARYOPSTRATEGY_HPP
