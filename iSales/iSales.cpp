#include "kategori.h"

void createList(List &L){
    First(L) = NULL;
    Last(L) = NULL;
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
    pointerBrg(P) = NULL;
    return P;
}
adrBarang allocationBrg(infotypeB barang){
    adrBarang P = new elmlistBarang;
    infoB(P).ID = barang.ID;
    infoB(P).nama = barang.nama;
    infoB(P).harga = barang.harga;
    nextB(P) = NULL;
    prevB(P) = NULL;
    return P;
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

void printAll(List L){
    adrKategori P = First(L);
    adrBarang Q;
    while(P!= NULL){
        cout<<"parent: "<<infoK(P)<<endl;
        Q = pointerBrg(P);
        while(Q!= NULL){
            cout<<infoB(Q).ID<<" - "<<infoB(Q).nama<<" - "<<infoB(Q).harga<<endl;
            Q = nextB(Q);
        }
        P = nextK(P);
        cout<<endl;
    }
}


adrKategori searchParent(List L, infotypeK kategori){
    adrKategori P = First(L);
    while(P != NULL){
        if(infoK(P)== kategori){
            return P;
        } else{
            P= nextK(P);
        }

    };
    return NULL;
}

void insertBarang(List &L, infotypeK kategori, infotypeB barang){
    adrKategori P = searchParent(L,kategori);
    if (P!= NULL){
        adrBarang R = allocationBrg(barang);
        if(pointerBrg(P)!=NULL){
            adrBarang Q = pointerBrg(P);
            while (nextB(Q)!=NULL){
                Q = nextB(Q);
            }
            nextB(Q)= R;
            prevB(R)= Q;
       } else {
            pointerBrg(P)= R;
       }
    }
}
adrBarang searchChild(adrBarang P,string nama){
   while(P != NULL){
        if(infoB(P).nama== nama){
            return P;
        } else{
            P= nextB(P);
        }

    };
    return NULL;
}

