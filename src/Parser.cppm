//
// Created by ryanm on 12/21/2025.
//
module;
#include <string>
#include <vector>
#include <memory>

export module Parser;

import Expressions;
import Tokenizer;


export class Parser {
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

