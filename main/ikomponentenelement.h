//------------------------------------------------------------------
// IKomponentenElement
// Copyright 07.11.2021
// Author: MM
//------------------------------------------------------------------

#ifndef IKOMPONENTENELEMENT_H
#define IKOMPONENTENELEMENT_H
#include "ikomponente.h"

struct IKomponentenElement {
    IKomponente* k;
    IKomponentenElement* before;
    IKomponentenElement* next;
};
#endif // IKOMPONENTENELEMENT_H
