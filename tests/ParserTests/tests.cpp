#include <gtest/gtest.h>

import Expressions.all;
import Parser;
// Simple tests
TEST(ParserTests, SimpleAddition) {
    Parser parser("1 + 2;");
    auto   expressions = parser.getExpressions();
    ASSERT_EQ(expressions.size(), 1);
    EXPECT_EQ(expressions[0]->toString(), "(+ 1 2 )");
    EXPECT_DOUBLE_EQ(expressions[0]->evaluate(), 3.0);
}

TEST(ParserTests, SimpleAssignment) {
    Parser parser("x = 10;");
    auto   expressions = parser.getExpressions();
    ASSERT_EQ(expressions.size(), 1);
    EXPECT_EQ(expressions[0]->toString(), "(= x 10 )");
    EXPECT_DOUBLE_EQ(expressions[0]->evaluate(), 10.0);
    EXPECT_DOUBLE_EQ(*Environment::getInstance().get("x"), 10.0);
}

// Complex single-line tests
TEST(ParserTests, ComplexSingleLineArithmetic) {
    Parser parser("1 + 2 * 3;");
    auto   expressions = parser.getExpressions();
    ASSERT_EQ(expressions.size(), 1);
    EXPECT_EQ(expressions[0]->toString(), "(+ 1 (* 2 3 ) )");
    EXPECT_DOUBLE_EQ(expressions[0]->evaluate(), 7.0);
}

TEST(ParserTests, ComplexSingleLineParentheses) {
    Parser parser("(1 + 2) * 3;");
    auto   expressions = parser.getExpressions();
    ASSERT_EQ(expressions.size(), 1);
    EXPECT_EQ(expressions[0]->toString(), "(* (+ 1 2 ) 3 )");
    EXPECT_DOUBLE_EQ(expressions[0]->evaluate(), 9.0);
}

// Multi line complex statements
TEST(ParserTests, MultiLineComplex) {
    Parser parser("a = 5; b = 10; c = a + b * 2;");
    auto   expressions = parser.getExpressions();
    ASSERT_EQ(expressions.size(), 3);

    EXPECT_EQ(expressions[0]->toString(), "(= a 5 )");
    EXPECT_DOUBLE_EQ(expressions[0]->evaluate(), 5.0);

    EXPECT_EQ(expressions[1]->toString(), "(= b 10 )");
    EXPECT_DOUBLE_EQ(expressions[1]->evaluate(), 10.0);

    EXPECT_EQ(expressions[2]->toString(), "(= c (+ a (* b 2 ) ) )");
    EXPECT_DOUBLE_EQ(expressions[2]->evaluate(), 25.0);

    EXPECT_DOUBLE_EQ(*Environment::getInstance().get("c"), 25.0);
}

