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

    P = searchParent(L,"kuntul");
    if(P==NULL){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Ditemukan: "<<infoK(P)<<endl;
    }





    cout<<"Parent: "; printParent(L);

}
