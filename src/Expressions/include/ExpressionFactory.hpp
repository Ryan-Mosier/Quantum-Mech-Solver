//
// Created by ryanm on 12/21/2025.
//

#ifndef QUANTUM_MECH_SOLVER_EXPRESSIONFACTORY_H
#define QUANTUM_MECH_SOLVER_EXPRESSIONFACTORY_H
#include <string>
#include <vector>

#include "ExpressionType.hpp"
#include "Token.hpp"

class ExpressionFactory {
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


#endif //QUANTUM_MECH_SOLVER_EXPRESSIONFACTORY_H
