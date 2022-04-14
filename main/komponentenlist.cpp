//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 07.11.2021
// Author: MM
//------------------------------------------------------------------


#include <iostream>
#include "komponentenlist.h"
#include <stdexcept>

KomponentenElement* KomponentenList::getElement(int pos)const{
    KomponentenElement* curr = first;
    if ((counter == 0) || (pos+1 <= 0) || (pos+1 > counter)){
        curr = nullptr;
    }
    else {
        for(int i = 0; i < pos && curr; i++){
            curr = curr->next;
        }
    }
    return curr;
}

Komponente const* KomponentenList::at(int pos) const{
        KomponentenElement* pc = getElement(pos);
        Komponente* tmp = nullptr;
        if (pc != nullptr){
            tmp = pc->k;
        }
        return tmp;
}

int KomponentenList::erase(int pos) {
    double erg = 0;
    KomponentenElement* tmp = getElement(pos);
    if(tmp != nullptr){

        KomponentenElement* after = tmp->next;
        KomponentenElement* prev = tmp->before;
        if (counter == 1){
            first = nullptr;
        } else {

        if (prev != nullptr && after != nullptr){
            after->before = prev;
            prev->next = after;
        } else if (prev == nullptr && after != nullptr) {
            after->before = prev;
            first = tmp->next;
        } else if (prev != nullptr && after == nullptr){
            prev->next = after;
            }
        }

        delete tmp;
        tmp = nullptr;
        --counter;
        erg = pos;

    } else {erg = -1;}
    return erg;
}

void KomponentenList::push_back(Komponente* k){
    KomponentenElement* newElement = new KomponentenElement;
    newElement->next = end();
    newElement->before = nullptr;
    newElement->k = k;
    if(first == end()) {
        first = newElement;
    } else {
        KomponentenElement* prev = getElement(counter-1);
        newElement->before = prev;
        prev->next = newElement;
    }
    ++counter;
}

KomponentenList::~KomponentenList() {
    KomponentenElement* tmp = nullptr;
    while (first != end()){
        tmp = first->next;
        delete first;
        first = tmp;
    }
    counter = 0;
}
