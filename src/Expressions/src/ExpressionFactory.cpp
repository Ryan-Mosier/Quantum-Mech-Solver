//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"
#include <stdexcept>
#include "strategies/BinaryStrategyFactory.hpp"

std::shared_ptr<Expression> ExpressionFactory::createExpression(const Token& token) {
    // TODO: construct left and right expressions
    return nullptr;
}

std::shared_ptr<Expression> ExpressionFactory::createExpression(const Token&                       token,
                                                                const std::shared_ptr<Expression>& left,
                                                                const std::shared_ptr<Expression>& right) {
    const BinaryOpStrategy *strategy = BinaryStrategyFactory::createStrategy(token.type);
    return std::make_shared<BinaryExpression>(left, right, strategy);
}

std::shared_ptr<Expression> ExpressionFactory::createExpression(const Token&                        token,
                                                                const std::shared_ptr<Expression> & expression) {
    throw std::logic_error("not implemented"); // Nothing in the language uses UnaryOperations yet!
}

std::shared_ptr<Expression> ExpressionFactory::createExpression(const std::string& type, const std::string& string) {
    if (type == "number") return std::make_shared<Number>(string);
    if (type == "identifier") return std::make_shared<Identifier>(string);
    return nullptr;
}
