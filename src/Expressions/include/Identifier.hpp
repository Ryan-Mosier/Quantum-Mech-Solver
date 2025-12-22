//
// Created by ryanm on 12/21/2025.
//

#ifndef QUANTUM_MECH_SOLVER_IDENTIFIER_H
#define QUANTUM_MECH_SOLVER_IDENTIFIER_H
#include "ExpressionType.hpp"


class Identifier : public Expression {
public:
    Identifier(const std::string& ident);
    std::unique_ptr<Expression>               evaluate() override;
    [[nodiscard]] std::string                 getIdentifier() const;
    [[nodiscard]] std::unique_ptr<Expression> clone() const override;

private:
    std::string ident;
};


#endif //QUANTUM_MECH_SOLVER_IDENTIFIER_H
