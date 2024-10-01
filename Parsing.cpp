#include <string>
#include "Parsing.h"
#include "CPU.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace parsing
{
    namespace instructions {
        using namespace std;
        const string CPU = "CPU";
        const string SYSCALL = "SYSCALL";
        const string END_IO = "END_IO";
    }

    instr readFromTrace(std::ifstream* file)
    {
        std::string text;
        instr operation;

        if(!file->eof()){
            getline(*(file),text);
            for(int i = 0, len = text.size(); i < len; i++){
                if (text[i] == ','){
                    text.erase(i--, 1);
                    len = text.size();
                }
            }
            
            std::stringstream ss(text);
            int i = 0;
            std::string s;
            
            getline(ss,operation.argName,' ');// First parameter always command
            while (getline(ss,s,' ')) { //while for any args
                operation.args[i] = stoi(s);
                i++;
            }
        

        }
            
        else{
            file->close();
        }
        return operation;
    }

};


