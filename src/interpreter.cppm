//
// Created by ryanm on 12/30/2025.
//
module;
#include <string>
export module interpreter;

import Parser;
import Expressions;
export void evaluateFile(const std::string& filename);
