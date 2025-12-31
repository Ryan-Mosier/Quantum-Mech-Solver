//
// Created by ryanm on 12/21/2025.
//
module;
#include <string>
#include <memory>

module Expression.Environment;


void Environment::set(const std::string& name, const Value& value) { environment[name] = value; }
void Environment::set(const std::string& name, const Expression* value) { environment[name] = value->evaluate(); }

void Environment::set(const std::string& name, const std::shared_ptr<Expression>& value) {
    environment[name] = value->evaluate();
}

const Value* Environment::get(const std::string& name) const {
    const auto it = environment.find(name);
    return (it == environment.end()) ? nullptr : &(it->second);
}

bool Environment::exists(const std::string& name) const { return environment.contains(name); }

Environment& Environment::getInstance() {
    static Environment instance;
    return instance;
}