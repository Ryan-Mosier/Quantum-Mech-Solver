//
// Created by ryanm on 12/21/2025.
//

#include "Expressions.hpp"
#include <map>
#include <string>
#include <memory>
#include <stdexcept>

Environment* Environment::instance = new Environment();

void Environment::set(const std::string& name, const Value& value) { environment[name] = value; }
void Environment::set(const std::string& name, const Expression* value) { environment[name] = value->evaluate(); }

void Environment::set(const std::string& name, const std::shared_ptr<Expression>& value) {
    environment[name] = value->evaluate();
}

const Value* Environment::get(const std::string& name) const {
    const auto it = environment.find(name);
    return (it == environment.end()) ? nullptr : &(it->second);
}

bool Environment::exists(const std::string& name) const { return environment.find(name) != environment.end(); }
