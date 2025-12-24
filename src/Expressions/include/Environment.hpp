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
    std::map<std::string, Value> environment;
    Environment() = default;
    static Environment* instance;

public:
    void                              set(const std::string& name, const Value& value);
    void                              set(const std::string& name, const Expression* value);
    void                              set(const std::string& name, const std::shared_ptr<Expression>& value);
    [[nodiscard]] const Value*        get(const std::string& name) const;
    [[nodiscard]] bool                exists(const std::string& name) const;
    [[nodiscard]] static Environment& getInstance() { return *instance; }
};


#endif //EXPRESSION_LIBRARY_ENVIRONMENT_HPP
