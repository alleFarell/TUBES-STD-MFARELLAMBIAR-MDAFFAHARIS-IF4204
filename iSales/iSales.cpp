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
    infoB(P).ID = rand() % 1000 + 10;
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
    if(First(L)!= NULL){
        prevK(P) = Last(L);
        nextK(Last(L)) = P;
        Last(L) = P;
    } else{
        insertFirst(L,P);
    }
}

void insertAfter(List &L, adrKategori Prec, adrKategori P){
    if (Prec != Last(L)){
        nextK(P) = nextK(Prec);
        prevK(nextK(P)) = P;
        prevK(P) = Prec;
        nextK(Prec) = P;
    } else {
        insertLast(L,P);
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

void deleteAfter(List &L, adrKategori Prec, adrKategori &P){
     /*
    Name: Muhamad Farell Ambiar
    NIM: 1301184262
    */
    P = nextK(Prec);
    nextK(Prec) = nextK(P);
    prevK(nextK(P)) = Prec;
    nextK(P) = NULL;
    prevK(P) = NULL;

}

void printParent(List L){
    adrKategori P = First(L);
    cout<<"Kategori Yang ada : ";
    while (P!=NULL){
        cout<<infoK(P)<<" - ";
        P = nextK(P);
    }
    cout<<endl;
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
void printIDOnly(List L){
    adrKategori P = First(L);
    adrBarang Q;
    cout<<endl<<"ID YANG TERSEDIA PADA LIST: "<<endl<<endl;
    while(P!= NULL){
        Q = pointerBrg(P);
        while(Q!= NULL){
            cout<<infoB(Q).ID<<" - ";
            Q = nextB(Q);
        }
        P = nextK(P);
    }
    cout<<endl;
}
void printBarangOnly(List L){
    adrKategori P = First(L);
    adrBarang Q;
    cout<<endl<<"BARANG YANG TERSEDIA PADA LIST: "<<endl<<endl;
    while(P!= NULL){
        Q = pointerBrg(P);
        while(Q!= NULL){
            cout<<infoB(Q).nama<<" - ";
            Q = nextB(Q);
        }
        P = nextK(P);
    }
    cout<<endl;
}

adrKategori searchParent(List L, infotypeK kategori){
    adrKategori P = First(L);
    while(P != NULL){
        if(infoK(P)== kategori){
            return P;
        } else{
            P= nextK(P);
        }

    }
    return NULL;
}


void insertLastChild(adrKategori P, infotypeB barang){
    adrBarang R = allocationBrg(barang);
    if(pointerBrg(P)!=NULL){
        adrBarang Q = pointerBrg(P);
        while (nextB(Q)!=NULL){
            Q = nextB(Q);
        }
        nextB(Q)= R;
        prevB(R)= Q;
    }
    else{
        insertFirstChild(P, barang);
    }
}
void insertAfterChild(adrKategori P, adrBarang Prec, infotypeB barang){
    adrBarang R = allocationBrg(barang);
    if (nextB(Prec) != NULL){
        nextB(R) = nextB(Prec);
        prevB(nextB(R)) = R;
        prevB(R) = Prec;
        nextB(Prec) = R;
    } else {
        insertLastChild(P,barang);
    }
}
void insertFirstChild(adrKategori P, infotypeB barang){
    adrBarang R = allocationBrg(barang);
    if(pointerBrg(P) == NULL){
        pointerBrg(P) = R;
    }
    else{
        nextB(R) = pointerBrg(P);
        prevB(pointerBrg(P)) = R;
        pointerBrg(P) = R;
    }
}
void deleteFirstChild(adrKategori &P, adrBarang &Q){
    Q = pointerBrg(P);
    if(Q != NULL && nextB(Q)!= NULL){
        pointerBrg(P) = nextB(Q);
        prevB(pointerBrg(P)) = NULL;
        nextB(Q) = NULL;
    } else{
        pointerBrg(P) = NULL;
    }

}
void deleteAfterChild(adrKategori &P, adrBarang Prec, adrBarang &Q){
     /*
    Name: Muhamad Farell Ambiar
    NIM: 1301184262
    */
    if (Prec!=pointerBrg(P)){
        Q = nextB(Prec);
        nextB(Prec) = nextB(Q);
        prevB(nextB(Q)) = Prec;
        nextB(Q) = NULL;
        prevB(Q) = NULL;
    } else{
        deleteFirstChild(P,Q);
    }
}
adrBarang searchChild(adrBarang P,string nama){
   while(P != NULL){
        if(infoB(P).nama== nama){
            return P;
        } else{
            P= nextB(P);
        }

    }
    return NULL;
}

void inputBarang(List &L, infotypeK kategori, infotypeB barang){
    adrKategori P = searchParent(L,kategori);
    if(P!= NULL){
        adrBarang R = searchChild(pointerBrg(P),barang.nama);
        if (P!= NULL && R == NULL){
           insertLastChild(P, barang);
           cout<<endl<<"ENTRY BARANG BERHASIL!"<<endl<<endl;
        }
        else if(R != NULL){
            cout<<endl<<"DUPLICATE ENTRY BARANG"<<endl<<endl;
        }
    } else{

        cout<<endl<<"KATEGORI TIDAK DITEMUKAN GAIZ"<<endl<<endl;
    }
}



void inputKategori(List &L, infotypeK kategori){
    adrKategori P = searchParent(L,kategori);
    if(P == NULL){
        P = allocationKat(kategori);
        insertLast(L,P);
        cout<<endl<<"ENTRY KATEGORI BERHASIL!"<<endl<<endl;
    }
    else{
        cout<<"DUPLICATE ENTRY CATEGORY"<<endl;
    }
}

bool connection(List L, infotypeK kategori, infotypeB barang){
    adrKategori P = searchParent(L, kategori);
    if (P!=NULL){
        adrBarang Q = searchChild(pointerBrg(P), barang.nama);
        if(P != NULL && Q != NULL){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}
adrBarang searchID(List L,infotypeB barang){
    adrKategori P = First(L);
    adrBarang Q;
    while(P!= NULL){
        Q = pointerBrg(P);
        while(Q!= NULL){
            if (infoB(Q).ID == barang.ID){
                return Q;
            }
            Q = nextB(Q);
        }
        P = nextK(P);
    }
    return NULL;
}
adrKategori searchParentID(List L,infotypeB barang){
    adrKategori P = First(L);
    adrBarang Q;
    while(P!= NULL){
        Q = pointerBrg(P);
        while(Q!= NULL){
            if (infoB(Q).ID == barang.ID){
                return P;
            }
            Q = nextB(Q);
        }
        P = nextK(P);
    }
    return NULL;
}
void MaxMinPriceKategory(List L, infotypeK kategori){
    adrKategori P = searchParent(L,kategori);
    if(P != NULL){
        adrBarang Q = pointerBrg(P);
        if(Q!= NULL){
            int Max = 0;
            int Min = infoB(Q).harga;
            while(Q != NULL){
                if(infoB(Q).harga >= Max){
                    Max = infoB(Q).harga;
                }
                if(infoB(Q).harga <= Min ){
                    Min = infoB(Q).harga;
                }
                Q = nextB(Q);
            }
            cout<<"Harga Tertinggi pada kategori "<<infoK(P)<<" adalah: Rp."<<Max<<endl;
            cout<<"Harga Terendah pada kategori "<<infoK(P)<<" adalah: Rp."<<Min<<endl;
        } else{
            cout<<endl<<"TIDAK ADA BARANG GAIZ"<<endl<<endl;
        }
    }
    else{
        cout<<"kategory tidak ketemu"<<endl;
    }
}
void deleteKategori(List &L,infotypeK kategori){
    adrKategori P = searchParent(L,kategori);
    if (P!=NULL){
        adrBarang Q = pointerBrg(P);
        while(Q!=NULL){
            deleteFirstChild(P,Q);
            delete Q;
        }
        adrKategori R;
        if(P!=First(L)){
            deleteAfter(L,prevK(P),R);
            delete R;
        } else{
            deleteFirst(L,R);
            delete R;
        }
        cout<<endl<<"DELETE KATEGORY BERHASIL!"<<endl<<endl;
    }else{
        cout<<endl<<"KATEGORY TIDAK DITEMUKAN"<<endl<<endl;
    }
}
void deleteBarang(List &L, infotypeB barang){
    adrBarang Q = searchID(L,barang);
    adrKategori P = searchParentID(L,barang);
    if (Q !=NULL){
        adrBarang R;
        if(Q!=pointerBrg(P)){
            deleteAfterChild(P,prevB(Q),R);
            delete R;
        } else{
            deleteFirstChild(P,Q);
        }
    } else{
        cout<<"Barang Tidak Ditemukan"<<endl;
    }
}
int countBarang(List L,infotypeK kategori){
    adrKategori P = searchParent(L,kategori);
    int X = 0;
    adrBarang Q = pointerBrg(P);
    while(Q!=NULL){
        X++;
        Q = nextB(Q);
    }
    return X;
}

