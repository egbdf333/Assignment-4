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