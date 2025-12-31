//
// Created by ryanm on 12/21/2025.
//
module;
#include <string>
#include <vector>
#include <memory>

export module Expression.ExpressionFactory;

import Expression.Expression;
import Expression.Token;
import Expression.Strategies.Factory;
import Expression.OpStrategy;
import Expression.CompositeExpressions;
import Expression.Atoms;


export class ExpressionFactory {
public:
    /// Fills expressions left to right based on the vector
    static std::shared_ptr<Expression> createExpression(const Token&                                    token,
                                                        const std::vector<std::shared_ptr<Expression>>& expressions);
    static std::shared_ptr<Expression> createExpression(const Token&                       token,
                                                        const std::shared_ptr<Expression>& expressions);

    //used for atom/leaf expressions
    static std::shared_ptr<Expression> createExpression(const std::string& type, const std::string& string);
    static std::shared_ptr<Expression> createExpression(const std::string& type, const double& value);
    static std::shared_ptr<Expression> createExpression(const ExpressionType& type, const std::string& string);
    static std::shared_ptr<Expression> createExpression(const ExpressionType& type, const double& value);
};
