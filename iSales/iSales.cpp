#include "iSales.h"

void createList(List &L){
    First(L) = NULL;
    Last(L) = NULL;
}

adrKategori allocationKat(string kategori){
    adrKategori P = new elmlistKategori;
    infoK(P) = kategori;
    nextK(P) = NULL;
    prevK(P) = NULL;
    FirstBrg(P) = NULL;
    LastBrg(P) = NULL;
}
