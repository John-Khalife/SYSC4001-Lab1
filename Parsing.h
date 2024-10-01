#ifndef __PARSING_H__
#define __PARSING_H__
#include <iostream>
#include <string>
#include <fstream>

namespace parsing{

    const int MAX_PARAMETERS = 2; // Constant that holds the maximum number of parameters a command can have.

    // If ever a new instruction needs to be added - add the equivalent string here
    namespace orders {
        using namespace std;
        const string CPU = "CPU";
        const string SYSCALL = "SYSCALL";
        const string END_IO = "END_IO";
    }

    //This struct holds the contents of an instruction including command and arguments
    struct instruction{
        int args[MAX_PARAMETERS];
        std::string argName;
    } typedef instr;

    /**
     * This function reads from a trace given and returns an instruction each time it is called.
     * @param file - an ifstream object that provides access to the trace.
     * @return an instruction object containing the neccessary information for the CPU to execute a command.
    */
    instr* readFromTrace(std::ifstream* file);

    /**
     * This function converts an integer to a hexidecimal string.
     * @param number - an integer that will be converted.
     * @return a hexidecimal string.
    */
    std::string integerToHexString(int number);
};

#endif