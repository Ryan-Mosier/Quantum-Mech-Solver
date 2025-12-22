//
// Created by ryanm on 12/21/2025.
//

#ifndef QUANTUM_MECH_SOLVER_EXPRESSIONFACTORY_H
#define QUANTUM_MECH_SOLVER_EXPRESSIONFACTORY_H
#include <string>
#include "ExpressionType.hpp"
#include "Token.hpp"

class ExpressionFactory {
public:
    static std::unique_ptr<Expression> createExpression(const Token& token);
    static std::unique_ptr<Expression> createExpression(const Token& token, const std::unique_ptr<Expression>& left,
                                                        const std::unique_ptr<Expression>& right);
    static std::unique_ptr<Expression> createExpression(const Token&                       token,
                                                        const std::unique_ptr<Expression>& expression);
    //used for ident/number expressions
    static std::unique_ptr<Expression> createExpression(const std::string& type, const std::string& string);
};


#endif //QUANTUM_MECH_SOLVER_EXPRESSIONFACTORY_H
