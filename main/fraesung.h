//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 07.11.2021
// Author: MM
//------------------------------------------------------------------

#ifndef FRAESUNG_H
#define FRAESUNG_H
#include <iostream>
#include "bohrung.h"

class Fraesung : public Bohrung {
private:
    double length;
    double angle;
public:
    Fraesung(double x, double y, double diam, double l, double a = 0.0) : Bohrung{x, y, diam}, length{l}, angle{a} {
        if(angle<0){angle=0;}
        if(length<0){length=0.0;}
    }
    double calcTotalPath() const override {return 2 * length;}
    double getLength()const{return length;}
    double getAngle()const{return angle;}
    double getEndX()const;
    double getEndY()const;
    void output(std::ostream& os) const override;
    ~Fraesung();
};

#endif // FRAESUNG_H
