//
// Created by ryanm on 12/21/2025.
//
module;

#include <optional>
#include <string>

export module Expression.Token;


export enum class TokenType {
    Null,
    Assignment, // Basic
    Plus, Minus, Star, Slash,
    LParen, RParen,
    Comma, // Seperator for functions (eventually)
    Number, Identifier,
    EOFToken
};

export inline bool canBeUnary(TokenType type) {
    switch (type) {
        default:
            return false;
        case TokenType::Minus:
            return true;
    }
}

///
/// This is where we define our order of operations (in the binding power functions)
/// Higher number means it has higher precedence
///
// TODO: where does comma go?
// Assignments
#define first_level_power 1.0f
// ADD,SUB
#define second_level_power 2.0f
#define third_level_power 3.0f
#define fourth_level_power 4.0f
// MUL,DIV
#define fifth_level_power 5.0f
#define sixth_level_power 6.0f
#define seventh_level_power 7.0f
#define eighth_level_power 8.0f
#define ninth_level_power 9.0f

#define tenth_level_power 10.0f

export struct BindingPower {
    float left;
    float right;
    BindingPower(const float& p) : left(p), right(p + 0.1f) {}
    // override to invert associativity (the bool is discarded)
    BindingPower(const float& p, [[maybe_unused]] bool) : left(p), right(p - 0.1f) {}
};

//TODO: function to map binding powers
export inline std::optional<float> prefixBP(TokenType type) {
    // this functionally acts as a bool
    // nullopt is used when the token can't be used as a prefix
    // any other value is used when it can be
    using enum TokenType;
    switch (type) {
        default: return std::nullopt;
        case Minus: return first_level_power;
    }
}

export inline std::optional<BindingPower> infixBP(TokenType type) {
    using enum TokenType;
    switch (type) {
        case Plus:
        case Minus:
            return second_level_power;
        case Comma:
            return (ninth_level_power); // TODO: is this right?
        case Star:
        case Slash:
            return (fifth_level_power);
        case Assignment:
            return (first_level_power, true);

        case Null:
        case LParen:
        case RParen:
        case Number:
        case Identifier:
        case EOFToken:
            break;
    }
    return std::nullopt;
}


// TODO: define functionality for this
export inline std::optional<BindingPower> postfixBP(TokenType type) { return std::nullopt; }


export struct Token {
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