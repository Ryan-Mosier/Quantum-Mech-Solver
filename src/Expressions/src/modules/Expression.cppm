//
// Created by ryanm on 12/21/2025.
//
module;

#include <memory>
#include <stdexcept>
#include <string>

export module Expression.Expression;
import Expression.Token;


/// Terminal Types of the AST, use std::variant<> for more in the future
export using Value = double;

export enum class ExpressionType {
    Neg,
    Identifier, Number, Assignment, // Basic
    Plus, Minus, Multiply, Divide,  // Arithmetic
    FunctionCall,                   // Call a built-in function
    Null = 0                        // Allow testing if not null in if statements
};


/// Map a token type to a binary expression type
export inline ExpressionType mapToBinaryExpression(TokenType type) {
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
            throw std::invalid_argument("Parenthesis behavior needs more info, must be handled in parser");
        case TokenType::Comma: throw std::invalid_argument("Comma is not an expression");

        case TokenType::Identifier: return ExpressionType::Identifier;
        case TokenType::Number: return ExpressionType::Number;
    }
}

/// Map a token type to a unary expression type
export inline ExpressionType mapToUnaryExpression(TokenType type) {
    switch (type) {
        default: throw std::invalid_argument("Invalid token type: " + std::to_string(static_cast<int>(type)));
        case TokenType::Minus: return ExpressionType::Neg;
    }
}

export class Expression {
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
