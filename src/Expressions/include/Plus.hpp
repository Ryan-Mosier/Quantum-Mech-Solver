//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_PLUS_HPP
#define EXPRESSION_LIBRARY_PLUS_HPP

#include "ExpressionType.hpp"


class Plus : public Expression {
private:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

public:
    Plus(const std::unique_ptr<Expression>& left, const std::unique_ptr<Expression>& right);
    std::unique_ptr<Expression> evaluate() override;
    [[nodiscard]] std::unique_ptr<Expression> clone() const override;
};


#endif //EXPRESSION_LIBRARY_PLUS_HPP
