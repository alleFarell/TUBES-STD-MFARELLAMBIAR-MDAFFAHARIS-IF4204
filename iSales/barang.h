#ifndef BARANG_H_INCLUDED
#define BARANG_H_INCLUDED


#define nextB(P) P->nextB
#define prevB(P) P->prevB
#define infoB(P) P->infoB
#define FirstBrg(L) L.FirstBrg
#define LastBrg(L) L.LastBrg

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
struct ListBrg{
    adrBarang First;
    adrBarang Last;
};


#endif // BARANG_H_INCLUDED
