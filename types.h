#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <string>
#include "hw3_output.hpp"

class Node {
public:
    std::string text;

    // Constructor
    Node(const std::string& text) : text(text) {}

    // Virtual destructor to ensure proper cleanup of derived types
    virtual ~Node() {}

    // Copy constructor
    Node(const Node& other) : text(other.text) {}

    // Copy assignment operator
    Node& operator=(const Node& other) {
        if (this != &other) {
            text = other.text;
        }
        return *this;
    }

    // Move constructor
    Node(Node&& other) noexcept : text(std::move(other.text)) {}

    // Move assignment operator
    Node& operator=(Node&& other) noexcept {
        if (this != &other) {
            text = std::move(other.text);
        }
        return *this;
    }
};

#define YYSTYPE Node*

// Class for types, same as Node
class Type : public Node {
public:
    using Node::Node; // Inherit constructors
};

class Exp : public Node {
public:
    std::string type;
    int val;
    bool is_const;

    // Constructor
    Exp(const std::string& text, const std::string& type, int val, bool is_const)
        : Node(text), type(type), val(val), is_const(is_const) {}

    // Copy constructor
    Exp(const Exp& other)
        : Node(other), type(other.type), val(other.val), is_const(other.is_const) {}

    // Copy assignment operator
    Exp& operator=(const Exp& other) {
        if (this != &other) {
            Node::operator=(other); // Call base class assignment operator
            type = other.type;
            val = other.val;
            is_const = other.is_const;
        }
        return *this;
    }
};

class Call : public Exp {
public:
    using Exp::Exp;
};


void verifyNumeric(std::string type1, std::string type2, int lineno);
std::string verifyBinop(std::string type1, std::string type2, int lineno);
int verifyByte(std::string type1, std::string type2, int val1, int val2, std::string operation, int lineno);
std::string verifyFunc(std::string func_id, std::string arg_type, int lineno);

#endif
