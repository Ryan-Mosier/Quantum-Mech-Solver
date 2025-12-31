//
// Created by ryanm on 12/21/2025.
//

module;
#include <vector>
#include <stdexcept>
#include <memory>

module Parser;

import Tokenizer;
import Expressions;


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
