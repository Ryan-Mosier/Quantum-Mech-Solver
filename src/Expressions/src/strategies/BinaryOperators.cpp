//
// Created by ryanm on 12/21/2025.
//
#include "BinaryOperators.hpp"

#include <stdexcept>

#include "Atoms.hpp"


// This function will need to be checked when more types are added to Value
std::pair<double, double> extractNumbers(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) {
    auto l  = left->evaluate();
    auto r  = right->evaluate();
    return {l, r};
}

Value Plus::eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const {
    auto [nl, nr] = extractNumbers(std::move(left), std::move(right));
    return nl + nr;
}

Value Minus::eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const {
    auto [nl, nr] = extractNumbers(std::move(left), std::move(right));
    return nl - nr;
}

Value Multiply::eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const {
    auto [nl, nr] = extractNumbers(std::move(left), std::move(right));
    return nl * nr;
}

Value Divide::eval(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) const {
    auto [nl, nr] = extractNumbers(std::move(left), std::move(right));
    if (nr == 0) throw std::runtime_error("Division by zero");
    return nl / nr;
}
