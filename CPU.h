#include <iostream>
#include <fstream>
using namespace std;

class CPU {

    private:

        //Member variables
        int clock; //Number of clock cycles
        bool kernelMode; // Whether or not the CPU is currently in kernel mode.
        int programCounter; // this is used to increment the counter
    
    
    public:

        CPU() {
            clock = 0;
            kernelMode = true;
        }

 
        /**
        * This method is intended to calculate the info to display based on the read from the sensor
        */
        // int calculate(int sensorInput) {

        // }

        /**
         * This method handles interrupts
        */
        // void handleInterrupt(int interruptNum) {

        // }

        /**
         * This method changes the kernelMode.
        */
        // void setKernelMode(bool mode) {
        //     kernelMode = mode;
        // }


        /**
         * This method fetches the kernelMode.
        */
        // bool isKernelMode() {
        //     return kernelMode;
        // }


    
        /**
         * Method used to write to the output file
        */
        void writeToFile();


        /**
         * This method is intended to be used for a system call - it checks the input device.
         * 
        */


        /**
         * This method is intended to be used to display information on the output device
        */

};
