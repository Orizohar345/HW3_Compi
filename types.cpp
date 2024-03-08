
#include "types.h"
#include <typeinfo>


std::string verifyBinop(std::string type1, std::string type2, int lineno)
{
        verifyNumeric(type1, type2, lineno);
        if ((type1 != "INT" and type1 != "BYTE") or (type2 != "INT" and type2 != "BYTE")) {
                output::errorMismatch(lineno);
                exit(1);
        }

        if (type1 == "BYTE" and type2 == "BYTE")
                return "BYTE";

        return "INT";
}

void verifyNumeric(std::string type1, std::string type2, int lineno)
{
        if ((type1 != "INT" and type1 != "BYTE") or (type2 != "INT" and type2 != "BYTE")) {
                output::errorMismatch(lineno);
                exit(1);
        }
}

std::string verifyFunc(std::string func_id, std::string arg_type, int lineno) {
        if (func_id == "print") {
                if (arg_type != "STRING") {
                        output::errorPrototypeMismatch(lineno, func_id, arg_type);
                        exit(1);
                }

                return "VOID";
        } else if (func_id == "prini") {
                if (arg_type != "INT" and arg_type != "BYTE" ) {
                        output::errorPrototypeMismatch(lineno, func_id, arg_type);
                        exit(1);
                }

                return "VOID";
        } else if (func_id == "readi") {
                if (arg_type != "INT" and arg_type != "BYTE" ) {
                        output::errorPrototypeMismatch(lineno, func_id, arg_type);
                        exit(1);
                }

                return "INT";
        }


        output::errorUndefFunc(lineno, func_id);
        exit(1);
}

int main() {

        std::cout << verifyBinop("BYTE", "BYTE", 0) << std::endl;
        std::cout << verifyBinop("BYTE", "BYTE", 0) << std::endl;
        std::cout << verifyBinop("INT", "BYTE", 0) << std::endl;
        std::cout << verifyBinop("BYTE", "INT", 0) << std::endl;
        std::cout << verifyBinop("INT", "INT", 0) << std::endl;

}
