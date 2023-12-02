#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include <limits>
// #include <a4_talklib.hpp>
#include "a4_talkList.hpp"
using namespace std;

void printBanner() 
{
    std::cout << "| this is a fancy banner | wow so fancy | this is awesome! |\n| =-=-=-=-=-=-=- | CS Talks Lookup System | =-=-=-=-=-=-=- |\n| =-=-=-=-=-=-=-=-=-=-=-= | Linus | =-=-=-=-=-=-=-=-=-=-=- |\n| =-=-=-=-=-=-=-=-=-=-= | 301554378 | =-=-=-=-=-=-=-=-=-=- |\n| =-=-=-=-=-=-=-=-=-= | lpa44@sfu.ca | =-=-=-=-=-=-=-=-=-= |\n| wOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO |\n";
}

void printOptions() {
    std::cout << "-============================================================-\n";
    std::cout << "Press numbers 1-7 for the following options and then enter:\n";
    std::cout << "Option 1: Load a talks file\n";
    std::cout << "Option 2: List talks sorted by duration\n";
    std::cout << "Option 3: List talks sorted by title\n";
    std::cout << "Option 4: Look up a talk\n";
    std::cout << "Option 5: Add a talk\n";
    std::cout << "Option 6: Save a talks file\n";
    std::cout << "Option 7: Exit the program\n";
    std::cout << "Option: ";
}

int main() {
    printBanner();
    int optionNumber = 0;
    ifstream talksFile;
    string fileName;
    TalkList myTalks;


    // interface
    while (optionNumber != -1) {
        optionNumber = 0;
        printOptions();
        std::cin >> optionNumber;

        switch (optionNumber) {
            case 1: // load file
                if (talksFile.is_open()) {
                    // clear memory
                    talksFile.close();
                }
                std::cout << "Enter the full name of the file (with extension: abc.txt): ";
                std::cin >> fileName;
                if (fileName.empty()) {
                    std::cout << "Error in opening the file. Please check if it is available.\n";
                }
                else {
                    talksFile.open(fileName);
                    if (!talksFile.is_open()) {
                        std::cout << "Error in opening the file. Please check if it is available.\n";
                    }
                }

                myTalks.loadTalks(fileName);
                break;
            case 2: // sort by duration
                break;
            case 3: // sort by title
                break;
            case 4: // look up a talk
                break;
            case 5: // add a talk
                break;
            case 6: // save talks file to a file with name as input (can overwrite)
                break;
            case 7: // exit program, set optionNumber to 8
                std::cout << "Thank you for using the Talk Lookup System!\n";
                optionNumber = -1;
                break;
            default:
                std::cout << "Invalid input. Please try again\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    }

    talksFile.close();
    return 0;
}