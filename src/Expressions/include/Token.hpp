//
// Created by ryanm on 12/21/2025.
//


#ifndef QUANTUM_MECH_SOLVER_TOKENTYPE_H
#define QUANTUM_MECH_SOLVER_TOKENTYPE_H

#include <map>

enum class TokenType {
    Null,
    Assignment, // Basic
    Plus, Minus, Star, Slash,
    LParen, RParen,
    Comma // Seperator
};

const std::map<char, TokenType> token_map = {
    {'=', TokenType::Assignment},
    {'+', TokenType::Plus},
    {'-', TokenType::Minus},
    {'*', TokenType::Star},
    {'/', TokenType::Slash},
    {'(', TokenType::LParen},
    {')', TokenType::RParen},
    {',', TokenType::Comma}
};

struct Token {
    TokenType                 type;
    std::string               left;  // the string to the left of this token until the next token on the left
    std::string               right; // same, but right
    std::pair<Token*, Token*> adj;   // this will make the parsing less unhinged
    // adj.first is the token to the left, adj.second is the token to the right. This will not cross lines
    Token(TokenType type, std::string left, std::string right) : type(type), left(std::move(left)),
                                                                 right(std::move(right)) {}
};

#endif //QUANTUM_MECH_SOLVER_TOKENTYPE_H
