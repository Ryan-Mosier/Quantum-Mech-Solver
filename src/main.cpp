//
// Created by ryanm on 12/21/2025.
//

#include <iostream>
#include <string>
import Parser;
import interpreter;

// This code will contain the main entry point for the program, handle UI (terminal for now) and manage program flow
int main() {
    std::string line;
    std::cout
        << "Quantum Mech Solver Terminal Interface\n"
        << "Type 'file' followed by a file path to evaluate a file\n"
        << "Type 'exit' to quit";

    while (true) {
        std::cout << ">> ";
        if (!std::getline(std::cin, line) || line == "exit") { break; }
        if (line.starts_with("file ")) {
            evaluateFile(line.substr(5));
            continue;
        }
        if (line.empty()) { continue; }

        // The Parser expects expressions to end with ';' based on Tokenizer::seperateLines()
        if (line.back() != ';') { line += ';'; }

        try {
            Parser parser(line);
            auto   expressions = parser.getExpressions();
            for (const auto& expr : expressions) {
                std::cout << expr->toString() << " => " << expr->evaluate() << std::endl;
            }
        }
        catch (const std::exception& e) { std::cerr << "Error: " << e.what() << std::endl; }
    }
    return 0;
}
