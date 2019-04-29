#include "kategori.h"

adrBarang allocationBrg(infotypeB barang){
    adrBarang P = new elmlistBarang;
    infoB(P).ID = rand() % 1000 + 10;
    infoB(P).nama = barang.nama;
    infoB(P).harga = barang.harga;
    nextB(P) = NULL;
    prevB(P) = NULL;
    return P;
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
    if (nextB(Prec)!=pointerBrg(P)&&nextB(nextB(Prec))!=NULL){
        Q = nextB(Prec);
        nextB(Prec) = nextB(Q);
        prevB(nextB(Q)) = Prec;
        nextB(Q) = NULL;
        prevB(Q) = NULL;
    } else if (Prec==pointerBrg(P)){
        deleteFirstChild(P,Q);
    }
}
void deleteLastChild (adrKategori &P,adrBarang&Q){
    adrBarang R = pointerBrg(P);
    while(nextB(R)!=NULL){
        R = nextB(R);
    }
    Q = R;
    nextB(prevB(Q)) = NULL;
    prevB(Q) = NULL;
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
void deleteBarang(List &L, infotypeB barang){
    adrBarang Q = searchID(L,barang);
    adrKategori P = searchParentID(L,barang);
    if (Q !=NULL){
        adrBarang R;
        if(Q!=pointerBrg(P)&&nextB(Q)!=NULL){
            deleteAfterChild(P,prevB(Q),R);
            delete R;
        } else if(Q==pointerBrg(P)) {
            deleteFirstChild(P,Q);
        } else if(nextB(Q)==NULL){
            deleteLastChild(P,Q);
        }
    } else{
        cout<<"Barang Tidak Ditemukan"<<endl;
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
