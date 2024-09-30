/**
 * This file contains the declarations and descriptions of methods belonging
 * to the CPU class.
 * @date September 30th, 2024
 * @author John Khalife, Stavros Karamalis
 * 
*/

#ifndef __CPU_H__
#define __CPU_H__

//dependencies
#include <iostream>
#include <fstream>

class CPU {

    private:

        //Member variables
        int clock; //Number of clock cycles
        bool kernelMode; // Whether or not the CPU is currently in kernel mode.
        int programCounter; // Used to increment the counter
        int time; //used to keep track of time
    
    public:

        /**
        * Constructor of the CPU class.
        */
        CPU() {
            clock = 0;
            time = 0;
            programCounter = 0;
            kernelMode = true;
        }

        /**
         * This method changes the kernelMode.
        */
        void switchCPUMode();

        /**
         * This method fetches the kernelMode.
         * @return A boolean that states if the CPU is in kernel mode.
        */
        bool isKernelMode();

        /**
         * Method used to write CPU events to the output file
         * @param duration - An integer stating the time taken for the CPU to complete the action
         * @param eventType - A string dictating the action of the CPU
         * 
        */
        void writeExecutionStep(int duration, std::string eventType);

        /**
         * This method is intended to be used for a system call - it checks the input device.
         * @param duration - An integer stating the time taken for the CPU to complete the action
         * @param isrAddress - An integer stating the memory address in the vector table for the ISR.
        */
        void systemCall(int duration, int isrAddress);

        /**
         * This method is intended to be used to convert an integer to a hexidecimal string.
         * @param number - an integer that is the value needed to be converted.
         * @return the string containing a hexadecimal value
        */
        std::string integerToHexString(int number);

        void callISR(int );

        /**
         * This method is intended to be used to display information on the output device
        */

};

#endif