//
// Created by ryanm on 12/21/2025.
//

#ifndef QUANTUM_MECH_SOLVER_TYPES_H
#define QUANTUM_MECH_SOLVER_TYPES_H

#include <memory>
#include <string>

/// Terminal Types of the AST, use std::variant<> for more in future
using Value = double;

enum class ExpressionType {
    Identifier, Number, Assignment, // Basic
    Plus, Minus, Multiply, Divide,  // Arithmetic
    Print,                          // Output to console
    FunctionCall,                   // Call a built-in function
};

class Expression {
protected:
    ExpressionType type;

public:
    virtual ~Expression() = default;

    [[nodiscard]] ExpressionType getType() const { return type; };

    [[nodiscard]] virtual Value evaluate() const = 0;
    [[nodiscard]] virtual std::shared_ptr<Expression> clone() const = 0;
};


#endif //QUANTUM_MECH_SOLVER_TYPES_H
