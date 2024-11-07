#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> macros, definitions;

void pass1(const vector<string>& source) {
    bool inMacro = false;
    for (const auto& line : source) {
        stringstream ss(line);
        string word;
        ss >> word;
        if (word == "MACRO") {
            inMacro = true;
            string macroName;
            ss >> macroName;
            macros.push_back(macroName);
            definitions.push_back("");
        } else if (word == "MEND") {
            inMacro = false;
        } else if (inMacro) {
            definitions.back() += line + "\n";
        }
    }
}

void pass2(const vector<string>& source) {
    for (const auto& line : source) {
        stringstream ss(line);
        string word;
        ss >> word;
        bool isMacroCall = false;
        for (size_t i = 0; i < macros.size(); ++i) {
            if (word == macros[i]) {
                cout << "Expanding macro: " << macros[i] << "\n" << definitions[i];
                isMacroCall = true;
                break;
            }
        }
        if (!isMacroCall) cout << line << "\n";
    }
}

int main() {
    vector<string> source = {
        "MACRO INCR &ARG1", "ADD &ARG1, ONE", "MEND", 
        "MACRO DECR &ARG1", "SUB &ARG1, ONE", "MEND", 
        "START", "INCR A", "DECR B", "END"
    };
    
    pass1(source);  // First pass: Identify macros
    pass2(source);  // Second pass: Expand macros
    return 0;
}
