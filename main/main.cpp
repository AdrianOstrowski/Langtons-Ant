#include <iostream>
#include "mrowka.h"
#include <windows.h>
#include <iomanip>

int main()
{
    Pole pl;
    Mrowka mr;

    for (int n = 0; n < mr.ilosc; n++) {
        pl.zamien(&mr, n);
    };

    pl.usun();

    return 0;

};