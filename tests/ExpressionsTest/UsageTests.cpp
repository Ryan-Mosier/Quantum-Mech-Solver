#include <gtest/gtest.h>
#include "Expressions.hpp"

TEST(UsageTests, TestNumberEvaluation) {
    Number n(3.14);
    auto   result = n.evaluate();
    ASSERT_EQ(n.evaluate(), 3.14);
}

TEST(UsageTests, TestIdentifierEvaluation) {
    Environment::getInstance().set("x", std::make_shared<Number>(10.0));
    Identifier id("x");
    ASSERT_EQ(id.evaluate(), 10.0);
}

TEST(UsageTests, TestBinaryExpressionEvaluation) {
    auto  l = std::make_unique<Number>(5.0);
    auto  r = std::make_unique<Number>(3.0);
    Token plus(TokenType::Plus, "5", "3");
    auto  expr = ExpressionFactory::createExpression(plus, l->clone(), r->clone());
    ASSERT_EQ(expr->evaluate(), 8.0);
}

TEST(UsageTests, TestClone) {
    Number n(42.0);
    auto   cloned = n.clone();
    ASSERT_NE(cloned.get(), &n);
    ASSERT_EQ(cloned.get()->evaluate(), 42.0);
}

TEST(UsageTests, TestEnvironment) {
    auto& env = Environment::getInstance();
    env.set("test_var", std::make_unique<Number>(123.0));
    ASSERT_TRUE(env.exists("test_var"));
    ASSERT_EQ(*env.get("test_var"), 123.0);
}
