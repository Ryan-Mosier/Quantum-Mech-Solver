//
// Created by ryanm on 12/21/2025.
//

#ifndef EXPRESSION_LIBRARY_ENVIRONMENT_HPP
#define EXPRESSION_LIBRARY_ENVIRONMENT_HPP

#include <map>
#include <string>
#include "ExpressionType.hpp"


class Environment {
private:
    std::map<std::string, std::unique_ptr<Expression>> environment;
    Environment() = default;
    static Environment* instance;

public:
    void                            set(const std::string& name, const std::unique_ptr<Expression>& expr);
    [[nodiscard]] const Expression* get(const std::string& name) const;
    [[nodiscard]] bool              exists(const std::string& name) const;
    static Environment&             getInstance();
};

#endif //EXPRESSION_LIBRARY_ENVIRONMENT_HPP
