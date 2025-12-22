//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_ASSIGNMENT_H
#define EXPRESSION_LIBRARY_ASSIGNMENT_H
#include "ExpressionType.hpp"
#include "Identifier.hpp"


class Assignment : public Expression {
    std::unique_ptr<Expression> identifier;
    std::unique_ptr<Expression> expression;

public:
    Assignment(const std::unique_ptr<Expression>& identifier, const std::unique_ptr<Expression>& expression);
    std::unique_ptr<Expression>               evaluate() override;
    [[nodiscard]] std::unique_ptr<Expression> clone() const override;
};


#endif //EXPRESSION_LIBRARY_ASSIGNMENT_H
