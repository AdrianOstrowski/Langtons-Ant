#include <iostream>
#include <iomanip>
#ifndef  MROWKA_H
#define  MROWKA_H

class Mrowka;

class Pole
{
    friend class Mrowka;                                        //zrobic strukture zapamietujaca wspolrzedne
protected:
    struct Wspolrzedne {
        int x;
        int y;
        char kolor;
    };

    Wspolrzedne** pole;
    int z;
    int indx, indy;

public:
    Pole();
    void drukuj();
    void usun();
    void zamien(Mrowka* m, int n);
};



class Mrowka
{
    friend class Pole;
public:
    struct Mroweczka {
        int x, y, ile_razy;
        char znak;                //najpierw mrowka patrzy w prawo
        int numer;
        char kierunek = 'e';
        char obrot;
    };
    Mroweczka* mrowka;
    int ilosc;
    Mrowka();
    void rusz(int z);
    void usun();
};


#endif
