//
// Created by ryanm on 12/21/2025.
//

#ifndef QUANTUM_MECH_SOLVER_PARSER_H
#define QUANTUM_MECH_SOLVER_PARSER_H
#include <string>
#include <utility>
#include <vector>
#include "Expressions/include/ExpressionType.hpp"
#include "Expressions/include/Token.hpp"
#include "Expressions/Expressions.hpp"



/// Converts a string into a vector of tokens, which can then be parsed into expressions
/// This does an entire file (src string) at a time. In the future it may make more sense to do this line by line instead
class Tokenizer
{
private:
    std::string src;
    std::vector<std::string> lines;
    std::vector<std::vector<Token>> tokens;


    static TokenType trySingleCharTokenize(const char& c); // returns TokenType.Null on fail
    static std::vector<Token> tokenizeLine(const std::string &line); // parses a single line of tokens

    void cleanseWhiteSpace(); //removes whitespace
    void seperateLines(); // separates lines into vector (also calls cleanseWhitespace)

public:
    Tokenizer(std::string src): src(std::move(src)) {}
    std::vector<std::vector<Token>> getTokens() { return tokens; }
    Tokenizer& tokenize();
};

class Parser
{
private:
    std::vector<std::vector<Token>> srcTokens;
    std::vector<Expression*> expressions;
    void checkValidIdentifier(const std::string& left);
    void parse(); // called during init
    Expression parseLine(std::vector<Token> lineTokens);
    ~Parser() = default;
public:
    Parser(const std::string &src);
    std::vector<Expression*> getExpressions() {return expressions; }

};

#endif //QUANTUM_MECH_SOLVER_PARSER_H