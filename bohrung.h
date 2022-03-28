//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 07.11.2021
// Author: MM
//------------------------------------------------------------------

#ifndef BOHRUNG_H
#define BOHRUNG_H
#include <iostream>
#include "komponente.h"

class Bohrung : public Komponente {
private:
    double diameter;
public:
    Bohrung(double x_ = 0.0, double y_ = 0.0, double diam = 6.0) : Komponente{x_, y_}, diameter{diam} {
        if (diameter <= 0.0) { diameter = 6.0;}
    };
    double getDiameter() const{return diameter;}
    void output(std::ostream& os) const ;
    ~Bohrung() {}
};

#endif // BOHRUNG_H
