//
// Created by ryanm on 12/21/2025.
//
module;

#include <memory>

export module Expression.Strategies.Operators;

import Expression.Atoms;
import Expression.Expression;
import Expression.OpStrategy;
import Expression.Environment;

/// UNARY

export class Neg : public UnaryOpStrategy {
public:
    [[nodiscard]] Value eval(const std::shared_ptr<Expression>& expression) const override {
        return -1 * expression->evaluate();
    }

    [[nodiscard]] std::string toString() const override { return "-"; }
};

/// BINARY


export class Plus : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override {
        return left->evaluate() + right->evaluate();
    }

    [[nodiscard]] std::string toString() const override { return "+"; }
};


export class Minus : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override {
        return left->evaluate() - right->evaluate();
    }

    [[nodiscard]] std::string toString() const override { return "-"; }
};


export class Multiply : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override {
        return left->evaluate() * right->evaluate();
    }

    [[nodiscard]] std::string toString() const override { return "*"; }
};


export class Divide : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override {
        if (right->evaluate() == 0) throw std::runtime_error("Division by zero"); //compiler should fix this
        return left->evaluate() / right->evaluate();
    }

    [[nodiscard]] std::string toString() const override { return "/"; }
};


export class Assign : public BinaryOpStrategy {
    [[nodiscard]] Value
    eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const override {
        const auto identifier = std::dynamic_pointer_cast<Identifier>(left);
        if (!identifier) throw std::runtime_error("Can only assign to identifiers");
        // Might need to update this later, but I can't think of any other cases rn
        const auto r = right->evaluate();
        Environment::getInstance().set(identifier->getName(), r);
        return r;
    }

    [[nodiscard]] std::string toString() const override { return "="; }
};
