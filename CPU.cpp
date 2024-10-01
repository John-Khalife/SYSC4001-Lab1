/**
 * This is the deffinition file for the methods belonging to the CPU class.
 * @date September 30th, 2024
 * @author John Khalife, Stavros Karamalis
*/

#include "CPU.h"
#include <iostream>
#include <fstream>
#include <string>


void CPU::writeExecutionStep(int duration, std::string eventType) {
    std::ofstream file; //file stream object
    file.open("execution.txt", std::ios::app); //open execution file in append mode
    file << eventType << std::endl; // Write the execution message in the proper format
    file.close(); //Close the file
    //time += duration; //Add the amount of time to CPU time for the next write
}

void CPU::systemCall(int duration, int isrAddress) {
    //First switch to kernel mode
    switchCPUMode();
    
    using namespace std;
    int contextSaveDuration = (rand() % 10) + 1;
    writeExecutionStep(contextSaveDuration,"Context saved."); //Save context

    //Check vector table and call ISR
    ifstream file;
    string text;
    
    writeExecutionStep(1,"Find vector " + std::to_string(isrAddress) + "in memory position " + integerToHexString(isrAddress) + ".");
    file.open("VectorTable.txt");
    for (int i = 0 ; i <= isrAddress ; i++) {
        getline(file,text);
    }
    file.close(); // Now the text string should contain the ISR.
    writeExecutionStep(1, "Load address " + text + " into the PC."); //output the address being loaded
    
    //Call the device driver
    writeExecutionStep(duration - 5, "SYSCALL: Execute ISR.");

    //Prolly should switch back
    switchCPUMode();
    writeExecutionStep(1,"Transfer data."); //transfer data - //TODO: also a random time that sums to the duration with syscall
    writeExecutionStep(1,"Check for errors."); // Error check - //TODO: random time again - that sums to the duration with syscall!
    writeExecutionStep(1,"IRET"); // Interrupt return.
    // check for errors

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

std::string CPU::integerToHexString(int number) {
    char hexValue[6]; //TODO: make global const?
    snprintf(hexValue, 6, "%X", number); 
    return hexValue;
}




