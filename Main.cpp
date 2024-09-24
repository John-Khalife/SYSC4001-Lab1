#include "CPU.h"
#include <iostream>


int main() {
    std::cout << "This, is a test, nothing more.";
    CPU cpu = CPU();
    cpu.writeExecutionStep(50,"Initialize variables");
    cpu.writeExecutionStep(70,"This is a test of a second instrcution - does it append?");
    return 0;
}
