#ifndef KATEGORI_H_INCLUDED
#define KATEGORI_H_INCLUDED
#include "barang.h"
#include <stdlib.h>

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
void inputBarang(List &L, infotypeK kategori, infotypeB barang);
void printAll(List L);
adrBarang searchChild(adrBarang P,string nama);
void insertAfter(List &L, adrKategori Prec, adrKategori P);
void deleteAfter(List &L, adrKategori Prec, adrKategori &P);
void inputKategori(List &L, infotypeK kategori);
bool connection(List L, infotypeK kategori, infotypeB barang);
void insertLastChild(adrKategori P, infotypeB barang);
void insertFirstChild(adrKategori P, infotypeB barang);
void insertAfterChild(adrKategori P, adrBarang Prec, infotypeB barang);
void printIDOnly(List L);
adrBarang searchID(List L,infotypeB barang);
void MaxMinPriceKategory(List L, infotypeK kategori);
#endif // KATEGORI_H_INCLUDED
