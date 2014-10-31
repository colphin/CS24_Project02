// listtester.cpp - tests class DList
// Use AS-IS for CS 24 Project 2
// cmc, 10/22/2014

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "dlist.h"

// utility functions defined below main:
bool blank(string const &);
bool eq(string, char const *);
string yesno(bool);

int main() {
    DList list;
    string line, word;
    int index;

    while ( getline(cin, line) ) {
        if (blank(line)) // skip blank lines
            continue;

        istringstream parser(line);
        string cmnd;
        parser >> cmnd;
        
        if (cmnd.at(0) == '#') // skip comments
            continue;
        
        if (eq(cmnd, "quit"))
            return 0;

        if (eq(cmnd, "get") || eq(cmnd, "head")
            || eq(cmnd, "tail") || eq(cmnd, "insert")
            || eq(cmnd, "remove")) { // read index
            parser >> index;
            if (parser.fail()) {
                cout << "missing or bad index" << endl;
                continue;
            }
        }
        if (eq(cmnd, "addFirst") || eq(cmnd, "addLast")
            || eq(cmnd, "insert") || eq(cmnd, "contains")
            || eq(cmnd, "removeEqual")) {
            parser >> word;
            if (parser.fail()) {
                cout << "missing word" << endl;
                continue;
            }
        }

        try {
            if (eq(cmnd, "print")) {
                cout << "List contents: ";
                list.print();
                cout << endl;
            }
            else if (eq(cmnd, "printReverse")) {
                cout << "Reversed contents: ";
                list.rprint();
                cout << endl;
            }
            else if (eq(cmnd, "clear")) {
                cout << "clear list: ";
                list.clear();
                cout << "okay" << endl;
            }
            else if (eq(cmnd, "size")) {
                cout << "size: ";
                cout << list.getSize() << endl;
            }
            else if (eq(cmnd, "reverse")) {
                cout << "reversing list: ";
                list.reverse();
                cout << "okay" << endl;
            }
            else if (eq(cmnd, "get")) {
                cout << "get from index " << index << ": ";
                cout << list.get(index) << endl;
            }
            else if (eq(cmnd, "first")) {
                cout << "first: ";
                cout << list.getFirst() << endl;
            }
            else if (eq(cmnd, "last")) {
                cout << "last: ";
                cout << list.getLast() << endl;
            }
            else if (eq(cmnd, "head")) {
                cout << "first " << index << " elements: ";
                list.head(index).print();
                cout << endl;
            }
            else if (eq(cmnd, "tail")) {
                cout << "last " << index << " elements: ";
                list.tail(index).print();
                cout << endl;
            }
            else if (eq(cmnd, "insert")) {
                cout << "insert " << word << " at position " << index << ": ";
                list.insert(index, word);
                cout << "okay" << endl;
            }
            else if (eq(cmnd, "addFirst")) {
                cout << "add " << word << " first: ";
                list.addFirst(word);
                cout << "okay" << endl;
            }
            else if (eq(cmnd, "addLast")) {
                cout << "add " << word << " last: ";
                list.addLast(word);
                cout << "okay" << endl;
            }
            else if (eq(cmnd, "remove")) {
                cout << "remove from position " << index << ": ";
                cout << list.remove(index) << endl;
            }
            else if (eq(cmnd, "removeFirst")) {
                cout << "remove first: ";
                cout << list.removeFirst() << endl;
            }
            else if (eq(cmnd, "removeLast")) {
                cout << "remove last: ";
                cout << list.removeLast() << endl;
            }
            else if (eq(cmnd, "removeEqual")) {
                cout << "remove all equal to " << word << ": ";
                list.removeAllEqual(word);
                cout << "okay" << endl;
            }
            else if (eq(cmnd, "contains")) {
                cout << "contains " << word << ": ";
                cout << (list.contains(word) ? "yes" : "no") << endl;
            }
            else
                cout << "bad command: " << cmnd << endl;
        }
        catch(EmptyList e) {
            cout << "empty list exception" << endl;
        }
        catch(BadIndex e) {
            cout << "bad index exception" << endl;
        }
    }
}

// utility returns true if s is all white space
bool blank(string const &s) {
    for (size_t i = 0; i < s.size(); i++) {
        char c = s.at(i);
        if (!isspace(c))
            return false;
    }
    return true;
}
    
// utility simplifies string comparison
bool eq(string s1, char const *s2) {
    for (size_t i = 0; i < s1.size(); i++)
        s1.at(i) = tolower(s1.at(i));
    string s2copy(s2);
    for (size_t i = 0; i < s2copy.size(); i++)
        s2copy.at(i) = tolower(s2copy.at(i));
    return s1 == string(s2copy);
}

// utility returns "yes" if answer is true, or "no" otherwise
string yesno(bool answer) {
    if (answer) return string("yes");
    return string("no");
}
