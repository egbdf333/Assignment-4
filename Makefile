all: test1

test1: a4_talkLookupSystem.cpp a4_talklib.cpp a4_talkList.cpp
	g++ -Wall -std=c++11 -o test1 a4_talkLookupSystem.cpp a4_talklib.cpp a4_talkList.cpp

clean:
	rm -f test1
