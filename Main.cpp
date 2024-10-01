#include "CPU.h"
#include <iostream>
#include <fstream>
#include "Parsing.h"



int main() {
    std::cout << "This, is a test, nothing more." << std::endl;
    std::ifstream test;
    CPU cpu = CPU();
    test.open("trace1.txt");
    while(test.is_open()){
        parsing::instr* operation = parsing::readFromTrace(&test);
        cpu.executeInstruction(operation);
    }
    return 0;
}
