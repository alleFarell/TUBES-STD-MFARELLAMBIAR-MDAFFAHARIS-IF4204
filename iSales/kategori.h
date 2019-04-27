#ifndef KATEGORI_H_INCLUDED
#define KATEGORI_H_INCLUDED
#include "barang.h"

#include <iostream>
using namespace std;

#define nextK(P) P->nextK
#define prevK(P) P->prevK
#define infoK(P) P->infoK
#define First(L) L.First
#define Last(L) L.Last

typedef string infotypeK;
typedef struct elmlistKategori *adrKategori;

struct elmlistKategori{
    infotypeK infoK;
    adrKategori nextK;
    adrKategori prevK;
    adrBarang pointerBrg;
};
struct List{
    adrKategori First;
    adrKategori Last;
};
void createList(List &L);
adrKategori allocationKat(infotypeK kategori);
void insertFirst(List &L, adrKategori P);
void printParent(List L);
bool isEmpty(List L);
void insertLast(List &L, adrKategori P);
void deleteFirst(List &L, adrKategori &P);
void deleteLast(List &L, adrKategori &P);
adrKategori searchParent(List L, infotypeK kategori);
adrBarang allocationBrg(infotypeB barang);
void insertBarang(List &L, infotypeK kategori, infotypeB barang);
void printAll(List L);
adrBarang searchChild(adrBarang P,string nama);

#endif // KATEGORI_H_INCLUDED
