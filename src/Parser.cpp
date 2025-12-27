//
// Created by ryanm on 12/21/2025.
//

#include "Parser.hpp"

#include <set>
#include <vector>
#include <stdexcept>
#include "Expressions/include/Token.hpp"


std::optional<Token> Tokenizer::trySingleCharTokenize(const size_t& line_idx, size_t& char_idx) const {
    const std::map<char, TokenType> token_map = {
        {'=', TokenType::Assignment},
        {'+', TokenType::Plus},
        {'-', TokenType::Minus},
        {'*', TokenType::Star},
        {'/', TokenType::Slash},
        {'(', TokenType::LParen},
        {')', TokenType::RParen},
        {',', TokenType::Comma},
        {' ', TokenType::Null}
    };
    const std::string& line = lines[line_idx];
    if (const auto it = token_map.find(line[char_idx]); it != token_map.end()) {
        char_idx++;
        return Token(it->second, std::string(1, it->first), char_idx - 1);
    }
    return std::nullopt;
}

[[nodiscard]] std::optional<Token> multiCharTokenInternal(size_t& char_idx, const std::string& line, TokenType type,
                                                          bool (* isValid)(const char)) {
    size_t upper_limit = line.length();
    size_t i           = char_idx;

    std::string token_string = line.substr(i++, 1); //working string

    while (i < upper_limit && isValid(line[i])) {
        token_string += line[i];
        i++;
    }
    const auto start_idx = char_idx;
    char_idx             = i;
    return Token(type, token_string, start_idx);
}

std::optional<Token> Tokenizer::tryMultiCharTokenize(const size_t& line_idx, size_t& char_idx) const {
    const auto           c    = static_cast<unsigned char>(lines[line_idx][char_idx]);
    auto                 line = lines[line_idx];
    std::optional<Token> token;
    //sample the first character
    if (std::isdigit(c)) {
        auto isValid = [](const char c) { return std::isdigit(c) || c == '.'; };
        token        = multiCharTokenInternal(char_idx, line, TokenType::Number, isValid);
    }
    else if (std::isalpha(c) || c == '_') {
        auto isValid = [](const char c) { return std::isalnum(c) || c == '_'; };
        token        = multiCharTokenInternal(char_idx, line, TokenType::Identifier, isValid);
    }
    return token;
}

std::deque<Token> Tokenizer::tokenizeLine(const size_t& line_idx) const {
    std::deque<Token>  line_tokens;
    const std::string& line = lines[line_idx];
    size_t             i    = 0;
    const size_t       size = line.size();
    while (i < size) {
        std::optional<Token> token = trySingleCharTokenize(line_idx, i);
        if (token) {
            if (token->type == TokenType::Null)
                continue;
            line_tokens.push_back(token.value());
            continue;
        }
        token = tryMultiCharTokenize(line_idx, i); // i is mutated
        if (token) { line_tokens.push_back(token.value()); }
        else {
            throw std::invalid_argument(
                "invalid token at: (" + std::to_string(line_idx) + "," + std::to_string(i) + ")"
            );
        }
    }
    line_tokens.emplace_back(TokenType::EOFToken, "", size);
    return line_tokens;
}

void Tokenizer::seperateLines() {
    std::string line;
    bool        isComment = false;
    for (const auto& c : src) {
        // Are there any more newline characters?
        if ((c == '\n' || c == '\r') && isComment) { isComment = false; }
        if (isComment) { continue; }

        if (c == ';') {
            lines.push_back(line);
            line = "";
        }
        else if (c == '#') { isComment = true; } // may want to expand this so we can use // for comments
        else { line += c; }
    }
}

Tokenizer& Tokenizer::tokenize() {
    seperateLines();
    for (int i = 0; i < lines.size(); i++) { tokens.emplace_back(tokenizeLine(i)); }
    return *this; //allows chaining
}

void Parser::parse() {
    for (current_line_idx = 0; current_line_idx < srcTokens.size(); current_line_idx++) {
        auto lineExpr = parseExpression(0);
        expressions.push_back(lineExpr);
    }
}

/// Simplify Parsing code
inline void throwParseError(const size_t& current_line_idx, const size_t& current_idx) {
    throw std::runtime_error("Invalid token at line " + std::to_string(current_line_idx) + " at index " +
        std::to_string(current_idx - 1));
}


// allowed: anything that can be unary, numbers, identifiers
inline bool isValidStart(const TokenType& type) {
    return canBeUnary(type) || type == TokenType::Number || type == TokenType::Identifier;
}

/// Using Pratt Parsing
std::shared_ptr<Expression> Parser::parseExpression(const float min_bp) {
    // Get first token
    TokenLine& tokenLine  = srcTokens[current_line_idx]; // simplify access
    Token      firstToken = tokenLine.next();            // consume first
    // confirm valid lhs
    using enum TokenType;
    std::shared_ptr<Expression> lhs   = nullptr;
    auto                        preBP = prefixBP(firstToken.type);

    if (preBP.has_value()) {
        auto internal = parseExpression(preBP.value());
        lhs           = ExpressionFactory::createExpression(firstToken, internal);
    }
    else {
        switch (firstToken.type) {
            default:
                throwParseError(current_line_idx, current_idx);
            case Number:
            case Identifier: {
                auto type = mapToBinaryExpression(firstToken.type);
                lhs       = ExpressionFactory::createExpression(type, firstToken.value);
                break;
            }
            case LParen:
                lhs = parseExpression(0);
                // make sure that we terminated on a RParen
                if (srcTokens[current_line_idx].next().type != RParen) {
                    throwParseError(current_line_idx, current_idx);
                }
                break;
        }
    }

    while (true) {
        auto currToken = tokenLine.peek();
        if (currToken.type == EOFToken || currToken.type == RParen) { break; }
        if (currToken.type == Assignment && (lhs.get()->getType() != ExpressionType::Identifier)) {
            throwParseError(current_line_idx, current_idx);
        }
        auto bp = infixBP(currToken.type);
        if (!bp.has_value()) { break; }
        if (bp->left < min_bp) { break; }
        tokenLine.pop();
        auto rhs = parseExpression(bp->right);
        lhs      = ExpressionFactory::createExpression(currToken, {lhs, rhs});
    }
    return lhs;
}


Parser::Parser(const std::string& src) {
    srcTokens = Tokenizer(src).tokenize().getTokens();
    parse();
}
