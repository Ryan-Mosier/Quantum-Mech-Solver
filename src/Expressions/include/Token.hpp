//
// Created by ryanm on 12/21/2025.
//


#ifndef QUANTUM_MECH_SOLVER_TOKENTYPE_H
#define QUANTUM_MECH_SOLVER_TOKENTYPE_H

enum class TokenType {
    Null,
    Assignment, // Basic
    Plus, Minus, Star, Slash,
    LParen, RParen,
    Comma, // Seperator
    Number, Identifier
};

struct Token {
    TokenType   type;
    std::string value; //the string that this token represents
    // size_t is much bigger than we really should need, but it got clang to shut up...
    size_t start_index;
    size_t end_index;

    Token(const TokenType& type, std::string value, const size_t& start_index) : type(type), value(std::move(value)),
        start_index(start_index),
        end_index(start_index + value.size()) {}

    explicit Token(const TokenType& type) : Token(type, "", 0) {}
};

#endif //QUANTUM_MECH_SOLVER_TOKENTYPE_H
