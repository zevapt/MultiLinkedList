#ifndef INSTA_H_INCLUDED
#define INSTA_H_INCLUDED
//
// created by Zeva Patu A on 22/12/2022
//

//--- Library ---//
#include <iostream>
#include <conio.h>
//--- Define Pointer ---//
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define child(P) P->child

using namespace std;

//--- Deklarasi Pointer address ---//
typedef struct elmP *adrP;
typedef struct elmC *adrC;

//--- Deklarasi Tipe Bentukan Infotype ---//
struct acc {
    string usn;
    char verif;
};
typedef acc infotypeC;
typedef acc infotypeP;

//--- Tipe Bentukan Element List ---//

//Tipe Bentukan Parent Akun
struct elmP {
    infotypeP info;
    adrP next;
    adrP prev;
    adrC child;
};

//Tipe Bentukan child Akun
struct elmC {
    infotypeC info;
    adrC next;
};

//--- Tipe Bentukan List ---//
struct listP {
    adrP first;
    adrP last;
};
struct listC {
    adrC first;
};

//---------- Fungsi dan Prosedur ----------//

//----- Create -----//
void createListP(listP &L);
void createListC(listC &L);
void createAccP(infotypeP &accP);

//----- Address -----//
adrP alokasiP(infotypeP &accP);
adrC alokasiC(infotypeC &accC);

adrP findElmP(listP L, string x);
adrC findElmC(listC L, string x);

//----- View -----//
void printInfoP(listP L);
void printInfoPnC(listP L);
void printCertainP(listP L);
void printFollP(listP L);

//----- Searching -----//
void searchParent(listP L);
void searchChild(listP L);

//----- Insert Akun Child -----//
void insertLastC(adrP P, infotypeC addC);
void addC(listP &L);

//----- Delete Akun Parent -----//
void deleteFirstP(listP &L, adrP &P);
void deleteLastP(listP &L, adrP &P);
void deleteAfterP(listP &L, adrP &P);
void deleteParentbyUsn(listP &L);

//----- Delete Akun Child -----//
void deleteFirstC(listP &LP, listC &LC,adrC &C, adrP &P);
void deleteLastC(listC &L, adrC &C);
void deleteAfterC(listC &L, adrC &C);
void deleteChildbyUsn(listC &L, string x);
void unfoll(listP &L);

//----- Insert Akun Parent Tambahan -----//
void insertFirstP(listP &L, adrP P);
void insertLastP(listP &L, adrP P);
void addP(listP &L);

//----- Counting -----//
int countParent(listP L);
int countChild(listC L);
int countFollowing(listP L, string x);
void menuCount(listP L);

//----- Delete Akun ------//
void deact(listP &L);
#endif // INSTA_H_INCLUDED
