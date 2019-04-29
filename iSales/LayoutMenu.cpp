#include "kategori.h"

void Menu(){
    List L;
    int X;
    createList(L);
    //header

    cout<<"=================================  MENU  ================================="<<endl;
    cout<<"|                                                                        |"<<endl;
    cout<<"|                                                                        |"<<endl;
    cout<<"|\t1. Input Kategori                                                     |"<<endl;
    cout<<"|\t2. Input Barang                                                       |"<<endl;
    cout<<"|\t3. Hapus Kategori                                                     |"<<endl;
    cout<<"|\t4. Hapus Barang                                                       |"<<endl;
    cout<<"|\t5. Tampilkan Kategori                                                 |"<<endl;
    cout<<"|\t6. Tampilkan Semua                                                    |"<<endl;
    cout<<"|\t7. Cari Barang Berdasarkan ID                                         |"<<endl;
    cout<<"|\t8. Cek koneksi kategori dan Barang                                    |"<<endl;
    cout<<"|\t9. Tampilkan harga Tertinggi dan Terendah                             |"<<endl;
    cout<<"|\t10. Function 2                                                         |"<<endl;
    cout<<"|\t11. TEST                                                               |"<<endl;
    cout<<"============================  copyright 2019  ============================"<<endl;
    cout<<endl;
    cout<<"Masukkan Pilihan Menu: ";
    cin>> X;
    switch (X){
        case 1:
            infotypeK kategori;
            //header
            cout<<"Input Kategori: ";
            cin>>kategori;
            inputKategori(L,kategori);
            break;
        case 2 :
            infotypeK kategori;
            infotypeB barang;
            //header
            printParent(L);
            cout<<"Pilih Kategori: ";
            cin>>kategori;
            cout<<"Masukkan Nama Barang: ";
            cin>>barang;
            inputBarang(L,kategori,barang);
            break;
        case 3 :
            break;
        case 4 :
            break;
        case 5 :
            printParent(L);
            break;
        case 6 :
            printAll(L);
            break;
        case 7 :
            infotypeB barang;
            printIDOnly(L);
            cout<<"Masukkan ID. Barang yang Dicari: ";
            cin>>barang.ID;
            adrBarang W = searchID(L,barang);
            if(W!=NULL){
                cout<<"ID ditemukan yaitu: "<<infoB(W).ID<<" - "<<infoB(W).nama<<" - "<<infoB(W).harga<<endl;
            } else {
                cout<<"ID. Tidak Ditemukan";
            }
            break;
        case 8 :
            infotypeK kategori;
            infotypeB barang;
            cout<<"Masukkkan Kategori: ";
            cin>>kategori;
            cout<<"Masukkan Barang: ";
            cin>>barang;
            bool Q = connection(L,kategori,barang);
            if (Q== true){
                cout<<"Kategori dan Barang Terkoneksi"<<endl;
            } else {
                cout<<"Kategori dan barang tidak terkonksi"<<endl;
            }
            break;
    }
}
