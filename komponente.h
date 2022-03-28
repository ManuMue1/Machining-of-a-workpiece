//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 07.11.2021
// Author: MM
//------------------------------------------------------------------

#ifndef KOMPONENTE_H
#define KOMPONENTE_H
#include <iostream>
#include "ikomponente.h"

class Komponente : public IKomponente{
private:
    double x, y;
    IKomponente const* parent;
public:
    Komponente(double xPos = 0.0, double yPos = 0.0) : x{xPos}, y{yPos}, parent{nullptr} {
        if ( x < 0.0){
            x = 0.0;
        }
        if (y < 0.0){
            y = 0.0;
        }
    }
    double calcTotalPath() const override {return 0.0;}
    double getX() const override{return x;}
    double getY() const override{return y;}
    double getXAbsolute() const override;
    double getYAbsolute() const override;
    double distance(IKomponente const* k) const override;
    IKomponente const* getParent() const override {return parent;}
    void setParent(IKomponente const* p) override {parent = p;}
    virtual void output(std::ostream& os) const override;
    ~Komponente();
};

#endif // KOMPONENTE_H
