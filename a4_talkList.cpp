// Linus Pui | 301554378 | lpa44@sfu.ca

#include <limits>
#include <iostream>
#include <string>
#include <fstream>
#include "a4_talkList.hpp"
// #include "a4_talklib.hpp"

// constructor
TalkList::TalkList() {

}

// destrctor
TalkList::~TalkList() {

}

//return the size of the list (i.e., number of talks)
int TalkList::getSize() {
    int size;
    size = talkEntries.size();
    return size;
}

//list talks sorted by duration
void TalkList::listTalksByDuration() {
    sort(talkEntries.begin(), talkEntries.end(), compareTalksByDuration);
    int counter = 1;
    for (Talk* talk : talkEntries) {
        std::cout << "Talk #" << counter << '\n';
        printTalk(talk);
        counter++;
    }
}

//list talks sorted by title
void TalkList::listTalksByTitle() {
    sort(talkEntries.begin(), talkEntries.end(), compareTalksByTitle);
    int counter = 1;
    for (Talk* talk : talkEntries) {
        std::cout << "Talk #" << counter << '\n';
        printTalk(talk);
        counter++;
    }
}

//create and insert a Talk entry to the list
void TalkList::insertTalk(short hours, short minutes, short seconds, const std::string title, const std::string overview) {

    
}

//list talks that have title containing the keyTitle as substring
void TalkList::listTalksContainingTitle(const std::string keyTitle) {
    int counter = 1;
    for (Talk* talk : talkEntries) {
        if (talk->title.find(keyTitle) != std::string::npos) {
            std::cout << "Talk #" << counter << '\n';
            printTalk(talk);
            counter++;
        }
    }
    if (counter == 1) {
        std::cout << "No such talk on record.\n";
    }
}

//save all the talks into a file using the sample format
void TalkList::saveTalksToFile(const std::string filename) {
    
}

void TalkList::clearVector() {
    talkEntries.clear();
}

void TalkList::loadTalks(std::string filename) {
    int hours;
    int minutes;
    int seconds;
    int result;
    string title;
    string overview;
    std::ifstream myFile(filename);

    while(myFile) {
        //line 1
        myFile.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
        myFile >> hours;
        myFile.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        myFile >> minutes;
        myFile.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        myFile >> seconds;
        myFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // line 2
        myFile.ignore(std::numeric_limits<std::streamsize>::max(), '\"');
        getline(myFile, title, '\"');
        //line 3
        myFile.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
        getline(myFile, overview, '\n');
        //skip line 4
        myFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Talk* myTalk = createTalk(hours, minutes, seconds, title, overview);
        talkEntries.push_back(myTalk);
    }
    //handles issue with the last talk being pushed into the vector twice
    talkEntries.pop_back();
}

