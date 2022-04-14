//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 04.12.2021
// Author: MM
//------------------------------------------------------------------


#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include "ikomponentenelement.h"
#include "delist.h"

class Iterator {
private:
    IKomponentenElement* curr;
public:
    explicit Iterator(IKomponentenElement* begin = nullptr) : curr{begin} {};

    Iterator& operator++() {
        curr = curr->next;
        return *this;
    }
    bool operator!=(Iterator const& it) const{
        return !(it.curr == curr);
    }
    bool operator==(Iterator const& it) const{
        return it.curr == curr;
    }
    IKomponente* operator*() const{
        return curr->k;
    }
    ~Iterator(){};
};

#endif // ITERATOR_H
