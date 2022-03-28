//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 04.12.2021
// Author: MM
//------------------------------------------------------------------


#ifndef DELIST_H
#define DELIST_H

#include <iostream>
#include "ikomponentenelement.h"
#include "iterator.h"

class DeList {
private:
    int counter;
    IKomponentenElement* first;
    IKomponentenElement* getElement(Iterator it) const;
public:
    DeList() : counter{0}, first{nullptr} {};

    DeList(DeList const& rhs);

    DeList& operator=(DeList const& rhs);

    void clear();
    int size() const {return counter;}
    Iterator erase(Iterator pos);
    void push_back(IKomponente* k);
    Iterator end() const {return Iterator();}
    Iterator begin() const {return Iterator(first);}
    ~DeList() {clear();}
};

#endif // DELIST_H
