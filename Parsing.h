#ifndef __PARSING_H__
#define __PARSING_H__
#include <iostream>
#include <string>
#include <fstream>

namespace parsing{

    struct instruction{
        int args[2];
        std::string argName;
    } typedef instr;

    instr readFromTrace(std::ifstream* file);
};

#endif