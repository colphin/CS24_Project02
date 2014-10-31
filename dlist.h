// dlist.h
// DO NOT CHANGE ANY PART OF THIS FILE

#ifndef DLIST_H
#define DLIST_H

#include <string>
using std::string;

// Exception types
class EmptyList { };
class BadIndex { };

class DList {

public:
    // parts already done for you - do not change the implementations
    DList() : first(0), last(0), size(0) { } // only ctor implemented here
    ~DList() { clear(); } // dtor implemented here depends on clear()
    void print() const; // implemented in dlist.cpp
    void rprint() const; // prints in reverse - implemented in dlist.cpp
    
    // parts you must implement in dlist.cpp
    void clear();
    int getSize() const;
    bool isEmpty() const;
    string get(int index) const;
    string getFirst() const;
    string getLast() const;
    DList head(int length) const;
    DList tail(int length) const;
    void insert (int index,  string obj);
    void addFirst(string obj);
    void addLast(string obj);
    string remove(int index);
    string removeFirst();
    string removeLast();
    void removeAllEqual(string obj);
    void reverse();
    bool contains(string obj) const;

private:
    // You must use the following struct in the implementation
    struct DLNode {
        string info;
        DLNode *prev; // points to previous node (is 0 if first node)
        DLNode *next; // points to next node (is 0 if last node)
        DLNode(string s) : info(s), prev(0), next(0) { } // ctor
    };
    
    // pointers to first and last node (both 0 only if list is empty)
    DLNode *first, *last;
    
    // number of items in the list
    int size;
};

#endif
