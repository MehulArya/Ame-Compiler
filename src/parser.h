#pragma once
#include "tokenization.h"

struct NodeExpr{
    Token int_lit;
};
struct NodeExit {
    NodeExpr expr;
};

class Parser {
public:
    inline explicit Parser(std::vector<Token> tokens): m_tokens(std::move(tokens)) {

    }

    std::optional<NodeExpr> parse_expr() {

        if (peek().has_value() && peek().value().type == TokenType::int_lit) {
            return NodeExpr{.int_lit = consume()};
        }
        else {
            return {};
        }
    }

    std::optional<NodeExit> parse() {
        std::optional<NodeExit> exit_node;
        while (peek().has_value()) {
            if (peek().has_value()) {
                if (peek().value().type == TokenType::exit && peek(1).has_value() && peek(1).value().type == TokenType::open_paren) {
                    consume();
                    consume();
                    if (auto node_expr = parse_expr()) {
                        exit_node = NodeExit{.expr = node_expr.value()};
                    }
                    else {
                        std::cout << "Invalid Expression" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    if (peek().has_value() && peek().value().type == TokenType::close_paren) {
                        consume();
                    }
                    else {
                        std::cout << "Invalid Expression" << std::endl;
                    }
                    if (peek().has_value() && peek().value().type == TokenType::semi) {
                        consume();
                    }
                    else {
                        std::cout << "Expected Semi Colon" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }
            }
            else {
                consume();
            }
        }
        m_index = 0;
        return exit_node;
    }
private:
    inline std::optional<Token> peek(int ahead = 0) const {
        if (m_index + ahead >= m_tokens.size()) {
            return {};
        }
        else {
            return m_tokens[m_index + ahead];
        }
    }

    inline Token consume() {
        return m_tokens[m_index++];
    }

    const std::vector<Token> m_tokens;
    size_t m_index = 0;
};