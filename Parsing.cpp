#include <string>
#include "Parsing.h"
#include "CPU.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace parsing
{
    instr* readFromTrace(std::ifstream* file)
    {
        instr* operation = new instr();
        if (!file->eof()) {
            std::string text;
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
            getline(ss,operation->argName,' ');// First parameter always command
            while (getline(ss,s,' ')) { //while for any args
                operation->args[i] = stoi(s);
                i++;
            }
        } else {
            file->close();
        }
        return operation;
    }

    std::string integerToHexString(int number) {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << std::hex << number;
    return "0x" + ss.str();
}
};


