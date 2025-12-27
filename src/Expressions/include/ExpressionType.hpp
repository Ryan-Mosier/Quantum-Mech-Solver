//
// Created by ryanm on 12/21/2025.
//

#ifndef QUANTUM_MECH_SOLVER_TYPES_H
#define QUANTUM_MECH_SOLVER_TYPES_H

#include <memory>
#include <stdexcept>
#include <string>

#include "Token.hpp"

/// Terminal Types of the AST, use std::variant<> for more in future
using Value = double;

enum class ExpressionType {
    Neg,
    Identifier, Number, Assignment, // Basic
    Plus, Minus, Multiply, Divide,  // Arithmetic
    FunctionCall,                   // Call a built-in function
    Null = 0                        // Allow testing if not null in if statements
};


class CastError : public std::runtime_error {
public:
    explicit CastError(const std::string& msg) : std::runtime_error(msg) {}
};

/// Map a token type to a binary expression type
inline ExpressionType mapToBinaryExpression(TokenType type) {
    switch (type) {
        default: throw std::invalid_argument("Invalid token type: " + std::to_string(static_cast<int>(type)));

        case TokenType::Null: throw
                std::invalid_argument("No null expression");
        case TokenType::Assignment: return ExpressionType::Assignment;

        case TokenType::Plus: return ExpressionType::Plus;
        case TokenType::Minus: return ExpressionType::Minus;
        case TokenType::Star: return ExpressionType::Multiply;
        case TokenType::Slash: return ExpressionType::Divide;

        case TokenType::LParen:
        case TokenType::RParen:
            throw CastError("Parenthesis behavior needs more info, must be handled in parser");
        case TokenType::Comma: throw CastError("Comma is not an expression");

        case TokenType::Identifier: return ExpressionType::Identifier;
        case TokenType::Number: return ExpressionType::Number;
    }
}

/// Map a token type to a unary expression type
inline ExpressionType mapToUnaryExpression(TokenType type) {
    switch (type) {
        default: throw std::invalid_argument("Invalid token type: " + std::to_string(static_cast<int>(type)));
        case TokenType::Minus: return ExpressionType::Neg;
    }
}

class Expression {
protected:
    ExpressionType type;

public:
    virtual  ~Expression() = default;
    explicit Expression(const ExpressionType type) : type(type) {}

    [[nodiscard]] ExpressionType getType() const { return type; };

    [[nodiscard]] virtual Value                       evaluate() const = 0;
    [[nodiscard]] virtual std::shared_ptr<Expression> clone() const = 0;

    [[nodiscard]] virtual std::string toString() const = 0;
};


#endif //QUANTUM_MECH_SOLVER_TYPES_H
