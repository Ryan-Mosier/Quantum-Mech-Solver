//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"

BinaryExpression::BinaryExpression(const std::unique_ptr<Expression>& left, const std::unique_ptr<Expression>& right,
                                   const BinaryOpStrategy* strategy) : left(left->clone()),
    right(right->clone()), strategy(strategy) {}

std::unique_ptr<Expression> BinaryExpression::evaluate() { return strategy->eval(left->clone(), right->clone()); }

std::unique_ptr<Expression> BinaryExpression::clone() const {
    return std::make_unique<BinaryExpression>(left, right, strategy);
}
