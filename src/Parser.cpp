//
// Created by ryanm on 12/21/2025.
//

#include "Parser.hpp"

#include <set>
#include <vector>
#include <list>
#include <stdexcept>
#include "Expressions/include/Token.hpp"

TokenType Tokenizer::trySingleCharTokenize(const char& c) {
    if (auto it = token_map.find(c); it != token_map.end())
        return it->second;
    return TokenType::Null;
}

std::list<Token> Tokenizer::tokenizeLine(const std::string& line) {
    // i is the current index
    // j is the index after prev token
    int              i = 0, j = 0;
    std::list<Token> tokens;
    for (auto& c : line) {
        if (TokenType t = trySingleCharTokenize(c); t != TokenType::Null) {
            std::string left     = line.substr(j, i);
            Token       newToken = {t, left, ""};\
            if (!tokens.empty()) {
                tokens.back().right = left; // left of this is the right of the prev
            }
            tokens.emplace_back(newToken);

            j = i + 1;
        }
        i++;
    }
    return tokens;
}

void Tokenizer::cleanseWhiteSpace() {
    std::string newSrc;
    static const std::set
        newLines = {'\n', '\r', ';'}; //allow use of ';' as a newline character
    for (auto& c : src) {
        bool isNewline = newLines.count(c);
        if (c != ' ') newSrc += c; //cleanses spaces
        else if (newLines.count(newSrc.back()) && isNewline) continue;
        else if (isNewline) newSrc += '\n'; // standardizes newlines
    }
    src = std::move(newSrc);
}

void Tokenizer::seperateLines() {
    std::string line;
    for (auto& c : src) {
        if (c == '\n') {
            lines.push_back(line);
            line = "";
        }
        else line += c;
    }
}

Tokenizer& Tokenizer::tokenize() {
    cleanseWhiteSpace();
    seperateLines();
    for (auto& line : lines) { tokens.push_back(tokenizeLine(line)); }
    return *this;
}

Parser::Parser(const std::string& src) {
    srcTokens = std::move(Tokenizer(src).tokenize().getTokens());
    parse();
}


void Parser::checkValidIdentifier(const std::string& left) {
    //TODO: this should check that proper identifier grammar is present, throws error on fail
}

void Parser::parse() { for (const auto& t : srcTokens) { auto expr = parseLine(t); } }

std::unique_ptr<Expression> Parser::parseLine(const std::list<Token>& lineTokens) {
    for (auto& token : lineTokens) {
        switch (token.type) {
            default: break;
            case TokenType::Null:
                throw std::invalid_argument("null token");
            case TokenType::Assignment:
                // check that left is a valid Identifier string
                checkValidIdentifier(token.left); //throws error
                // generate expression for the right side
                break;
            case TokenType::Plus:
                break;
            case TokenType::Minus:
                break;
            case TokenType::Star:
                break;
            case TokenType::Slash:
                break;
            case TokenType::LParen:
                break;
            case TokenType::RParen:
                break;
            case TokenType::Comma:
                break;
        }
    }
    throw std::invalid_argument("no expression found"); //TODO: this is broken 100%
}
