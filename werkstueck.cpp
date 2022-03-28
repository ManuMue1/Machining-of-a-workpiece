//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 04.12.2021
// Author: MM
//------------------------------------------------------------------


#include <iostream>
#include "werkstueck.h"

using std::cout;
using std::endl;

Iterator Werkstueck::getNearest(IKomponente const* pk) const {
    Iterator nearest = komponenten.end();
    Iterator tmp = komponenten.begin();
    if(pk != nullptr && tmp != komponenten.end()){
        nearest = komponenten.begin();
        double min_dist = (*tmp)->distance(pk);
        ++tmp;
        while(tmp != komponenten.end()){
            if(min_dist > (*tmp)->distance(pk)){
                min_dist = (*tmp)->distance(pk);
                nearest = tmp;
            }
            ++tmp;
        }
    }
    return nearest;
}

void Werkstueck::add(IKomponente* k) {
    if(k){
        komponenten.push_back(k);
        k->setParent(this);
        pathIsOptimized = false;
    }
}

void Werkstueck::remove(IKomponente const* k) {
    Iterator I = Iterator(komponenten.begin());
    if(k){
        for(int x = 0; x < komponenten.size(); x++){
            if(*I == k){
                break;
            }
            ++I;
        }
        if(I != komponenten.end()){
            (*I)->setParent(nullptr);
            komponenten.erase(I);
            pathIsOptimized = false;
        }
    }
}

IKomponente const* Werkstueck::getChild(int i) const {
    Iterator I = komponenten.begin();
    for(int x = 0; x < i; x++){
        ++I;
    }
    return *I;
}

double Werkstueck::calcPathLength() const{
    Iterator I = komponenten.begin();
    double ret = 0;
    if(I != komponenten.end()){
        ret += (this)->distance(*(I));
    }
    for(int x = 0; x < komponenten.size()-1; x++){
        ret += (*I)->distance(*(++I));
    }
    if(I != komponenten.end()){
        ret += (this)->distance(*(I));
    }
    return ret;
}

double Werkstueck::calcTotalPath() const {
    double ret = 0.0;
    Iterator I = komponenten.begin();
    for(int i = 0; i < komponenten.size(); i++){
        ret += (*I)->calcTotalPath();
        if(i == komponenten.size()-1) {break;}
        ++I;
    }
    ret += calcPathLength();
    return ret;
}

void Werkstueck::optimizePath() {
    if (!pathIsOptimized && komponenten.size() > 0) {
        // first call optimizePath for all Components,
        // which are of type Werkstueck recursively
        Iterator it = komponenten.begin();
        while (it != komponenten.end()) {
        Werkstueck* w = dynamic_cast<Werkstueck*>(*it);
        if (w != nullptr) {
            w->optimizePath();
        }
        ++it;
    }
    // Now determine a nearest neighbour-sorting
    // of all components
        DeList komponentenSortiert;
        IKomponente* pcurrent = this;
        Iterator nearest = getNearest(pcurrent);
        komponentenSortiert.push_back(*nearest);
        pcurrent = *nearest;
        komponenten.erase(nearest);
        while (komponenten.size() > 0) {
            nearest = getNearest(pcurrent);
            komponentenSortiert.push_back(*nearest);
            pcurrent = *nearest;
            komponenten.erase(nearest);
        }
        komponenten = komponentenSortiert;
        pathIsOptimized = true;
    }
}

void Werkstueck::output(std::ostream& os) const {
    std::string blanks;
    IKomponente const* parent_new = getParent();
    while(parent_new!=nullptr){
        parent_new = parent_new->getParent();
        blanks += " ";
    }
    os << blanks << "Werkstueck: " << endl
       << blanks << "Verankerung: (" << getXAbsolute() << ", "
       << getYAbsolute() << ")"  << endl
       << blanks << "heigth: " << getHeight() << ", "
       << "width: " << getWidth() << endl
       << blanks << "Komponenten:" << endl;

    Iterator it = komponenten.begin();
        while (it != komponenten.end()) {
            if (dynamic_cast<Werkstueck*>(*it) == nullptr) {
                os << blanks;
            }
            os << *(*it);
            if (dynamic_cast<Werkstueck*>(*it) == nullptr) {
                os << endl;
            }
            ++it;
        }
}

Werkstueck::~Werkstueck(){}
