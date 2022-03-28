//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 07.11.2021
// Author: MM
//------------------------------------------------------------------

#include "fraesung.h"
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

double Fraesung::getEndX() const{
    double ankatete = (cos(getAngle())) * getLength();
    double erg = getX() + ankatete;
    return erg;
}

double Fraesung::getEndY()const {
    double gegenkatete = (sin(getAngle())) * getLength();
    double erg = getY() + gegenkatete;
    return erg;
}

void Fraesung::output(std::ostream& os) const{
    os << "Fraesung mit Start: ";
    Komponente::output(os);
    os << " und Endpunkt: (" << getEndX() << ", " << getEndY() << ")"
       << ", Durchmesser: " << getDiameter();
}

Fraesung::~Fraesung(){}
