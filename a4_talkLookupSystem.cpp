// Linus Pui | 301554378 | lpa44@sfu.ca

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
    int talkSize = sizeof(Talk);
    std::cout << talkSize << endl;
    printBanner();
    int optionNumber = 0;

    std::string fileName;
    TalkList myTalks;
    int numberOfTalks;
    std::string searchTitle;
    short hours;
    short minutes;
    short seconds;
    std::string title;
    std::string overview;
    std::string newFileName;

    // interface
    while (optionNumber != -1) {
        optionNumber = 0;
        printOptions();
        std::cin >> optionNumber;

        switch (optionNumber) {
            case 1: // load file
            {
                std::cout << "Enter the full name of the file (with extension: abc.txt): ";
                std::cin >> fileName;
                if (fileName.empty()) {
                    std::cout << "Error in opening the file. Please check if it is available.\n";
                }
                std::ifstream myFile(fileName);
                if (!myFile) {
                    std::cerr << "Error in opening the file. Please check if it is available.\n";
                }
                myTalks.clearVector();
                myTalks.loadTalks(fileName);
                numberOfTalks = myTalks.getSize();
                std::cout << numberOfTalks << " entries loaded.\n";
                myFile.close();
                break;
            }

            case 2: // sort by duration
                if (numberOfTalks == 0) {
                    std::cerr << "No file/entries loaded.\n";
                    break;
                }
                myTalks.listTalksByDuration();
                break;

            case 3: // sort by title
                if (numberOfTalks == 0) {
                    std::cerr << "No file/entries loaded.\n";
                    break;
                }
                myTalks.listTalksByTitle();
                break;
                
            case 4: // look up a talk
                if (numberOfTalks == 0) {
                    std::cerr << "No file/entries loaded.\n";
                    break;
                }
                std::cout << "What is the title of the talk, enter in part or as a whole (50 characters max.)? ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(std::cin, searchTitle);
                myTalks.listTalksContainingTitle(searchTitle);
                break;

            case 5: // add a talk
                while (true) {
                    std::cout << "What is the number of hours (input 0 or more and press enter)? ";
                    std::cin >> hours;   
                    if (hours < 0) {
                        std::cout << "Invalid input.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else {
                        break;
                    }                 
                }
                std::cout << endl;
                while (true) {
                    std::cout << "What is the number of minutes (input 0-59 and press enter)? ";
                    std::cin >> minutes;   
                    if (minutes < 0 || minutes > 60) {
                        std::cout << "Invalid input.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else {
                        break;
                    }                 
                }
                std::cout << endl;
                while (true) {
                    std::cout << "What is the number of seconds (input 0-59 and press enter)? ";
                    std::cin >> seconds;   
                    if (seconds < 0 || seconds > 60) {
                        std::cout << "Invalid input.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else {
                        break;
                    }                 
                }
                std::cout << endl;
                std::cout << "What is the title of the talk? ";
                std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, title);
                std::cin.clear();
                std::cout << "What is the overview of the talk? ";
                getline(cin, overview);
                std::cin.clear();
                myTalks.insertTalk(hours, minutes, seconds, title, overview);
                break;

            case 6: // save talks file to a file with name as input (can overwrite)
            {
                std::cout << "Enter the full name of the save file (with extension): ";
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(std::cin, newFileName);
                cin.clear();
                ofstream toFile(newFileName);
                if (!toFile) {
                    std::cerr << "Error in opening the file. Please check if it is available.\n";
                    break;
                }
                else {
                    myTalks.saveTalksToFile(newFileName);
                    toFile.close();
                }
                break;
            }
            case 7: // exit program, set optionNumber to -1
            {
                std::cout << "Thank you for using the Talk Lookup System!\n";
                myTalks.~TalkList();
                bool vectorEmpty = myTalks.vectorEmpty();
                std::cout << vectorEmpty;

                optionNumber = -1;
                break;
            }
            default:
                std::cout << "Invalid input. Please try again\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    }
    

    
    return 0;
}