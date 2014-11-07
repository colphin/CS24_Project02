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
    if (isEmpty()){        //EMPTY LIST EXCEPTION
        throw EmptyList();
    }
    if (index<0){
        throw BadIndex();
    }
    
    DLNode *q;
    q = first;
    
    for (int i = 0;i < index - 1;i++){      //BAD ENTRY EXCEPTION
        q = q->next;
        if (q == NULL)
        {
            throw BadIndex();
        }
    }
    
    return q->info;     //IF ALL GOOD THEN RETURN QUERY
}

string DList::getFirst() const {    // WORKS
    if (isEmpty()){        //EMPTY LIST EXCEPTION
        throw EmptyList();
    }
    return first->info;
}

string DList::getLast() const {     // WORKS 
    if (isEmpty()){        //EMPTY LIST EXCEPTION
        throw EmptyList();
    }
    return last->info;
}

DList DList::head(int length) const {       // Works
    DList sublist;
    DLNode *main_n = first;
    if (length == 0 || isEmpty())
        return sublist;

    sublist.first = new DLNode(first->info);
    DLNode *n = sublist.first;
    for (int i = 0; i < length-1;i++){
        n->next = new DLNode(main_n->next->info);
        n = n->next;
        main_n = main_n -> next;
    }


    return sublist;
}

DList DList::tail(int length) const {       //WORKS
    DList sublist;
    DLNode *main_n = last;
    if (length == 0 || isEmpty())
        return sublist;

    sublist.last = new DLNode(last->info);
    DLNode *n = sublist.last;
    for (int i = 0; i < length-1;i++){
        n->prev = new DLNode(main_n->prev->info);
        DLNode *temp = n;
        n = n->prev;
        n->next = temp;

        //std::cout<<n->info<<std::endl;
        //std::cout<<temp->info<<std::endl;

        //delete temp;
        main_n = main_n -> prev;
    }
    sublist.first = n;
    //std::cout <<"reverse: ";
    //sublist.print();

    return sublist;
}

void DList::insert(int index,  string obj) {        // WORKS
    if (isEmpty()){        //EMPTY LIST EXCEPTION
        throw EmptyList();
    }
    DLNode *tmp, *q;
    q = first;
    for (int i = 0;i < index - 1;i++){
        q = q->next;
        if (q == NULL)
        {
            throw BadIndex();
        }
    }
    tmp = new DLNode(obj);      // to add at last item
    if (q->next == NULL){
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
        last = tmp;
    }else if(index == 0){       // to add to start
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
}

void DList::addFirst(string obj) {          // WORKS

    DLNode *temp = new DLNode(obj);
    temp->prev = NULL;
    temp->next = first;
    first = temp;
    
    if (first->next == 0){
        last = temp;
    }

    if (first ->next != 0){
        first -> next -> prev = first;
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

string DList::remove (int index) {      //Works...I think
    DLNode *q = first;

    if (isEmpty()){        //EMPTY LIST EXCEPTION
        throw EmptyList();
    }

    for(int i = 0; i <index-1; i++){
        q = q-> next;
        if (q == NULL){
            throw BadIndex();
        }
    }

    string temp = q->info;
    if (index == 1){        //START
        first = first -> next;
        delete q;
    }

    else if (q->next == NULL){       //END
        DLNode *temp = q;
        q->prev->next = NULL;
        delete temp;
    }
    else{                   //MIDDLE
        DLNode *temp = q;
        q->prev->next = temp -> next;
        q -> next-> prev = temp-> prev;
        delete temp;
        //delete q;
    }

    return temp;
}

string DList::removeFirst () {      //WORKS
    if (isEmpty()){        //EMPTY LIST EXCEPTION
        throw EmptyList();
    }
    
    DLNode *q = first;
    first = first->next;
    string temp = q->info;
    delete q;
    
    return temp;
}

string DList::removeLast() {        //WORKS
    if (isEmpty()){        //EMPTY LIST EXCEPTION
        throw EmptyList();
    }
    
    DLNode *q = last;
    last = last->prev;
    last -> next = NULL;
    string temp = q->info;
    delete q;
    
    return temp;
}

void DList::removeAllEqual(string obj) {        //WORKS
    DLNode *q = first;
    while (q) {
        if (q==first && q->info == obj){        //START
            //std::cout<< "\n BEG:";
            //print();
            DLNode *head_temp = q;
            first = first -> next;
            delete head_temp;
            q = first;
            //std::cout<< "\n-BEG:";
            //print();
        }
        else if (q->next == NULL && q->info == obj){       //END
            //std::cout<< "\n END:";
            //print();
            removeLast();
            //std::cout<< "\n-END:";
            //print();
            return;
        }
        else if ( q->info == obj){                   //MIDDLE
            //std::cout<< "\n MID:";
            //print();
            DLNode *temp = q;
            q->prev->next = temp -> next;
            q -> next-> prev = temp-> prev;
            delete temp;
            q = first;
            //std::cout<< "\n-MID:";
            //print();
        }else{
            q = q->next;
        }
    }
}

void DList::reverse() {     //WORKS

    if (isEmpty()) {
        return;
    }
    if (first->next == 0 || first == 0){
        return;
    }else{
        DLNode *ptr = first;
        while (ptr != 0) {
            DLNode *tmp = ptr->next;
            ptr->next = ptr->prev;
            ptr->prev = tmp;
            if (tmp == 0) {
                last = first;
                first = ptr;
            }
            ptr = tmp;
        }
    }

}

bool DList::contains(string obj) const {        //WORKS
    DLNode *n = first;
    while(n){
        if(n->info == obj){
            return true;
        }
        n = n->next;
    }
    return false;
}


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
