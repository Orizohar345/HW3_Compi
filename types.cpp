
#include "types.h"

void verifyNumeric(std::string type1, std::string type2, int lineno)
{
        if ((type1 != "INT" and type1 != "BYTE") or (type2 != "INT" and type2 != "BYTE")) {
                output::errorMismatch(lineno);
                exit(1);
        }
}

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

std::string verifyFunc(std::string func_id, std::string arg_type, int lineno) {
        if (func_id == "print") {
                if (arg_type != "STRING") {
                        output::errorPrototypeMismatch(lineno, func_id, "STRING");
                        exit(1);
                }

                return "VOID";
        } else if (func_id == "printi") {
                if (arg_type != "INT" and arg_type != "BYTE" ) {
                        output::errorPrototypeMismatch(lineno, func_id,  "INT");
                        exit(1);
                }

                return "VOID";
        } else if (func_id == "readi") {
                if (arg_type != "INT" and arg_type != "BYTE" ) {
                        output::errorPrototypeMismatch(lineno, func_id, "INT");
                        exit(1);
                }

                return "INT";
        }


        output::errorUndefFunc(lineno, func_id);
        exit(1);
}

int verifyByte(std::string type1, std::string type2, int val1, int val2, std::string operation, int lineno) {
        int res;

        if (operation == "MULT")
                res = val1 * val2;
        else if (operation == "ADD")
                res = val1 + val2;

        if (type1 == "BYTE" && type2 == "BYTE") {
                if (res > 255) {
                        output::errorByteTooLarge(lineno, std::to_string(res));
                        exit(1);
                }
        }

        return res;
}

