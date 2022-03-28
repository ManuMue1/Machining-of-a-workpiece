//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 04.12.2021
// Author: MM
//------------------------------------------------------------------


#ifndef WERKSTUECK_H
#define WERKSTUECK_H

#include <iostream>
#include "komponente.h"
#include "delist.h"
#include "iterator.h"

class Werkstueck : public Komponente {
private:
    double height;
    double width;
    bool pathIsOptimized;
    DeList komponenten;
    Iterator getNearest(IKomponente const* pk) const;
public:
    Werkstueck(double xPos = 0.0, double yPos = 0.0, double h = 1, double w = 1) :
        Komponente{xPos, yPos}, height{h}, width{w}, pathIsOptimized{false} {
        if (h < 0) {height = 1.0;}
        if (w < 0) {width = 1.0;}
    }
    double getHeight() const {return height;}
    double getWidth() const {return width;}
    void add(IKomponente* k);
    void remove(IKomponente const* k);
    IKomponente const* getChild(int i) const;
    double calcTotalPath() const override;
    double calcPathLength() const ;
    void optimizePath();
    void output(std::ostream& os) const override;
    ~Werkstueck();
};

#endif // WERKSTUECK_H
