#include <iostream>
#include <fstream>
using namespace std;

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
        */
        bool isKernelMode();

        /**
         * Method used to write to the output file
        */
        void writeExecutionStep(int duration, std::string eventType);

        /**
         * This method is intended to be used for a system call - it checks the input device.
        */
        void systemCall(int duration, int isrAddress);

        /**
         * This method is intended to be used to display information on the output device
        */

};
