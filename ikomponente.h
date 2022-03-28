//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 02.12.2021
// Author: MM
//------------------------------------------------------------------

#ifndef IKOMPONENTE_H
#define IKOMPONENTE_H

#include <iostream>

class IKomponente {
public:
    virtual double calcTotalPath() const = 0;
    virtual double getXAbsolute() const = 0;
    virtual double getYAbsolute() const = 0;
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double distance(IKomponente const* k) const = 0;
    virtual IKomponente const* getParent() const = 0;
    virtual void setParent(IKomponente const* p) = 0;
    virtual void output(std::ostream& os) const = 0;
    ~IKomponente();
};

inline std::ostream& operator<<(std::ostream& os, const IKomponente& ik) {
    ik.output(os);
    return os;
}
#endif // IKOMPONENTE_H
