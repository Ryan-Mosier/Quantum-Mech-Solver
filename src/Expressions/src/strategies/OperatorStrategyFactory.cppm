//
// Created by ryanm on 12/21/2025.
//


export module Expression.Strategies.Factory;

import Expression.Expression;
import Expression.OpStrategy;
import Expression.Token;
import Expression.Strategies.Operators;

export class UnaryStrategyFactory {
public:
    static const UnaryOpStrategy* createStrategy(TokenType type);
    static const UnaryOpStrategy* createStrategy(ExpressionType type);
    static ExpressionType         getType(const UnaryOpStrategy* strategy);
};

export class BinaryStrategyFactory {
public:
    static const BinaryOpStrategy* createStrategy(TokenType type);
    static const BinaryOpStrategy* createStrategy(ExpressionType type);
    static ExpressionType          getType(const BinaryOpStrategy* strategy);
};

