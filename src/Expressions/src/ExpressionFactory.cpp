//
// Created by ryanm on 12/21/2025.
//
module;
#include <stdexcept>
#include <memory>
#include <vector>
#include <string>
module Expression.ExpressionFactory;


std::shared_ptr<Expression> ExpressionFactory::createExpression(const Token& token,
                                                                const std::vector<std::shared_ptr<Expression>>&
                                                                expressions) {
    switch (expressions.size()) {
        default: throw std::runtime_error("No expression of given size: " + std::to_string(expressions.size()));
        case 1: { return createExpression(token, expressions[0]); }
        case 2: {
            const BinaryOpStrategy* strategy = BinaryStrategyFactory::createStrategy(token.type);
            return std::make_shared<BinaryExpression>(expressions[0], expressions[1], strategy,
                                                      mapToBinaryExpression(token.type));
        }
    }
}

std::shared_ptr<Expression> ExpressionFactory::createExpression(const Token&                       token,
                                                                const std::shared_ptr<Expression>& expressions) {
    const UnaryOpStrategy* strategy = UnaryStrategyFactory::createStrategy(token.type);
    return std::make_shared<UnaryExpression>(expressions, strategy, mapToUnaryExpression(token.type));
}

// We have to manually verify if the following are valid inputs, we can't trust the mapTo___Expression functions to throw exceptions for us
// Realistically, if our parser is working correctly, these should never fail (our parser should throw the error instead)

std::shared_ptr<Expression> ExpressionFactory::createExpression(const ExpressionType& type, const std::string& string) {
    switch (type) {
        case ExpressionType::Number: return std::make_shared<Number>(string);
        case ExpressionType::Identifier: return std::make_shared<Identifier>(string);
        default: throw std::runtime_error("Unknown expression type: " + std::to_string(static_cast<int>(type)));
    }
}

std::shared_ptr<Expression> ExpressionFactory::createExpression(const ExpressionType& type, const double& value) {
    switch (type) {
        case ExpressionType::Number: return std::make_shared<Number>(value);
        default: throw std::runtime_error("Unknown expression type: " + std::to_string(static_cast<int>(type)));
    }
}

std::shared_ptr<Expression> ExpressionFactory::createExpression(const std::string& type, const std::string& string) {
    if (type == "number") return std::make_shared<Number>(string);
    if (type == "identifier") return std::make_shared<Identifier>(string);
    throw std::runtime_error("Unknown expression type: " + type);
}

std::shared_ptr<Expression> ExpressionFactory::createExpression(const std::string& type, const double& value) {
    if (type == "number") return std::make_shared<Number>(value);
    throw std::runtime_error("Unknown expression type: " + type);
}
