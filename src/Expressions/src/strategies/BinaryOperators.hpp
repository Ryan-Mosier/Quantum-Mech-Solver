//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_BINARYOPERATORS_HPP
#define EXPRESSION_LIBRARY_BINARYOPERATORS_HPP

#include "OpStrategy.hpp"

class Plus : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override;

    [[nodiscard]] std::string toString() const override { return "+"; }
};


class Minus : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override;

    [[nodiscard]] std::string toString() const override { return "-"; }
};

class Multiply : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override;

    [[nodiscard]] std::string toString() const override { return "*"; }
};

class Divide : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override;

    [[nodiscard]] std::string toString() const override { return "/"; }
};

class Assign : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override;

    [[nodiscard]] std::string toString() const override { return "="; }
};

#endif //EXPRESSION_LIBRARY_BINARYOPERATORS_HPP
