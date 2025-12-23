//
// Created by ryanm on 12/21/2025.
//
#include "BinaryOperators.hpp"

#include <stdexcept>

#include "Atoms.hpp"

std::pair<double, double> extractNumbers(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right) {
    auto l  = left->evaluate();
    auto r  = right->evaluate();
    auto nl = dynamic_cast<Number*>(l.get());
    auto nr = dynamic_cast<Number*>(r.get());
    if (!nl || !nr) throw std::runtime_error("Invalid operands");
    return {nl->getValue(), nr->getValue()};
}

std::unique_ptr<Number> generateReturn(double value) { return std::make_unique<Number>(value); }

std::unique_ptr<Expression> Plus::eval(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right) const {
    auto [nl, nr] = extractNumbers(std::move(left), std::move(right));
    return generateReturn(nl + nr);
}

std::unique_ptr<Expression> Minus::eval(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right) const {
    auto [nl, nr] = extractNumbers(std::move(left), std::move(right));
    return generateReturn(nl - nr);
}

std::unique_ptr<Expression> Multiply::eval(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right) const {
    auto [nl, nr] = extractNumbers(std::move(left), std::move(right));
    return generateReturn(nl * nr);
}

std::unique_ptr<Expression> Divide::eval(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right) const {
    auto [nl, nr] = extractNumbers(std::move(left), std::move(right));
    if (nr == 0) throw std::runtime_error("Division by zero");
    return generateReturn(nl / nr);
}
