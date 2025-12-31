//
// Created by ryanm on 12/21/2025.
//
module;

#include <memory>

export module Expression.Atoms;
import Expression.Expression;
import Expression.Environment;

export class Number : public Expression {
    double value;

public:
    Number(const double& value);
    Number(const std::string& value);
    [[nodiscard]] Value                       evaluate() const override;
    [[nodiscard]] std::shared_ptr<Expression> clone() const override;
    [[nodiscard]] std::string                 toString() const override;
};

export class Identifier : public Expression {
    std::string name;

public:
    Identifier(std::string name);
    [[nodiscard]] Value                       evaluate() const override;
    [[nodiscard]] std::shared_ptr<Expression> clone() const override;
    [[nodiscard]] std::string                 toString() const override;
    [[nodiscard]] const std::string&          getName() const;
};

