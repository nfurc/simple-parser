/*
 * parser.cpp
 *
 *  Created on: 26 Sept 2013
 *      Author: Nicholas
 */


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <map>
#include "classes.h"

using namespace std;

void instructions();
bool intcheck (const string& str);
bool spcheck (const string& str);
bool islegal (const string& str);
bool correctwords (vector<string>& vstrings, vector<string>& verbs, vector<string>& objects);

int main()
{
//vettore di possibili verbi
vector<string> verbs;
verbs.push_back("open");
verbs.push_back("examine");
verbs.push_back("take");
;


//vettore di possibili oggetti
vector<string> objects;
objects.push_back("book");
objects.push_back("door");
objects.push_back("lamp");
objects.push_back("body");

//linka parole a relativa classe
map<string, ActionHandler*> actionMap;

actionMap["take"] = new TakeActionHandler;
actionMap["examine"] = new ExamineActionHandler;
actionMap["open"] = new OpenActionHandler;

instructions();

string input;

do {

getline(cin, input);
transform(input.begin(), input.end(), input.begin(), ::tolower);
stringstream ss(input);
istream_iterator<string> begin(ss);
istream_iterator<string> end;
vector<string> vstrings(begin, end);

if ((islegal(input) == true) && (correctwords(vstrings, verbs, objects) == true)) {

		string obj = vstrings[1];
        ActionHandler* handler = actionMap[vstrings[0]];
        handler->doAction(obj);


} else {

	cout << "Illegal input." << endl;
}


} while (input != "quit");

cin.get();
cin.get();
return 0;

}


void instructions () {

cout << "Hello! Enter two words (hint: take, examine, open - book, lamp, door...).\n";
cout << "Type 'quit' to exit the program. \n\n";

}

bool intcheck (const string& str) {  //returns true if there's ints

if (str.find_first_of("0123456789")!= string::npos )
{
    return true;
} else {

    return false;
}

}

bool spcheck (const string& str) { //returns true if anything other than one whitespace

int i = 0;
int num = 0;
while (str[i])
{
    char c = str[i];
    if (isspace(c)) num++;
    i++;
}

if (num == 1)
{
    return false;
} else {
    return true;
}
}

bool islegal (const string& str) {

if (intcheck(str))
{
    cout << "Please don't put numbers in the thing" << endl;
    return false;
} else {

    if (spcheck(str))
    {
        cout << "Only two words separated by a space pls" << endl;
        return false;
    } else {
        return true;
    }
}

}

bool correctwords (vector<string>& vstrings, vector<string>& verbs, vector<string>& objects) {

	bool vrbchk;
	bool objchk;

	//compare verbs with first entered word
	if (find(verbs.begin(), verbs.end(), vstrings[0]) != verbs.end()) {

		vrbchk = true;

	} else {

		vrbchk = false;
	}


	//compare objects with second word

	if (find(objects.begin(), objects.end(), vstrings[1]) != objects.end()) {

		objchk = true;

	} else {

		objchk = false;
	}


	if (vrbchk && objchk) {
		return true;
	} else {
		return false;
	}
}


