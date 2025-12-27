//
// Created by ryanm on 12/21/2025.
//
#include "BinaryOperators.hpp"

#include <stdexcept>

#include "Atoms.hpp"
#include "Environment.hpp"

#define nl left->evaluate()
#define nr right->evaluate()


Value Plus::eval(const std::shared_ptr<Expression> left, const std::shared_ptr<Expression> right) const {
    return nl + nr;
}

Value Minus::eval(const std::shared_ptr<Expression> left, const std::shared_ptr<Expression> right) const {
    return nl - nr;
}

Value Multiply::eval(const std::shared_ptr<Expression> left, const std::shared_ptr<Expression> right) const {
    return nl * nr;
}

Value Divide::eval(const std::shared_ptr<Expression> left, const std::shared_ptr<Expression> right) const {
    if (nr == 0) throw std::runtime_error("Division by zero"); //compiler should fix this
    return nl / nr;
}

Value Assign::eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const {
    const auto identifier = std::dynamic_pointer_cast<Identifier>(left);
    if (!identifier) throw std::runtime_error("Can only assign to identifiers");
    // Might need to update this later, but I can't think of any other cases rn
    const auto r = right->evaluate();
    Environment::getInstance().set(identifier->getName(), r);
    return r;
}
