#include "CPU.h"
#include <iostream>
#include <fstream>
#include "Parsing.h"



int main() {
    std::cout << "This, is a test, nothing more." << std::endl;
    CPU cpu = CPU();
    int numline = 0;
    std::ifstream test;
    test.open("trace1.txt");
    std::cout << test.eof();
    while(!test.eof()){
        parsing::readFromTrace(&test);
        numline++;
    }
    test.close();

    cpu.writeExecutionStep(50,"Initialize variables");
    cpu.writeExecutionStep(70,"This is a test of a second instruction - does it append?");
    cpu.systemCall(10,1);
    return 0;
}
