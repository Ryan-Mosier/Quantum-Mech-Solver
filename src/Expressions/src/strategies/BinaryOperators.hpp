//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_BINARYOPERATORS_HPP
#define EXPRESSION_LIBRARY_BINARYOPERATORS_HPP
#include "BinaryOpStrategy.hpp"

class Plus : public BinaryOpStrategy {
    std::unique_ptr<Expression>
    eval(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right) const override;
};


class Minus : public BinaryOpStrategy {
    std::unique_ptr<Expression>
    eval(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right) const override;
};

class Multiply : public BinaryOpStrategy {
    std::unique_ptr<Expression>
    eval(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right) const override;
};

class Divide : public BinaryOpStrategy {
    std::unique_ptr<Expression>
    eval(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right) const override;
};


#endif //EXPRESSION_LIBRARY_BINARYOPERATORS_HPP
