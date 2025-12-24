//
// Created by ryanm on 12/21/2025.
//

#ifndef QUANTUM_MECH_SOLVER_PARSER_H
#define QUANTUM_MECH_SOLVER_PARSER_H
#include <list>
#include <optional>
#include <string>
#include <utility>
#include <vector>
#include "Expressions/Expressions.hpp"

/// Converts a string into a 2D vector of tokens, which can then be parsed into expressions
/// This does an entire file (src string) at a time. In the future it may make more sense to do this line by line instead
/// TODO: LaTex compatibility?
class Tokenizer {
private:
    std::string                     src;
    std::vector<std::string>        lines;
    std::vector<std::vector<Token>> tokens;


    [[nodiscard]] std::optional<Token> trySingleCharTokenize(const size_t& line_idx, size_t& char_idx) const;
    [[nodiscard]] std::optional<Token> tryMultiCharTokenize(const size_t& line_idx, size_t& char_idx) const;
    std::vector<Token>   tokenizeLine(const size_t& line_idx) const; // parses a single line of tokens

    void seperateLines(); // separates lines into the vector, 'lines' are separated with ';'

public:
    Tokenizer(std::string src) : src(std::move(src)) {}
    const std::vector<std::vector<Token>>& getTokens() { return tokens; }
    Tokenizer&                             tokenize();
};

class Parser {
private:
    std::vector<std::list<Token>>            srcTokens;
    std::vector<std::unique_ptr<Expression>> expressions;
    static void                              checkValidIdentifier(const std::string& left);
    void                                     parse(); // called during init
    std::unique_ptr<Expression>              parseLine(const std::list<Token>& lineTokens);
    ~Parser() = default;

public:
    Parser(const std::string& src);
    std::vector<std::unique_ptr<Expression>>& getExpressions() { return expressions; }
};

#endif //QUANTUM_MECH_SOLVER_PARSER_H
