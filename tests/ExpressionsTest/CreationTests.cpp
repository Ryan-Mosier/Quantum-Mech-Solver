//
// Created by ryanm on 12/22/2025.
//

#include <gtest/gtest.h>
#include "Expressions.hpp"

TEST(CreationTests, TestNumberCreation) {
    Number number("42");
    ASSERT_EQ(number.getValue(), 42);
    ASSERT_EQ(number.getType(), ExpressionType::Number);

    Number number2(42);
    ASSERT_EQ(number2.getValue(), 42);
    ASSERT_EQ(number2.getType(), ExpressionType::Number);
}

TEST(CreationTests, TestIdentifierCreation) {
    Identifier identifier("foo");
    ASSERT_EQ(identifier.getName(), "foo");
    ASSERT_EQ(identifier.getType(), ExpressionType::Identifier);
}

TEST(CreationTests, TestBinaryExpressionCreation) {
    auto l = std::make_unique<Number>(1);
    auto r = std::make_unique<Number>(2);
    Token plus(TokenType::Plus, "1", "2");
    auto expr = ExpressionFactory::createExpression(plus, l, r);
    ASSERT_EQ(expr->getType(), ExpressionType::Plus);
}

TEST(CreationTests, TestFactoryWithStrings) {
    auto n = ExpressionFactory::createExpression("number", "123.45");
    ASSERT_EQ(n->getType(), ExpressionType::Number);
    ASSERT_EQ(static_cast<Number*>(n.get())->getValue(), 123.45);

    auto id = ExpressionFactory::createExpression("identifier", "my_var");
    ASSERT_EQ(id->getType(), ExpressionType::Identifier);
    ASSERT_EQ(static_cast<Identifier*>(id.get())->getName(), "my_var");
}

TEST(CreationTests, TestBinaryExpressionTypes) {
    auto l = std::make_unique<Number>(1);
    auto r = std::make_unique<Number>(2);
    
    ASSERT_EQ(ExpressionFactory::createExpression(Token(TokenType::Plus, "", ""), l, r)->getType(), ExpressionType::Plus);
    ASSERT_EQ(ExpressionFactory::createExpression(Token(TokenType::Minus, "", ""), l, r)->getType(), ExpressionType::Minus);
    ASSERT_EQ(ExpressionFactory::createExpression(Token(TokenType::Star, "", ""), l, r)->getType(), ExpressionType::Multiply);
    ASSERT_EQ(ExpressionFactory::createExpression(Token(TokenType::Slash, "", ""), l, r)->getType(), ExpressionType::Divide);
}