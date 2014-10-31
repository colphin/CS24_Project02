// dlist.cpp - implements class DList
// Calvin Yin, Oct 27 2014

#include <iostream>
#include "dlist.h"

void DList::clear() {       //Works
    DLNode *q = first;
    while(q!=NULL){
        first = first->next;
        delete q;
        q = first;
    }
    first = last = NULL;
}

int DList::getSize() const {
    int sum = 0;
    DLNode *n = first;
    while (n){
        sum++;
        n = n->next;
    }
    return sum;
}

bool DList::isEmpty() const {
    return first == 0;
}

string DList::get(int index) const {        //WORKS
    if (first == 0){        //EMPTY LIST EXCEPTION
        std::cout << "FIRST MAKE A LIST"<<std::endl;
        return "";
    }
    
    DLNode *q;
    q = first;
    
    for (int i = 0;i < index - 1;i++){      //BAD ENTRY EXCEPTION
        q = q->next;
        if (q == NULL)
        {
            std::cout<<"There are less than ";
            std::cout<<index<<" elements."<<std::endl;
            return"";
        }
    }
    
    return q->info;     //IF ALL GOOD THEN RETURN QUERY
}

string DList::getFirst() const {    // WORKS
    return first->info;
}

string DList::getLast() const {     // WORKS 
    return last->info;
}

DList DList::head(int length) const {       // BROKEN
    DList sublist;
    /*
    DLNode *q = sublist.first;
    DLNode *n = first;
    for (int i = 0; i < length-1;i++){
        q = n->next;
        q = q->next;
        n = n->next;
    }
    return sublist;
    */
    
    DLNode *q = first;
    DLNode *n = sublist.first;
    
    n = new DLNode(q->info);
    for (int i = 0; i < length-1; i++) {
        DLNode *temp = new DLNode(q->next->info);
        n = temp;
        n = n->next;
    }
    return sublist;
}

DList DList::tail(int length) const {       //BROKEN
    DList sublist;
    DLNode *q = sublist.last;
    DLNode *n = last;
    for (int i = 0; i < length-1;i++){
        q->prev = n->prev;
        q = q->prev;
        n = n->prev;
    }
    return sublist;
}

void DList::insert(int index,  string obj) {        // WORKS
    if (first == NULL){
        std::cout<<"First Create the list."<<std::endl;
        return;
    }
    DLNode *tmp, *q;
    q = first;
    for (int i = 0;i < index - 1;i++){
        q = q->next;
        if (q == NULL)
        {
            std::cout<<"There are less than ";
            std::cout<<index<<" elements."<<std::endl;
            return;
        }
    }
    tmp = new DLNode(obj);      // to add at last item
    if (q->next == NULL){
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
        last = tmp;
    }else if(index == 0){
        tmp->next = first;
        tmp->prev = NULL;
        first = tmp;
    }
    else{                       // to add at middlem
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    std::cout<<"Element Inserted"<<std::endl;
}

void DList::addFirst(string obj) {          // WORKS

    DLNode *temp = new DLNode(obj);
    temp->prev = NULL;
    temp->next = first;
    first = temp;
    
    if (first->next == 0){
        last = temp;
    }
}

void DList::addLast(string obj){            // WORKS
    DLNode *temp = new DLNode(obj);
    temp->next =NULL;
    temp->prev = last;
    last = temp;
    
    if (last->prev == 0){
        first = temp;
    }
    if(last->prev != 0){
        last->prev->next = last;
    }
}

string DList::remove (int index) {      //BROKEN - won't actually delete
    if (first == NULL){
        std::cout<<"Empty List."<<std::endl;
        return "";
    }
    DLNode *q;
    q = first;
    for (int i = 0;i < index - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            std::cout<<"There are less than ";
            std::cout<<index<<" elements."<<std::endl;
            return "";
        }
    }
    if (q->next == NULL)
    {
        q->prev->next = 0;
        string temp = q->info;
        free(q);
        return temp;
    }
    else
    {
        string temp = q->info;
        q->prev = q->next;
        q->next->prev = q->prev;
        free(q);
        return temp;
    }
}

string DList::removeFirst () {      //WORKS
    if (first == 0){
        std::cout<<"Empty Set"<<std::endl;
        return "";
    }
    
    DLNode *q = first;
    first = first->next;
    string temp = q->info;
    delete q;
    
    return temp;
}

string DList::removeLast() {        //WORKS
    if (first == 0){
        std::cout<<"Empty Set"<<std::endl;
        return "";
    }
    
    DLNode *q = last;
    last = last->prev;
    last -> next = NULL;
    string temp = q->info;
    delete q;
    
    return temp;
}

void DList::removeAllEqual(string obj) {
    DLNode *temp, *q;
    if (first->info == obj){
        temp = first;
        first = first->next;
        first -> prev = 0;
        delete temp;
    }
    q = first;
    while (q->next->next != 0) {
        if (q->next->info == obj){
            temp = q->next;
            q->next = temp->next;
            temp->next->prev = 0;
            delete temp;
        }
        q=q->next;
    }
    
    if (q->next->info == obj) {
        temp = q -> next;
        delete temp;
        q->next = 0;
    }
    else{
        std::cout<<"Element not found"<<std::endl;
    }
}

void DList::reverse() {     //WORKS- don't have a clue as to why
    /*
    DLNode *p1, *p2;
    p1 = first;
    p2 = p1->next;
    p1 -> next = 0;
    p1 -> prev = p2;
    while(p2!=0){
        p2 -> prev = p2 -> next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->next;
    }
    */

    if(first == NULL){
        std::cout << "empty list" << std::endl;
    }else if (first->next == NULL){
        return;
    }else{
        DLNode *ptr = first;
        while (ptr != NULL) {
            DLNode *tmp = ptr->next;
            ptr->next = ptr->prev;
            ptr->prev = tmp;
            if (tmp == NULL) {
                last = first;
                first = ptr;
            }
            ptr = tmp;
        }
    }

}

bool DList::contains(string obj) const {        //BROKEN
    DLNode *n = first;
    while(n){
        if(n->info == obj){
            return true;
        }
        n = n->next;
    }
    return false;
}

//rprint doesn't work.

// DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
// print and rprint are already done.

void DList::print() const {
    DLNode *n = first;
    while (n) {
        std::cout << n->info;
        if (n->next)
            std::cout << ", ";
        n = n->next;
    }
}

void DList::rprint() const {
    DLNode *n = last;
    while (n) {
        std::cout << n->info;
        if (n->prev)
            std::cout << ", ";
        n = n->prev;
    }
}
