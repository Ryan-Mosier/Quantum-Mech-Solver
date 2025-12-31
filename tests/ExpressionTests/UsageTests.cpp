#include <gtest/gtest.h>
import Expressions.all;
TEST(ExpressionTests, TestNumberEvaluation) {
    Number n(3.14);
    auto   result = n.evaluate();
    ASSERT_EQ(n.evaluate(), 3.14);
}

TEST(ExpressionTests, TestIdentifierEvaluation) {
    Environment::getInstance().set("x", std::make_shared<Number>(10.0));
    Identifier id("x");
    ASSERT_EQ(id.evaluate(), 10.0);
}

TEST(ExpressionTests, TestBinaryExpressionEvaluation) {
    auto  l = std::make_unique<Number>(5.0);
    auto  r = std::make_unique<Number>(3.0);
    Token plus(TokenType::Plus, "+", 0);
    auto  expr = ExpressionFactory::createExpression(plus, {l->clone(), r->clone()});
    ASSERT_EQ(expr->evaluate(), 8.0);
}

TEST(ExpressionTests, TestClone) {
    Number n(42.0);
    auto   cloned = n.clone();
    ASSERT_NE(cloned.get(), &n);
    ASSERT_EQ(cloned.get()->evaluate(), 42.0);
}

TEST(ExpressionTests, TestEnvironment) {
    auto& env = Environment::getInstance();
    env.set("test_var", std::make_unique<Number>(123.0));
    ASSERT_TRUE(env.exists("test_var"));
    ASSERT_EQ(*env.get("test_var"), 123.0);
}

TEST(ExpressionTests, ComplexTreeEvaluation) {
    // ((x + 5) * (y - 10)) / (z * 2) + 100 / 4 - 5
    // x=10, y=20, z=5 -> ((10+5)*(20-10)) / (5*2) + 25 - 5 = (15*10)/10 + 20 = 15 + 20 = 35
    auto& env = Environment::getInstance();
    env.set("x", 10.0);
    env.set("y", 20.0);
    env.set("z", 5.0);

    auto x    = std::make_shared<Identifier>("x");
    auto y    = std::make_shared<Identifier>("y");
    auto z    = std::make_shared<Identifier>("z");
    auto n5   = std::make_shared<Number>(5.0);
    auto n10  = std::make_shared<Number>(10.0);
    auto n2   = std::make_shared<Number>(2.0);
    auto n100 = std::make_shared<Number>(100.0);
    auto n4   = std::make_shared<Number>(4.0);

    auto x_plus_5   = ExpressionFactory::createExpression(Token(TokenType::Plus, "+", 0), {x, n5});
    auto y_minus_10 = ExpressionFactory::createExpression(Token(TokenType::Minus, "-", 0), {y, n10});
    auto numer      = ExpressionFactory::createExpression(Token(TokenType::Star, "*", 0), {x_plus_5, y_minus_10});

    auto z_times_2 = ExpressionFactory::createExpression(Token(TokenType::Star, "*", 0), {z, n2});

    auto left_term = ExpressionFactory::createExpression(Token(TokenType::Slash, "/", 0), {numer, z_times_2});

    auto hundred_div_4 = ExpressionFactory::createExpression(Token(TokenType::Slash, "/", 0), {n100, n4});

    auto sum = ExpressionFactory::createExpression(Token(TokenType::Plus, "+", 0), {left_term, hundred_div_4});

    auto final_expr = ExpressionFactory::createExpression(Token(TokenType::Minus, "-", 0), {sum, n5});

    ASSERT_EQ(final_expr->evaluate(), 35.0);
}

TEST(ExpressionTests, DeepTreeEvaluation) {
    // 1 + (2 + (3 + (4 + (5 + (6 + (7 + (8 + (9 + 10)))))))) = 55
    std::shared_ptr<Expression> expr = std::make_shared<Number>(10.0);
    for (int i = 9; i >= 1; --i) {
        expr = ExpressionFactory::createExpression(
            Token(TokenType::Plus, "+", 0),
            {
                std::make_shared<Number>(static_cast<double>(i)),
                expr
            }
        );
    }
    ASSERT_EQ(expr->evaluate(), 55.0);
}
