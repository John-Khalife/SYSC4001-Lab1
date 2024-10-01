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
    cpu.execution(30);
    cpu.systemCall(10,1);
    cpu.execution(45);
    cpu.interrupt(238,26);
    return 0;
}
