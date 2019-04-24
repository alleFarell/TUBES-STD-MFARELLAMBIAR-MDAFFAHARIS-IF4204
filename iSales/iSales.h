#ifndef ISALES_H_INCLUDED
#define ISALES_H_INCLUDED

#include <iostream>
using namespace std;

#define nextB(P) P->nextB
#define prevB(P) P->prevB
#define nextK(P) P->nextK
#define prevK(P) P->prevK
#define infoK(P) P->infoK
#define infoB(P) P->infoB
#define First(L) L.First
#define Last(L) L.Last
#define FirstBrg(P) P->FirstBrg
#define LastBrg(P) P->LastBrg



struct infoBarang{
    int ID;
    string nama;
    int harga;
};

typedef infoBarang infotypeB;
typedef struct elmlistBarang *adrBarang;
typedef string infotypeK;
typedef struct elmlistKategori *adrKategori;

struct elmlistBarang {
    infotypeB infoB;
    adrBarang nextB;
    adrBarang prevB;
};

struct elmlistKategori{
    infotypeK infoK;
    adrKategori nextK;
    adrKategori prevK;
    adrBarang FirstBrg;
    adrBarang LastBrg;

};

struct List{
    adrKategori First;
    adrKategori Last;
};







#endif // ISALES_H_INCLUDED
