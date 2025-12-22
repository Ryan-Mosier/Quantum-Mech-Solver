//
// Created by ryanm on 12/21/2025.
//

#ifndef QUANTUM_MECH_SOLVER_NUMBER_H
#define QUANTUM_MECH_SOLVER_NUMBER_H
#include <string>
#include "ExpressionType.hpp"

class Number : public Expression {
public:
    Number(const std::string& value);
    Number(const double value);
    std::unique_ptr<Expression>               evaluate() override;
    double                                    getValue() const;
    [[nodiscard]] std::unique_ptr<Expression> clone() const override;

private:
    double value;
};

#endif //QUANTUM_MECH_SOLVER_NUMBER_H
