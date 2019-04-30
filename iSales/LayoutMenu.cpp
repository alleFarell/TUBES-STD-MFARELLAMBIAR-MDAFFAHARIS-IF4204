#include "kategori.h"
#include<windows.h>
void header(){
    system("color E5");
    system("cls");
    cout<<"===============================  i-Sales  ================================"<<endl;
    cout<<"|                                                                        |"<<endl;
    cout<<"|                 'Creating Future With Digital Economy'                 |"<<endl;
    cout<<"|                              Created By :                              |"<<endl;
    cout<<"|                               MDH & MFA                                |"<<endl;
    cout<<"|                                                                        |"<<endl;
    cout<<"================================  V 1.0  ================================="<<endl;

};
void Menu(){
    List L;
    int X;
    createList(L);
    infotypeK kategori;
    infotypeB barang;
    do{
        header();
        cout<<"=================================  MENU  ================================="<<endl;
        cout<<"|                                                                        |"<<endl;
        cout<<"|                                                                        |"<<endl;
        cout<<"|\t1. Input Kategori                                                |"<<endl;
        cout<<"|\t2. Input Barang                                                  |"<<endl;
        cout<<"|\t3. Hapus Kategori                                                |"<<endl;
        cout<<"|\t4. Hapus Barang                                                  |"<<endl;
        cout<<"|\t5. Tampilkan Kategori                                            |"<<endl;
        cout<<"|\t6. Tampilkan Semua                                               |"<<endl;
        cout<<"|\t7. Cari Barang Berdasarkan ID                                    |"<<endl;
        cout<<"|\t8. Cek koneksi kategori dan Barang                               |"<<endl;
        cout<<"|\t9. Tampilkan harga Tertinggi dan Terendah                        |"<<endl;
        cout<<"|\t10. Hitung banyak Barang per Kategori                            |"<<endl;
        cout<<"|\t0. EXIT                                                          |"<<endl;
        cout<<"|                                                                        |"<<endl;
        cout<<"|                                                                        |"<<endl;
        cout<<"============================  copyright 2019  ============================"<<endl;
        cout<<endl;
        cout<<"Masukkan Pilihan Menu: ";
        cin>> X;
        switch (X){
            case 1:{
                header();
                cout<<"Input Kategori: ";
                cin>>kategori;
                inputKategori(L,kategori);
                system("pause");
                break;
            }
            case 2 :{
                header();
                printParent(L);
                cout<<"Pilih Kategori: ";
                cin>>kategori;
                cout<<"Masukkan Nama Barang: ";
                cin>>barang.nama;
                 cout<<"Masukkan Harga Barang: ";
                cin>>barang.harga;
                inputBarang(L,kategori,barang);
                system("pause");
                break;
            }
            case 3 :{
                header();
                printParent(L);
                cout<<"Masukkan Kategori yang ingin dihapus: ";
                cin>>kategori;
                deleteKategori(L,kategori);
                system("pause");
                break;
            }
            case 4 :{
                header();
                printAll(L);
                infotypeB barang2;
                cout<<"Masukkan ID. Barang yang akan dihapus: ";
                cin>>barang2.ID;
                deleteBarang(L,barang2);
                system("pause");
                break;
            }
            case 5 :{
                header();
                printParent(L);
                system("pause");
                break;
            }
            case 6 :{
                header();
                printAll(L);
                system("pause");
                break;
            }
            case 7 :{
                header();
                printIDOnly(L);
                cout<<"Masukkan ID. Barang yang Dicari: ";
                cin>>barang.ID;
                adrBarang W = searchID(L,barang);
                if(W!=NULL){
                    cout<<"ID ditemukan yaitu: "<<endl;
                    cout<<"\tID.\t: "<<infoB(W).ID<<endl;
                    cout<<"\tNama\t: "<<infoB(W).nama<<endl;
                    cout<<"\tHarga\t: "<<infoB(W).harga<<endl;
                } else {
                    cout<<"ID. Tidak Ditemukan"<<endl;
                }
                system("pause");
                break;
            }
            case 8 :{
                header();
                printParent(L);
                printBarangOnly(L);
                cout<<"Masukkkan Kategori: ";
                cin>>kategori;
                cout<<"Masukkan Barang: ";
                cin>>barang.nama;
                bool Q = connection(L,kategori,barang);
                if (Q== true){
                    cout<<"Kategori dan Barang Terkoneksi"<<endl;
                } else {
                    cout<<"Kategori dan barang tidak terkonksi"<<endl;
                }
                system("pause");
                break;
            }
            case 9 :{
                header();
                printParent(L);
                cout<<"Masukkan Kategori MinMax Price: "; cin>>kategori;
                MaxMinPriceKategory(L,kategori);
                system("pause");
                break;
            }
            case 10 :{
                header();
                printParent(L);
                cout<<"Pilih kategori: ";
                cin>>kategori;
                int X = countBarang(L,kategori);
                cout<<"Jumlah Barang Pada Kategori "<<kategori<<" adalah: "<<X<<endl;
                system("pause");
                break;
            }
        }
    } while(X != 0);
    header();
    cout<<"HATUR NUHUN GaiZh";
}
