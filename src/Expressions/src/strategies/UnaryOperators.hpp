//
// Created by ryanm on 12/26/2025.
//

#ifndef QUANTUM_MECH_SOLVER_UNARYOPERATORS_HPP
#define QUANTUM_MECH_SOLVER_UNARYOPERATORS_HPP

#include "OpStrategy.hpp"

class Neg : public UnaryOpStrategy {
public:
    [[nodiscard]] Value eval(const std::shared_ptr<Expression>& expression) const override;

    [[nodiscard]] std::string toString() const override { return "-"; }
};


#endif //QUANTUM_MECH_SOLVER_UNARYOPERATORS_HPP
