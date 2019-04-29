#include "kategori.h"

using namespace std;

int main()
{
    List L;
    createList(L);
    inputKategori(L,"Minuman");
    inputKategori(L,"ATK");
    inputKategori(L,"Kontrasepsi");

    infotypeB Z;
    cout<<"nama : ";
    cin>>Z.nama;
    cout<<"harga : ";
    cin>>Z.harga;
    inputBarang(L,"Minuman",Z);

    cout<<"nama : ";
    cin>>Z.nama;
    cout<<"harga : ";
    cin>>Z.harga;
    inputBarang(L,"Minuman",Z);

    cout<<"nama : ";
    cin>>Z.nama;
    cout<<"harga : ";
    cin>>Z.harga;
    inputBarang(L,"Minuman",Z);

    cout<<"nama : ";
    cin>>Z.nama;
    cout<<"harga : ";
    cin>>Z.harga;
    inputBarang(L,"Kontrasepsi",Z);

    printAll(L);
    /*printIDOnly(L);
    infotypeB Q;
    cout<<"ID yang dicari : ";
    cin>>Q.ID;
    adrBarang W = searchID(L,Q);
    if(W!=NULL){
        cout<<infoB(W).ID<<" - "<<infoB(W).nama<<" - "<<infoB(W).harga<<endl;
    } else {
        cout<<"Kosongsss";
    }*/
    MaxMinPriceKategory(L,"Minuman");
}
