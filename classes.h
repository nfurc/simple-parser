/*
 * classes.h
 *
 *  Created on: 5 Oct 2013
 *      Author: Nicholas
 */

#ifndef CLASSES_H_
#define CLASSES_H_

using namespace std;

class ActionHandler {
public:

    virtual void doAction(string obj) = 0;
};


class ExamineActionHandler : public ActionHandler {
public:

    virtual void doAction(string obj) {

    	if (obj == "book")
    	{
        cout << "You open the book and find that all pages are empty." << endl;
    	}
    	else if (obj == "door")
    	{
    	cout << "The door is locked. There is no escape." << endl;
    	}
    	else if (obj == "lamp")
    	{
    	cout << "The lamp is off." << endl;
    	}
    	else if (obj == "body")
    	{
    	cout << "There is a shrivelled, mummified body in the corner." << endl;
    	 }
    }
};

class TakeActionHandler : public ActionHandler {
public:

    virtual void doAction(string obj) {
    	if (obj == "book")
    	    	{
    	        cout << "You have taken the book." << endl;
    	        //add book to player's inventory
    	        //remove book from room
    	    	}
    	    	else if (obj == "door")
    	    	{
    	    	cout << "You can't take the door, silly!" << endl;
    	    	}
    	    	else if (obj == "lamp")
    	    	{
    	    	cout << "And how exactly would you carry a lamp around?" << endl;
    	    	}
    	    	else if (obj == "body")
    	    	{
    	    	cout << "Taking a body might be a bit encumbering." << endl;
    	    	 }
    }
};

class OpenActionHandler : public ActionHandler {
public:

    virtual void doAction(string obj) {
    	if (obj == "book")
    	    	{
    	        cout << "You go through the book, but there is nothing inside." << endl;
    	    	}
    	    	else if (obj == "door")
    	    	{
    	    	cout << "Unfortunately, the door is locked." << endl;
    	    	}
    	    	else if (obj == "lamp")
    	    	{
    	    	cout << "You don't have the tools to take a lamp apart." << endl;
    	    	}
    	    	else if (obj == "body")
    	    	{
    	    	cout << "That's a bit gross." << endl;
    	    	 }
    }
};

#endif /* CLASSES_H_ */
