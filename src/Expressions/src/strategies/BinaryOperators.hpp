//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_BINARYOPERATORS_HPP
#define EXPRESSION_LIBRARY_BINARYOPERATORS_HPP
#include "OpStrategy.hpp"

class Plus : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override;
};


class Minus : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override;
};

class Multiply : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override;
};

class Divide : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override;
};

class Assign : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override;
};

#endif //EXPRESSION_LIBRARY_BINARYOPERATORS_HPP
