//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 07.11.2021
// Author: MM
//------------------------------------------------------------------

#include "komponente.h"
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

Komponente::~Komponente(){}
void Komponente::output(std::ostream& os) const{
    os <<"(" << getX() << ", " << getY() << ")";
}

double Komponente::getXAbsolute() const {
    double x1 = 0.0;
    if (parent != nullptr){
        x1 = parent->getXAbsolute();
    }
    return x + x1;
};

double Komponente::getYAbsolute() const {
    double y1 = 0.0;
    if (parent != nullptr){
        y1 = parent->getYAbsolute();
    }
    return y + y1;
};

double Komponente::distance(IKomponente const* k) const {

    double dx = k->getXAbsolute() - this->getXAbsolute();
    double dy = k->getYAbsolute() - this->getYAbsolute();
    return std::sqrt(std::pow(dx, 2)+std::pow(dy, 2));
}
