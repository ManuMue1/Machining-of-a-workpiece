//------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 07.11.2021
// Author: MM
//------------------------------------------------------------------

#include <iostream>

#include "fraesung.h"
#include "werkstueck.h"
#include <cmath>

using std::cout;
using std::endl;

int main() {
    //Komponenten Erstellung
    //Bohrungen und Fräsungen erstellen
        Bohrung b1{1, 2, 8};
        Bohrung b2{2, 6, 4};
        Bohrung b3{10, 8, 7};
        Bohrung b4{7, 2, 5};
        Bohrung b5{1, 2, 6};
        Bohrung b6{5, 1, 8};
        Bohrung b7{5, 2.5, 8};
        Bohrung b8{6, 0.5, 6};

        Fraesung f1{2, 3, 5, 2*sqrt(2), 0.25*M_PI};
        Fraesung f2{6, 7, 6, 3};
        Fraesung f3{17, 6, 4, 4*sqrt(2), 1.25*M_PI};
        Fraesung f4{3, 3, 3, sqrt(5), M_PI-0.463647};
        Fraesung f5{1, 2, 4, sqrt(2), 1.75*M_PI};
    //DeList Erstellung;
    DeList kl;

    //Push_Back Test
    kl.push_back(&b1);
    kl.push_back(&f1);
    kl.push_back(&b3);
    kl.push_back(&f2);
    kl.push_back(&b4);
    kl.push_back(&f3);
    kl.push_back(&b2);

    Werkstueck w2(6, 3);
        w2.add(&b7);
        w2.add(&b8);
        w2.add(&f5);

    Werkstueck w1(6, 10);
        w1.add(&b5);
        w1.add(&b6);
        w1.add(&f4);
        w1.add(&w2);

    Werkstueck w0;
        w0.add(&b1);
        w0.add(&b2);
        w0.add(&b3);
        w0.add(&b4);
        w0.add(&f1);
        w0.add(&f2);
        w0.add(&f3);
        w0.add(&w1);


    cout << w0 << endl;
    cout << "total Path w0: " << w0.calcTotalPath() << endl;
    cout << "Path length w0: " << w0.calcPathLength() << endl;
    cout << "total Path w1: " << w1.calcTotalPath() << endl;
    cout << "Path length w1: " << w1.calcPathLength() << endl;
    cout << "total Path w2: " << w2.calcTotalPath() << endl;
    cout << "Path length w2: " << w2.calcPathLength() << endl << endl << endl;

    w0.optimizePath();
    cout << "-------Path optimized-------" << endl;
    cout << w0 << endl;
    cout << "total Path w0: " << w0.calcTotalPath() << endl;
    cout << "Path length w0: " << w0.calcPathLength() << endl;
    cout << "total Path w1: " << w1.calcTotalPath() << endl;
    cout << "Path length w1: " << w1.calcPathLength() << endl;
    cout << "total Path w2: " << w2.calcTotalPath() << endl;
    cout << "Path length w2: " << w2.calcPathLength() << endl<< endl<< endl;


    return 0;


}
