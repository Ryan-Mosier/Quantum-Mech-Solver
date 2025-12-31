//
// Created by ryanm on 12/21/2025.
//
module;
#include <fstream>
#include <iostream>
#include <string>

module interpreter;

void evaluateFile(const std::string& filename) {
    auto file = std::ifstream(filename);

    if (!file.is_open()) { throw std::runtime_error("Failed to open file: " + filename); }
    const auto data = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    try {
        Parser      parser(data);
        const auto& exprList = parser.getExpressions();
        for (const auto& expr : exprList) { std::cout << expr->toString() << " => " << expr->evaluate() << std::endl; }
    }
    catch (const std::exception& e) { std::cerr << "Error: " << e.what() << std::endl; }
}
