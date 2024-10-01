/**
 * This is the definition file for the methods belonging to the CPU class.
 * @date September 30th, 2024
 * @author John Khalife, Stavros Karamalis
*/

#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include <string>
#include "CPU.h"
#include "Parsing.h"


void CPU::writeExecutionStep(int duration, std::string eventType) {
    std::ofstream file; //file stream object
    file.open("execution.txt", std::ios::app); //open execution file in append mode
    file << timer << ", " << duration << ", " << eventType << std::endl; // Write the execution message in the proper format
    file.close(); //Close the file
    timer += duration; //Add the amount of timer to CPU timer for the next write
}

void CPU::systemCall(int duration, int isrAddress) {
    accessVectorTable(isrAddress);

    std::default_random_engine generator; // generates uniformly distributed numbers
    generator.seed(time(0)); //Give the generator a seed
    std::uniform_real_distribution<> isrDistribution(0, 0.25); //probability distribution for 0-25% of the duration.
    int dataTransferTime = (int) duration*isrDistribution(generator) + 1; //time for data transfer
    int errorCheckingTime = (int) duration*isrDistribution(generator) + 1; //generate time for error checking

    //Call the device driver
    writeExecutionStep(duration - dataTransferTime - errorCheckingTime, "SYSCALL: Execute ISR.");
    writeExecutionStep(dataTransferTime,"Transfer data."); //transfer data
    writeExecutionStep(errorCheckingTime,"Check for errors."); // Error check
    writeExecutionStep(1,"IRET"); // Interrupt return.
}

void CPU::executeCPU(int duration) {
    writeExecutionStep(duration,"CPU execution.");
}

void CPU::interrupt(int duration, int isrAddress) {
    writeExecutionStep(1,"Check the priority of interrupt.");
    writeExecutionStep(1,"Check if interrupt is masked.");
    accessVectorTable(isrAddress);
    writeExecutionStep(duration,"END_IO"); 
    writeExecutionStep(1,"IRET"); // Interrupt return.
}

void CPU::accessVectorTable(int isrAddress) {
    std::default_random_engine generator; // generates uniformly distributed numbers
    generator.seed(time(0)); //Give the generator a seed
    std::uniform_int_distribution<int> contextSaveTimeDistribution(1,3); //Create a distribution

    //First switch to kernel mode
    writeExecutionStep(1,"Switch CPU to Kernel mode.");
    
    using namespace std;
    writeExecutionStep(contextSaveTimeDistribution(generator),"Context saved."); //Save context

    //Check vector table and call ISR
    ifstream file;
    string text;
    
    writeExecutionStep(1,"Find vector " + std::to_string(isrAddress) + " in memory position " + parsing::integerToHexString(isrAddress) + ".");
    file.open("VectorTable.txt");
    for (int i = 0 ; i <= isrAddress ; i++) {
        getline(file,text);
    }
    file.close(); // Now the text string should contain the ISR.
    writeExecutionStep(1, "Load address " + text + " into the PC."); //output the address being loaded
}


void CPU::executeInstruction(parsing::instr* instruction) {
    if (!parsing::orders::CPU.compare(instruction->argName)) {
        executeCPU(instruction->args[0]);
    } else if (!parsing::orders::SYSCALL.compare(instruction->argName)) {
        systemCall(instruction->args[1],instruction->args[0]);
    } else if (!parsing::orders::END_IO.compare(instruction->argName)) {
        interrupt(instruction->args[1],instruction->args[0]);
    }
}
