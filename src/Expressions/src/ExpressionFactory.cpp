//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"
#include <stdexcept>
#include "strategies/BinaryStrategyFactory.hpp"

std::unique_ptr<Expression> ExpressionFactory::createExpression(const Token& token) {
    // TODO: construct left and right expressions
    return nullptr;
}

std::unique_ptr<Expression> ExpressionFactory::createExpression(const Token&                       token,
                                                                const std::unique_ptr<Expression>& left,
                                                                const std::unique_ptr<Expression>& right) {
    const BinaryOpStrategy* strategy = BinaryStrategyFactory::createStrategy(token.type);
    return std::make_unique<BinaryExpression>(left->clone(), right->clone(), strategy);
}

std::unique_ptr<Expression> ExpressionFactory::createExpression(const Token&                       token,
                                                                const std::unique_ptr<Expression>& expression) {
    throw std::logic_error("not implemented"); // Nothing in the language uses UnaryOperations yet!
}

std::unique_ptr<Expression> ExpressionFactory::createExpression(const std::string& type, const std::string& string) {
    if (type == "number") return std::make_unique<Number>(string);
    if (type == "identifier") return std::make_unique<Identifier>(string);
    return nullptr;
}
