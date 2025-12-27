//
// Created by ryanm on 12/26/2025.
//

#include "UnaryOperators.hpp"
Value Neg::eval(const std::shared_ptr<Expression>& expression) const { return -1 * expression->evaluate(); }
