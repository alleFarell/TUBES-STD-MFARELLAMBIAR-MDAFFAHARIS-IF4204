#include "kategori.h"

void createList(List &L){
    First(L) = NULL;
    Last(L) = NULL;
}

void createList(ListBrg &L2){
    First(L2) = NULL;
    Last(L2) = NULL;
}

bool isEmpty(List L){
    if(First(L)==NULL){
        return true;
    }
    else{
        return false;
    }
}

adrKategori allocationKat(infotypeK kategori){
    adrKategori P = new elmlistKategori;
    infoK(P) = kategori;
    nextK(P) = NULL;
    prevK(P) = NULL;
    ListBrg L2;
    createList(L2);
}
void insertFirst(List &L, adrKategori P){
    if (First(L) != NULL){
        nextK(P)= First(L);
        prevK(First(L))= P;
        First(L)=P;
    } else{
        First(L) = P;
        Last(L) = P;
    }
}

void insertLast(List &L, adrKategori P){
    if(P!= NULL){
        prevK(P) = Last(L);
        nextK(Last(L)) = P;
        Last(L) = P;
    } else{
        insertFirst(L,P);
    }
}

void deleteFirst(List &L, adrKategori &P){
    P = First(L);
    if(First(L)!= Last(L)){
        First(L) = nextK(P);
        prevK(First(L)) = NULL;
        nextK(P) = NULL;
    } else{
        First(L) = NULL;
        Last(L) = NULL;
    }

}

void deleteLast(List &L, adrKategori &P){
    if(First(L)!=Last(L)){
        P = Last(L);
        Last(L) = prevK(Last(L));
        nextK(Last(L)) = NULL;
        prevK(P) = NULL;
    } else{
        deleteFirst(L,P);
    }
}

void printParent(List L){
    adrKategori P = First(L);
    while (P!=NULL){
        cout<<infoK(P)<<" - ";
        P = nextK(P);
    }
};

adrKategori searchParent(List L, infotypeK kategori){
    adrKategori P = First(L);
    do{
        if(infoK(P)== kategori){
            return P;
        } else{
            P= nextK(P);
        }

    } while(P != Last(L));
    return NULL;
}

void insertBarang(List &L, infotypeK kategori, infotypeB barang){
    adrKategori P = searchParent(L,kategori);
    if (P!=NULL){

    }
}
