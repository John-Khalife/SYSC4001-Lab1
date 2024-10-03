/**
 * This is the file used to create the test case trace files.
 * @date October 3rd, 2024
 * @author John Khalife, Stavros Karamalis
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>


// If ever a new instruction needs to be added - add the equivalent string here
namespace orders {
    using namespace std;
    const string CPU = "CPU";
    const string SYSCALL = "SYSCALL";
    const string END_IO = "END_IO";
}

int main(int argc, char* argv[]){

    if (argc > 3) {
        std::cout << "There are too many parameters." << std::endl;
        return 1;
    }

    int numTraces = atoi(argv[1]); //Represents how many trace files we want to make.
    int loopNum = atoi(argv[2]); //Represents how many instructions each trace file will have.
    int j; //Keeps track of which type of instruction should come next in the trace file.

    std::string nameFile;

    srand((unsigned) time(NULL));

    for(int i = 1; i <= numTraces; i++) //Create a set amount of trace files determined by the value of numTraces.
    {
        nameFile = "testTrace" + std::to_string(i) + ".txt"; //Creates a new file name for each trace file.
        std::ofstream outfile (nameFile); //Creates a new empty file for our trace.

        srand((unsigned) time(NULL));
    
        loopNum = 75 + (rand() % 75); //Randomizes how many instructions will be in each trace file.

        for(j = 0; j < loopNum; j++) //Writes the instructions in the trace file
        {
            outfile << orders::CPU << ", " << rand() % 100 << std::endl;

            if (j == 2){
                outfile << orders::SYSCALL << " " << rand() % 27 << ", " << 100 + (rand() % 301)<< std::endl;
            }
            else if (j == 1){
                outfile << orders::END_IO << " " << rand() % 27 << ", " << 100 + (rand() % 301)<< std::endl;
            }
        }

        if (j % 2 != 0)
        {
            outfile << orders::END_IO << " " << rand() % 27 << ", " << 100 + (rand() % 301)<< std::endl;
        }
        
        outfile << orders::CPU << ", " << rand() % 100 << std::endl; //Last instruction

        outfile.close(); //Closes the trace file.
    }

    return 0;
        
        
}