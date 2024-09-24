#include <iostream>
#include "CPU.h"
#include <fstream>

void CPU::writeExecutionStep(int duration, std::string eventType) {
    ofstream file; //file stream object
    file.open("execution.txt", std::ios::app); //open execution file in append mode
    file << clock << ", " << duration << ", " << eventType << std::endl; // Write the execution message in the proper format
    file.close(); //Close the file
}

void CPU::systemCall(int duration, int isrAddress) {
    //First switch to kernel mode
    switchCPUMode();

    //Save context

    //Check vector table and call ISR
    ifstream file;
    std::string text;
    file.open("VectorTable.txt");
    for (int i = 0 ; i <= isrAddress ; i++) {
        getline(file,text);
    }
    file.close(); // Now the text string should contain the ISR.

    //Call the device driver
    //TODO: Determine what should be put in the vector table - so that we know what function to call.

    //Prolly should switch back
    switchCPUMode();
}

void CPU::switchCPUMode() {
    if (kernelMode) {
        writeExecutionStep(1,"Switch CPU to User mode.");
        kernelMode = false;
    } else {
        writeExecutionStep(1,"Switch CPU to Kernel mode.");
        kernelMode = true;
    }
}

bool CPU::isKernelMode() {
    return kernelMode;
}



