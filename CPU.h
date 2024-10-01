/**
 * This file contains the declarations and descriptions of methods belonging
 * to the CPU class.
 * @date September 30th, 2024
 * @author John Khalife, Stavros Karamalis
*/

#ifndef __CPU_H__
#define __CPU_H__

//dependencies
#include <iostream>
#include <fstream>

class CPU {

    private:

        //Member variables
        int timer; //used to keep track of timer
    
    public: //TODO: Only the execute instruction method needs to be public

        /**
        * Constructor of the CPU class.
        */
        CPU() {
            timer = 0;
        }
        
        /**
         * Method used to write CPU events to the output file
         * @param duration - An integer stating the timer taken for the CPU to complete the action
         * @param eventType - A string dictating the action of the CPU
         * 
        */
        void writeExecutionStep(int duration, std::string eventType);

        /**
         * This method is intended to be used for a system call - it checks the input device.
         * @param duration - An integer stating the timer taken for the CPU to complete the action
         * @param isrAddress - An integer stating the memory address in the vector table for the ISR.
        */
        void systemCall(int duration, int isrAddress);

        /**
         * This method is intended to be used to convert an integer to a hexidecimal string.
         * @param number - an integer that is the value needed to be converted.
         * @return the string containing a hexadecimal value
        */
        std::string integerToHexString(int number);

        /**
         * This method represents the CPU instruction that can be given from the trace.
         * @param duration - an integer representing the duration of the command.
        */
        void executeCPU(int duration);

        /**
         * This method is intended to process interrupts given by an I/O device connected to the CPU.
         * @param duration - an integer representing the duration of the command.
         * @param isrAddress - an integer representing the address of the ISR address in the vector table
        */
       void interrupt(int duration,int isrAddress);

       /**
        * This method is meant to be used to access the vector table given an address and will output the ISR address it found.
        * @param isrAddress - an integer representing the address of the ISR address in the vector table
       */
       void accessVectorTable(int isrAddress);

        /**
         * This method is used to call the appropriate function based on the instrcution given.
         * @param instruction - a instr struct that contains the command and any parameters it may have
        */
       //executeInstruction(instr instruction)

};

#endif