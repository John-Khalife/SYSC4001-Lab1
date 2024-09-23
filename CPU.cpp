#include <iostream>
#include "CPU.h"

void CPU::writeToFile() {
     ofstream myfile;
    myfile.open("execution.txt");
    myfile << "Writing to file";
    myfile.close(); 
}


