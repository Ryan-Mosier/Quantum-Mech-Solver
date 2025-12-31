//
// Created by ryanm on 12/30/2025.
//
module;
#include <unordered_map>
#include <string>
#include <optional>
#include <deque>
#include <stdexcept>

module Tokenizer;

std::optional<Token> Tokenizer::trySingleCharTokenize(const size_t& line_idx, size_t& char_idx) const {
    const std::unordered_map<char, TokenType> token_map = {
        {'=', TokenType::Assignment},
        {'+', TokenType::Plus},
        {'-', TokenType::Minus},
        {'*', TokenType::Star},
        {'/', TokenType::Slash},
        {'(', TokenType::LParen},
        {')', TokenType::RParen},
        {',', TokenType::Comma},
        {' ', TokenType::Null}
    };
    const std::string& line = lines[line_idx];
    if (const auto it = token_map.find(line[char_idx]); it != token_map.end()) {
        char_idx++;
        return Token(it->second, std::string(1, it->first), char_idx - 1);
    }
    return std::nullopt;
}

[[nodiscard]] std::optional<Token> multiCharTokenInternal(size_t& char_idx, const std::string& line, TokenType type,
                                                          bool (* isValid)(const char)) {
    size_t upper_limit = line.length();
    size_t i           = char_idx;

    std::string token_string = line.substr(i++, 1); //working string

    while (i < upper_limit && isValid(line[i])) {
        token_string += line[i];
        i++;
    }
    const auto start_idx = char_idx;
    char_idx             = i;
    return Token(type, token_string, start_idx);
}

std::optional<Token> Tokenizer::tryMultiCharTokenize(const size_t& line_idx, size_t& char_idx) const {
    const auto           c    = static_cast<unsigned char>(lines[line_idx][char_idx]);
    auto                 line = lines[line_idx];
    std::optional<Token> token;
    //sample the first character
    if (std::isdigit(c)) {
        auto isValid = [](const char c) { return std::isdigit(c) || c == '.'; };
        token        = multiCharTokenInternal(char_idx, line, TokenType::Number, isValid);
    }
    else if (std::isalpha(c) || c == '_') {
        auto isValid = [](const char c) { return std::isalnum(c) || c == '_'; };
        token        = multiCharTokenInternal(char_idx, line, TokenType::Identifier, isValid);
    }
    return token;
}

std::deque<Token> Tokenizer::tokenizeLine(const size_t& line_idx) const {
    std::deque<Token>  line_tokens;
    const std::string& line = lines[line_idx];
    size_t             i    = 0;
    const size_t       size = line.size();
    while (i < size) {
        std::optional<Token> token = trySingleCharTokenize(line_idx, i);
        if (token) {
            if (token->type == TokenType::Null)
                continue;
            line_tokens.push_back(token.value());
            continue;
        }
        token = tryMultiCharTokenize(line_idx, i); // i is mutated
        if (token) { line_tokens.push_back(token.value()); }
        else {
            throw std::invalid_argument(
                "invalid token at: (" + std::to_string(line_idx) + "," + std::to_string(i) + ")"
            );
        }
    }
    line_tokens.emplace_back(TokenType::EOFToken, "", size);
    return line_tokens;
}

void Tokenizer::seperateLines() {
    std::string line;
    bool        isComment = false;
    for (const auto& c : src) {
        // Are there any more newline characters?
        if ((c == '\n' || c == '\r') && isComment) { isComment = false; }
        if (isComment) { continue; }

        if (c == ';') {
            lines.push_back(line);
            line = "";
        }
        else if (c == '#') { isComment = true; } // may want to expand this so we can use // for comments
        else if (c == '\n' || c == '\r' || c == ' ') {
            //do nothing on whitespace
        }
        else { line += c; }
    }
}

Tokenizer& Tokenizer::tokenize() {
    seperateLines();
    for (int i = 0; i < lines.size(); i++) { tokens.emplace_back(tokenizeLine(i)); }
    return *this; //allows chaining
}
