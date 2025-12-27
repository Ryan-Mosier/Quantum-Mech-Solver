//
// Created by ryanm on 12/21/2025.
//

#ifndef QUANTUM_MECH_SOLVER_PARSER_H
#define QUANTUM_MECH_SOLVER_PARSER_H
#include <deque>
#include <optional>
#include <string>
#include <utility>
#include <vector>
#include "Expressions/Expressions.hpp"

class TokenLine {
public:
    std::deque<Token> tokens;
    TokenLine(std::deque<Token> tokens) : tokens(std::move(tokens)) {}

    void                       pop() { tokens.pop_front(); }
    [[nodiscard]] const Token& peek() const { return tokens.front(); }

    /// Copy and pop
    Token next() {
        auto tmp = tokens.front();
        tokens.pop_front();
        return tmp;
    }
};

/// Converts a string into a vector of TokenLines, which can then be parsed into expressions
/// This does an entire file (src string) at a time, read the file into a string with ';' to separate lines. In the future it may make more sense to do this line by line instead
/// TODO: LaTex compatibility?
class Tokenizer {
private:
    std::string              src;
    std::vector<std::string> lines;
    std::vector<TokenLine>   tokens;


    [[nodiscard]] std::optional<Token> trySingleCharTokenize(const size_t& line_idx, size_t& char_idx) const;
    [[nodiscard]] std::optional<Token> tryMultiCharTokenize(const size_t& line_idx, size_t& char_idx) const;
    [[nodiscard]] std::deque<Token>    tokenizeLine(const size_t& line_idx) const; // parses a single line of tokens

    void seperateLines(); // separates lines into the vector, 'lines' are separated with ';'

public:
    Tokenizer(std::string src) : src(std::move(src)) {}
    const std::vector<TokenLine>& getTokens() { return tokens; }
    Tokenizer&                    tokenize();
};


class Parser {
private:
    std::vector<TokenLine>                   srcTokens;
    std::vector<std::shared_ptr<Expression>> expressions;
    size_t                                   current_line_idx = 0;
    size_t                                   current_idx      = 0;
    void                                     parse(); // called during init
    std::shared_ptr<Expression>              parseExpression(float min_bp);

public:
    explicit Parser(const std::string& src);
    ~Parser() = default;

    const std::vector<std::shared_ptr<Expression>>& getExpressions() { return expressions; }
};

#endif //QUANTUM_MECH_SOLVER_PARSER_H
