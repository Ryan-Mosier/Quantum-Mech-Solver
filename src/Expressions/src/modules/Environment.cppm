//
// Created by ryanm on 12/21/2025.
//
module;

#include <string>
#include <unordered_map>
#include <memory>

export module Expression.Environment;
export import Expression.Expression;


export class Environment {
private:
    std::unordered_map<std::string, Value> environment{};
    Environment() = default;

public:
    void                              set(const std::string& name, const Value& value);
    void                              set(const std::string& name, const Expression* value);
    void                              set(const std::string& name, const std::shared_ptr<Expression>& value);
    [[nodiscard]] const Value*        get(const std::string& name) const;
    [[nodiscard]] bool                exists(const std::string& name) const;
    [[nodiscard]] static Environment& getInstance();
};
