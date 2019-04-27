#include "kategori.h"

using namespace std;

int main()
{
    List L;
    createList(L);
    adrKategori P = allocationKat("Makanan");
    insertFirst(L,P);
    P = allocationKat("Minuman");
    insertFirst(L,P);
    P = allocationKat("ATK");
    insertFirst(L,P);
    P = allocationKat("alat Kungfu");
    insertFirst(L,P);

    deleteLast(L,P);

    P = searchParent(L,"Minuman");
    if(P==NULL){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Ditemukan: "<<infoK(P)<<endl;
    }
    infotypeB Z;
    cout<<"nama : ";
    cin>>Z.nama;
    cout<<"harga : ";
    cin>>Z.harga;
    insertBarang(L,"ATK",Z);
    cout<<"nama : ";
    cin>>Z.nama;
    cout<<"harga : ";
    cin>>Z.harga;
    insertBarang(L,"ATK",Z);
    cout<<"nama : ";
    cin>>Z.nama;
    cout<<"harga : ";
    cin>>Z.harga;
    insertBarang(L,"Minuman",Z);
    printAll(L);
    P = searchParent(L,"Minuman");
    adrBarang Q = searchChild(pointerBrg(P),"aqua");
    if (Q!=NULL){
        cout<<infoB(Q).nama;
    } else {
        cout<<"tidak ada";
    }


}
