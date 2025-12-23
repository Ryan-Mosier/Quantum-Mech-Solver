//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"
#include <map>
#include <string>
#include <memory>
#include <stdexcept>

Environment* Environment::instance = nullptr;

void Environment::set(const std::string& name, const std::unique_ptr<Expression>& expr) {
    environment[name] = expr->clone();
}

const Expression* Environment::get(const std::string& name) const {
    try { return environment.at(name).get(); }
    catch (const std::out_of_range& e) { throw std::invalid_argument("Undefined variable: " + name); }
}

bool Environment::exists(const std::string& name) const { return environment.find(name) != environment.end(); }

Environment& Environment::getInstance() {
    if (!instance) { instance = new Environment(); }
    return *instance;
}
