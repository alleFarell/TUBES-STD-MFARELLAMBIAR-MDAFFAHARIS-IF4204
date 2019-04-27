#ifndef BARANG_H_INCLUDED
#define BARANG_H_INCLUDED


#define nextB(P) P->nextB
#define prevB(P) P->prevB
#define infoB(P) P->infoB
#define FirstBrg(L) L.FirstBrg
#define LastBrg(L) L.LastBrg
#define pointerBrg(P) P->pointerBrg

#include <iostream>
using namespace std;


typedef struct elmlistBarang *adrBarang;

struct infoBarang{
    int ID;
    string nama;
    int harga;
};
typedef infoBarang infotypeB;
struct elmlistBarang {
    infotypeB infoB;
    adrBarang nextB;
    adrBarang prevB;
};


#endif // BARANG_H_INCLUDED
