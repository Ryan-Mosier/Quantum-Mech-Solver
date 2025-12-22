//
// Created by ryanm on 12/21/2025.
//

#include <memory>
#include <stdexcept>

#include "Expressions.hpp"

Plus::Plus(const std::unique_ptr<Expression>& left, const std::unique_ptr<Expression>& right) : left(left->clone()),
    right(right->clone()) {}

std::unique_ptr<Expression> Plus::evaluate() {
    const auto l  = left->evaluate();
    const auto r  = right->evaluate();
    const auto nl = dynamic_cast<Number*>(l.get());
    const auto nr = dynamic_cast<Number*>(r.get());
    if (!nl || !nr) { throw std::logic_error("Can't add two non-numbers together"); }
    return std::make_unique<Number>(nl->getValue() + nr->getValue());
}

std::unique_ptr<Expression> Plus::clone() const { return std::make_unique<Plus>(left, right); }
