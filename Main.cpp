#include "CPU.h"
#include <iostream>


int main() {
    std::cout << "This, is a test, nothing more.";
    CPU cpu = CPU();
    cpu.writeExecutionStep(50,"Initialize variables");
    cpu.execution(30);
    cpu.systemCall(10,1);
    cpu.execution(45);
    cpu.interrupt(238,26);
    return 0;
}
