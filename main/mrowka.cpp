#include <iostream>
#include <iomanip>
#include <windows.h>
#include "mrowka.h"


Mrowka::Mrowka() {
    std::cout << "Podaj ilosc mrowek" << std::endl;            //jeszcze nierozwiazmy problem tworzenia kilku
    std::cin >> ilosc;
    mrowka = new Mroweczka[ilosc];
    for (int n = 0; n < ilosc; n++) {
        mrowka[n].numer = n + 1;
        std::cout << "Podaj znak mrowki nr: " << mrowka[n].numer << std::endl;
        std::cin >> mrowka[n].znak;
        std::cout << "Podaj wspolrzedne mrowki nr: " << mrowka[n].numer << std::endl;;
        std::cin >> mrowka[n].x >> mrowka[n].y;
        std::cout << "Podaj ile krokow ma wykonac mrowka nr: " << mrowka[n].numer << std::endl;
        std::cin >> mrowka[n].ile_razy;
    };
};


void Mrowka::rusz(int z) {
    //funkcja ruchu mrowki
    for (int n = 0; n < ilosc; n++) {
        switch (mrowka[n].obrot) {
        case 'l': {                              //zapamietac poprzednie wspolrzedne
                                                //n,w,s,e kierunki jak na kompasie
            switch (mrowka[n].kierunek) {                   //zeby okreslic r\kierunek ruchu
            case 'n': {                                 //zrobic kontrole kiedy mrowka wyjdzie za plansze
                mrowka[n].y--;
                mrowka[n].kierunek = 'w';
                if (mrowka[n].y <= 0) {
                    mrowka[n].y = z;
                };
                break;

            }
            case 's': {
                mrowka[n].y++;
                mrowka[n].kierunek = 'e';
                if (mrowka[n].y >= z - 1) {
                    mrowka[n].y = 1;
                }
                break;
            }
            case 'e': {
                mrowka[n].x--;
                mrowka[n].kierunek = 'n';
                if (mrowka[n].x <= 0) {
                    mrowka[n].x = z;
                };
                break;
            }
            case 'w': {
                mrowka[n].x++;
                mrowka[n].kierunek = 's';
                if (mrowka[n].x >= z - 1) {
                    mrowka[n].x = 1;
                };
                break;
            }
            };
            break;
        };
        case 'p': {

            switch (mrowka[n].kierunek) {
            case 'n': {
                mrowka[n].y++;
                mrowka[n].kierunek = 'e';
                if (mrowka[n].y >= z - 1) {
                    mrowka[n].y = 1;
                }
                break;
            }
            case 's': {
                mrowka[n].y--;
                mrowka[n].kierunek = 'w';
                if (mrowka[n].y <= 0) {
                    mrowka[n].y = z;
                };
                break;
            }
            case 'e': {
                mrowka[n].x++;
                mrowka[n].kierunek = 's';
                if (mrowka[n].x >= z - 1) {
                    mrowka[n].x = 1;
                };
                break;
            }
            case 'w': {
                mrowka[n].x--;
                mrowka[n].kierunek = 'n';
                if (mrowka[n].x <= 0) {
                    mrowka[n].x = z;
                };
                break;
            };
            }
        };
                break;
        };
        break;
    };
};


Pole::Pole() {

    std::cout << "Podaj rozmiar tablicy" << std::endl;
    std::cin >> z;

    pole = new Wspolrzedne * [z];
    for (int i = 0; i < z; i++) {
        pole[i] = new Wspolrzedne[z];

    }
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < z; j++) {
            pole[i][j].kolor = '0';
        }

    };
};


void Pole::drukuj() {
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < z; j++) {
            std::cout << pole[i][j].kolor << '\t';

        }std::cout << std::endl;
    }std::cout << std::endl;
    Sleep(500);
};


void Pole::usun() {
    for (int i = 0; i < z; i++) {
        delete[]pole[i];
    }
    delete[]pole;
};


void Pole::zamien(Mrowka* m, int n) {
    //funckja pokazujaca ruch mrowki
    for (int o = 0; o < m->mrowka[n].ile_razy; o++) {
        for (int i = 0; i < z; i++) {
            for (int j = 0; j < z; j++) {
                pole[i][j].x = i + 1;
                pole[i][j].y = j + 1;
                if (m->mrowka[n].x == pole[i][j].x && m->mrowka[n].y == pole[i][j].y && pole[i][j].kolor == '0') {
                    system("cls");
                    pole[i][j].kolor = m->mrowka[n].znak;
                    drukuj();
                    system("cls");
                    m->mrowka[n].obrot = 'l';
                    m->rusz(z);
                    drukuj();
                    pole[i][j].kolor = '1';
                    break;

                };
                if (m->mrowka[n].x == pole[i][j].x && m->mrowka[n].y == pole[i][j].y && pole[i][j].kolor == '1') {
                    system("cls");
                    pole[i][j].kolor = m->mrowka[n].znak;
                    drukuj();
                    system("cls");
                    m->mrowka[n].obrot = 'p';
                    m->rusz(z);
                    drukuj();
                    pole[i][j].kolor = '0';
                    break;
                };
            };
        };
    };

};