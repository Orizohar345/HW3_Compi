#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <string>
#include "hw3_output.hpp"

struct Exp {
        std::string text;
        std::string type;
        bool is_const;
};

std::string verifyBinop(std::string type1, std::string type2, int lineno);
void verifyNumeric(std::string type1, std::string type2, int lineno);
std::string verifyFunc(std::string func_id, std::string arg_type, int lineno);

#endif
