//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_NUMBER_HPP
#define EXPRESSION_LIBRARY_NUMBER_HPP
#include "ExpressionType.hpp"

class Number : public Expression {
    double value;

public:
    Number(const double& value);
    Number(const std::string& value);
    [[nodiscard]] Value                       evaluate() const override;
    [[nodiscard]] std::shared_ptr<Expression> clone() const override;
    [[nodiscard]] std::string                 toString() const override;
};

class Identifier : public Expression {
    std::string name;

public:
    Identifier(std::string name);
    [[nodiscard]] Value                       evaluate() const override;
    [[nodiscard]] std::shared_ptr<Expression> clone() const override;
    [[nodiscard]] std::string                 toString() const override;
    [[nodiscard]] const std::string&          getName() const;
};

#endif //EXPRESSION_LIBRARY_NUMBER_HPP
