// Linus Pui | 301554378 | lpa44@sfu.ca

#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include <limits>
#include "a4_talklib.hpp"
#include "a4_talkList.hpp"
using namespace std;

Talk* createTalk(short hours, short minutes, short seconds, const std::string title, const std::string overview) {
    Talk* currentTalk = new Talk{hours, minutes, seconds, title, overview};
    return currentTalk;
}

void printTalk(const Talk* talk) {
    std::cout << talk->hours << 'h' << talk->minutes << "m" << talk->seconds << "s\n";
    std::cout << talk->title << '\n' << talk->overview << endl;
    std::cout << "================================\n";
}

bool compareTalksByDuration(const Talk* p1, const Talk* p2) {
    int talk1 = ((p1->hours * 60) + p1->minutes) * 60 + p1->seconds;
    int talk2 = ((p2->hours * 60) + p2->minutes) * 60 + p2->seconds;
    bool isGreater = false;
    if (talk2 > talk1) {
        isGreater = true;
    }
    return isGreater;
}

bool compareTalksByTitle(const Talk* p1, const Talk* p2) {
    std::string talk1 = p1->title;
    std::string talk2 = p2->title;
    bool isGreater = false;
    if (talk2 > talk1) {
        isGreater = true;
    }
    return isGreater;
}

void deleteTalk(Talk* talk) {
    if (talk != std::nullptr_t) {
        delete talk;
    }
}