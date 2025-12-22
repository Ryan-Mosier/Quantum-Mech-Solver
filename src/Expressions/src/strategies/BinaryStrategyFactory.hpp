//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_BINARYSTRATEGYFACTORY_HPP
#define EXPRESSION_LIBRARY_BINARYSTRATEGYFACTORY_HPP
#include <memory>

#include "BinaryOpStrategy.hpp"
#include "ExpressionType.hpp"
#include "Token.hpp"


class BinaryStrategyFactory {
public:
    static std::shared_ptr<BinaryOpStrategy> createStrategy(TokenType type);
    static std::shared_ptr<BinaryOpStrategy> createStrategy(ExpressionType type);
};


#endif //EXPRESSION_LIBRARY_BINARYSTRATEGYFACTORY_HPP
