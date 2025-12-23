//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_NUMBER_HPP
#define EXPRESSION_LIBRARY_NUMBER_HPP
#include "ExpressionType.hpp"

class Number : public Expression {
    double value;

public:
    Number(double value);
    Number(const std::string& value);
    [[nodiscard]] std::unique_ptr<Expression> evaluate() override;
    [[nodiscard]] std::unique_ptr<Expression> clone() const override;
    [[nodiscard]] double                      getValue() const;
};


class Identifier : public Expression {
    std::string name;

public:
    Identifier(const std::string& name);
    [[nodiscard]] std::unique_ptr<Expression> evaluate() override;
    [[nodiscard]] std::unique_ptr<Expression> clone() const override;
    [[nodiscard]] const std::string&          getName() const;
};

#endif //EXPRESSION_LIBRARY_NUMBER_HPP
