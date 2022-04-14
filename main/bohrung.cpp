//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 07.11.2021
// Author: MM
//------------------------------------------------------------------


#include <iostream>
#include "bohrung.h"

using std::cin;
using std::cout;
using std::endl;

void Bohrung::output(std::ostream& os)const{
    os << "Bohrung: ";
    Komponente::output(os);
    os << ", Durchmesser: " << getDiameter();
}

//Bohrung::~Bohrung(){};
