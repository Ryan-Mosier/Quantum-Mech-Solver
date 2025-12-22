//
// Created by ryanm on 12/21/2025.
//

#ifndef QUANTUM_MECH_SOLVER_PARSER_H
#define QUANTUM_MECH_SOLVER_PARSER_H
#include <list>
#include <string>
#include <utility>
#include <vector>
#include "Expressions/Expressions.hpp"

/// Converts a string into a vector of tokens, which can then be parsed into expressions
/// This does an entire file (src string) at a time. In the future it may make more sense to do this line by line instead
/// TODO: LaTex compatibility?
class Tokenizer {
private:
    std::string                   src;
    std::vector<std::string>      lines;
    std::vector<std::list<Token>> tokens;


    static TokenType        trySingleCharTokenize(const char& c);  // returns TokenType.Null on fail
    static std::list<Token> tokenizeLine(const std::string& line); // parses a single line of tokens

    void cleanseWhiteSpace(); //removes whitespace
    void seperateLines();     // separates lines into vector (also calls cleanseWhitespace)

public:
    Tokenizer(std::string src) : src(std::move(src)) {}
    std::vector<std::list<Token>> getTokens() { return tokens; }
    Tokenizer&                    tokenize();
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
