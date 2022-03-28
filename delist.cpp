//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 04.12.2021
// Author: MM
//------------------------------------------------------------------


#include <iostream>
#include "delist.h"

DeList::DeList(DeList const& rhs){
    counter = 0;
    Iterator rhs_i{rhs.begin()};
    while (rhs_i != rhs.end()) {
        this->push_back(*rhs_i);
        ++rhs_i;
    }
}

DeList& DeList::operator=(DeList const& rhs){
    if (this != &rhs){
        clear();
        Iterator rhs_i{rhs.begin()};
        while(rhs_i != rhs.end()){
            this->push_back(*rhs_i);
            ++rhs_i;
        }
    }
    return *this;
}

IKomponentenElement* DeList::getElement(Iterator it) const {
    IKomponentenElement* curr = first;
    IKomponentenElement* ret = nullptr;
    for(int i = 0; i < counter; i++){
        if(Iterator(curr)==it){
            ret = curr;
            break;
        }
        else {
            curr = curr->next;
        }
    }
    return ret;
}

Iterator DeList::erase(Iterator pos) {
    Iterator erg{};
    IKomponentenElement* tmp = getElement(pos);
    if(tmp != nullptr){

        IKomponentenElement* after = tmp->next;
        IKomponentenElement* prev = tmp->before;
        if (counter == 1){
            first = nullptr;
        } else {

        if (prev != nullptr && after != nullptr){
            after->before = prev;
            prev->next = after;
            erg = ++pos;
        } else if (prev == nullptr && after != nullptr) {
            after->before = prev;
            first = tmp->next;
            erg = ++pos;
        } else if (prev != nullptr && after == nullptr){
            prev->next = after;
            erg = end();
            }
        }
        delete tmp;
        tmp = nullptr;
        --counter;
    }
    return erg;
}

void DeList::push_back(IKomponente* k){
    IKomponentenElement* newElement = new IKomponentenElement;
    if(counter > 0){
        Iterator last {first};
        for(int i = 1; i < counter; i++){
            ++last;
            }
        newElement->before = getElement(last);
        getElement(last)->next = newElement;
     } else {
        newElement->before = nullptr;
        first = newElement;
    }
    newElement->next = nullptr;
    newElement->k = k;
    ++counter;
}

void DeList::clear(){
    IKomponentenElement* tmp = nullptr;
    while (begin() != end()){
        tmp = first->next;
        delete first;
        first = nullptr;
        first = tmp;
    }
    counter = 0;
}










