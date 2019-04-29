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

////////UNIVERSAL//////
void createList(List &L);
bool isEmpty(List L);
void printAll(List L);
bool connection(List L, infotypeK kategori, infotypeB barang);
void MaxMinPriceKategory(List L, infotypeK kategori); //CASE1
int countBarang(List L,infotypeK kategori); //CASE2
void Menu();

///////PARENT////////////
adrKategori allocationKat(infotypeK kategori);
void insertFirst(List &L, adrKategori P);
void insertAfter(List &L, adrKategori Prec, adrKategori P);
void insertLast(List &L, adrKategori P);
void deleteFirst(List &L, adrKategori &P);
void deleteAfter(List &L, adrKategori Prec, adrKategori &P);
void deleteLast(List &L, adrKategori &P);
void inputKategori(List &L, infotypeK kategori);
void deleteKategori(List &L,infotypeK kategori);
void printParent(List L);
adrKategori searchParent(List L, infotypeK kategori);
adrKategori searchParentID(List L,infotypeB barang);

///////////CHILD/////////////////////
adrBarang allocationBrg(infotypeB barang);
void insertFirstChild(adrKategori P, infotypeB barang);
void insertAfterChild(adrKategori P, adrBarang Prec, infotypeB barang);
void insertLastChild(adrKategori P, infotypeB barang);
void deleteFirstChild(adrKategori &P, adrBarang &Q);
void deleteAfterChild(adrKategori &P, adrBarang Prec, adrBarang &Q);
void deleteLastChild (adrKategori &P,adrBarang&Q);
void inputBarang(List &L, infotypeK kategori, infotypeB barang);
void deleteBarang(List &L, infotypeB barang);
void printIDOnly(List L);
void printBarangOnly(List L);
adrBarang searchChild(adrBarang P,string nama);
adrBarang searchID(List L,infotypeB barang);

#endif // KATEGORI_H_INCLUDED
