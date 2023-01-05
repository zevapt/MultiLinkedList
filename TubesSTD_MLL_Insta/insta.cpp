//
// created by Zeva Patu A on 22/12/2022

#include "insta.h"

//---------- Fungsi dan Prosedur ----------//

//----- Create -----//
void createListP(listP &L)
{
    first(L) = NULL;
    last(L) = NULL;
}
void createListC(listC &L)
{
    first(L) = NULL;
}
void createAccP(infotypeP &P)
{
    cout<<"=== Input Akun Baru ==="<<endl;
    cout<<"Username Akun\t: ";
    getline(cin, P.usn);
    if((P.usn[0] >= 'a' && P.usn[0] <= 'k') || (P.usn[0] >= 'A' && P.usn[0] <= 'K')) {
       P.verif = '~';
    } else {
        P.verif = '-';
    }
}

//----- Address -----//
adrP alokasiP(infotypeP &accP)
{
    adrP P;
    P = new elmP;
    info(P) = accP;
    next(P) = NULL;
    prev(P) = NULL;
    child(P) = NULL;
    return P;
}
adrC alokasiC(infotypeC &accC)
{
    adrC C = new elmC;
    info(C) = accC;
    next(C) = NULL;
    return C;
}

adrP findElmP(listP L, string x)
{
    adrP P = first(L);
    while(P != NULL) {
        if(info(P).usn == x){
            return P;
        }
        P = next(P);
    }
    return P;
}
adrC findElmC(listC L, string x)
{
    if(first(L) != NULL){
        adrC C = first(L);
        while(next(C) != first(L)){
            if(info(C).usn == x){
                return C;
            }
            C = next(C);
        }
        if(info(C).usn == x){
            return C;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

//----- View -----//
void printInfoP(listP L)
{
    adrP P = first(L);
    if(P != NULL) {
        cout << "========== List Akun ==========" << endl;
        while(P != NULL)
        {
            cout << "Username Akun  : " << info(P).usn <<endl;
            cout << endl;
            P = next(P);
        }
    } else {
        cout << "Tidak ada Akun yang dibuat" << endl;
        cout << endl;
    }
}

void printInfoPnC(listP L)
{
   if(first(L) != NULL) {
       adrP P = first(L);
       cout << "===== Data Akun dan Follower-nya =====" << endl;
       while(P != NULL) {
            cout << info(P).usn << " " << info(P).verif << endl;
            adrC C = child(P);
            if(C != NULL) {
                while(next(C) != child(P)) {
                    cout << "-> " << info(C).usn << " " << info(C).verif << endl;
                    C = next(C);
                }
                cout << "-> " << info(C).usn << " " << info(C).verif << endl;
            } else {
                cout << "-> " << endl;
            }
            cout << endl;
            P = next(P);
       }
   } else {
        cout << "Tidak ada akun yang dibuat"<<endl;
   }
}
void printCertainP(listP L)
{
    if(first(L) != NULL) {
        string x;
        cout << "Masukkan username akun yang akan ditampilkan follower-nya: ";
        getline(cin, x);
        adrP P = findElmP(L, x);
        if(P != NULL) {
            cout << info(P).usn << " " << info(P).verif << endl;
            adrC C = child(P);
            if(C != NULL) {
            while(next(C) != child(P)) {
                cout << "-> " << info(C).usn << " " << info(C).verif << endl;
                C = next(C);
            }
            cout << "-> " << info(C).usn << " " << info(C).verif << endl;
            }
        cout << endl;
        } else {
            cout << "Akun tidak ditemukan" << endl;
        }
    } else {
        cout << "Tidak ada Akun yang dibuat" << endl;
        cout << endl;
    }
}
void printFollP(listP L)
{
    if(first(L) != NULL) {
        string x;
        cout << "Masukkan username akun yang akan ditampilkan following-nya: ";
        getline(cin, x);
        adrP P = findElmP(L, x);
        if(P != NULL) {
            P = first(L);
            cout << "Following dari akun " << x << " adalah :\n";
            if(countFollowing(L, x) > 0) {
                while(P!=NULL) {
                    listC LC; createListC(LC); first(LC) = child(P);
                    adrC C = findElmC(LC, x);
                    if(C!=NULL) {
                        cout << "=> " << info(P).usn <<endl;
                    }
                    P = next(P);
                }
            } else {
                cout << "Tidak follow siapapun\n";
            }
        }
    } else {
        cout << "Tidak ada Akun yang dibuat" << endl;
        cout << endl;
    }

}

//----- Searching -----//
void searchParent(listP L)
{
    if(first(L) != NULL) {
        string x;
        cout << "Masukkan username akun yang akan ditampilkan : ";
        getline(cin, x);
        adrP P = findElmP(L, x);
        if(P != NULL) {
            cout << "Username Akun      : " << info(P).usn << endl;
            listC follower; createListC(follower); first(follower) = child(P);
            cout << "Banyak Follower    : " << countChild(follower) << endl;
            if(info(P).verif == '~') {
                cout << "Status verified    : true" << endl;
            } else {
                cout << "Status verified    : false" << endl;
            }
            cout << endl;
        } else {
            cout << "Akun tidak ditemukan" << endl;
        }
    } else {
        cout << "Tidak ada Akun yang dibuat" << endl;
        cout << endl;
    }
}
void searchChild(listP L)
{
    cout << "Masukkan username akun yang akan dicari : ";
    string x; getline(cin, x);
    adrP P = findElmP(L, x);
    if(P != NULL) {
        listC LC; createListC(LC); first(LC) = child(P);
        cout << "Masukkan username akun follower yang akan dicari : ";
        string y; getline(cin, y);
        adrC C = findElmC(LC, y);
        if(C != NULL) {
            cout << "Akun " << y << " follow " << x << endl;
        } else {
            cout << "Akun " << y << " tidak follow " << x << endl;
        }
    } else {
        cout << "Akun Tidak Ditemukan" << endl;
    }
}

//----- Insert Akun Child -----//
void insertLastC(adrP P, infotypeC addC)
{
    if(P == NULL) {
        cout << "Akun yang difollow tidak ditemukan" << endl;
    } else {
        adrC newC = alokasiC(addC);
        adrC C = child(P);
        if(C == NULL) {
            child(P) = newC;
            next(newC) = child(P);
        } else {
            while(next(C) != child(P)) {
                C = next(C);
            }
            next(C) = newC;
            next(newC) = child(P);
        }
    }
}
void addC(listP &L)
{
    if(first(L) == NULL) {
        cout << "Tidak ada akun yang dibuat" << endl;
    } else {
        printInfoPnC(L);
        cout << endl
        << "Masukkan username akun yang di follow : ";
        string x; cin >> x; cin.ignore();
        adrP P = findElmP(L, x);
        if(P == NULL) {
            cout << "Akun tidak ditemukan" << endl;
        } else {
            cout << "Masukkan akun yang follow : ";
            infotypeC y; cin >> y.usn; cin.ignore();
            listC LC; createListC(LC); first(LC) = child(P);
            //adrC sama = findElmC(LC, y.usn);
            if(x == y.usn) {
                cout << "Tidak bisa follow diri sendiri" << endl;
            } /*else if (info(sama).usn == y.usn){
                cout << "Tidak bisa follow akun yang sama dua kali"<<endl;
            }*/ else {
                adrP Q = findElmP(L, y.usn);
                if(Q != NULL) {
                    insertLastC(P, y);
                    cout << "Akun berhasil follow" << endl;
                } else {
                    cout << "Akun tidak ditemukan" << endl;
                }
            }
        }
    }
}

//----- Delete Akun Parent -----//
void deleteFirstP(listP &L, adrP &P)
{
    if(next(P) == NULL) {
        first(L) = NULL;
        last(L) = NULL;
    } else {
        cout<<"delfirst biasa"<<endl;
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}
void deleteLastP(listP &L, adrP &P)
{
    if(prev(P) == NULL) {
        first(L) = NULL;
        last(L) = NULL;
    } else {
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
}
void deleteAfterP(listP &L, adrP &P)
{
    adrP Prec = prev(P);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}
void deleteParentbyUsn(listP &L, adrP &P)
{
    if(first(L) == NULL) {
        cout << "Tidak ada Akun yang dibuat" << endl;
    } else {
        if(P == NULL) {
            cout << "Akun tidak ditemukan" << endl;
        } else if(P == first(L)) {
            deleteFirstP(L, P);
            cout << "udh di del parent" <<endl;
        } else if(P == last(L)) {
            deleteLastP(L, P);
            cout << "udh di del parent" <<endl;
        } else {
            deleteAfterP(L, P);
            cout << "udh di del parent" <<endl;
        }
    }

}

//----- Delete Akun Child -----//
void deleteFirstC(listP &LP, listC &LC,adrC &C, adrP &P)
{
    first(LC) = child(P);
    if(next(first(LC) == first(LC))) {
        child(P) = NULL;
        first(LC) = NULL;
    } else {
        adrC Curr = first(LC);
        while(next(Curr) != first(LC)) {
            Curr = next(Curr);
        }
        first(LC) = next(C);
        child(P) = first(LC);
        next(Curr) = first(LC);
        next(C) = NULL;
    }
}
void deleteLastC(listC &L, adrC &C)
{
    adrC Curr = first(L);
    while(next(Curr) != C) {
        Curr = next(Curr);
    }
    next(C) = NULL;
    next(Curr) = first(L);
}
void deleteAfterC(listC &L, adrC &C)
{
    adrC Curr = first(L);
    while(next(Curr) != C) {
        Curr = next(Curr);
    }
    next(Curr) = next(C);
    next(C) = NULL;
}
void deleteChildbyUsn(listP &L, string x)
{
    adrP P = first(L);
    while(P != NULL) {
        listC follower; createListC(follower);
        first(follower) = child(P);
        if(first(follower)==NULL){
            cout<<"tidak ada follower di " << info(P).usn <<endl;
        } else {
            adrC C = findElmC(follower, x);
            if(C != NULL) {
                cout<<"c ktemu\n";
                if(C == first(follower)) {
                    deleteFirstC(L, follower, C, P);
                    cout<<"udh di delfirst\n";
                } else if(next(C) == first(follower)) {
                    deleteLastC(follower, C);
                    cout<<"udh di delLast\n";
                } else {
                    deleteAfterC(follower, C);
                    cout<<"udh di delAfter\n";
                }
            }
        }
        P = next(P);
    }
}
void unfoll(listP &L)
{
    if(first(L) == NULL) {
        cout << "Tidak ada akun yang dibuat" << endl;
    } else {
        printInfoPnC(L);
        cout << endl
        << "Masukkan username akun yang di unfollow : ";
        string x; cin >> x; cin.ignore();
        adrP P = findElmP(L, x);
        if(P == NULL) {
            cout << "Akun tidak ditemukan" << endl;
        } else {
            cout << "Masukkan akun yang unfollow : ";
            infotypeC y; cin >> y.usn; cin.ignore();
            adrP Q = findElmP(L, y.usn);
            if(Q != NULL) {
                listC follower; createListC(follower);
                first(follower) = child(P);
                adrC C = findElmC(follower, y.usn);
                if(C != NULL) {
                    if(C == first(follower)) {
                        deleteFirstC(L, follower, C, P);
                    } else if(next(C) == first(follower)) {
                        deleteLastC(follower, C);
                    } else {
                        deleteAfterC(follower, C);
                    }
                    cout << "Akun berhasil unfollow" << endl;
                } else {
                    cout << "Akun tidak ditemukan" << endl;
                }
            } else {
                cout << "Akun tidak ditemukan" << endl;
            }
        }
    }
}

//----- Insert Akun Parent Tambahan -----//
void insertFirstP(listP &L, adrP P)
{
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void addP(listP &L)
{
    infotypeP newInfo;
    createAccP(newInfo);
    adrP P = alokasiP(newInfo);
    if(first(L) == NULL) {
        insertFirstP(L, P);
    } else {
        adrP sama = findElmP(L, info(P).usn);
        if(sama != NULL) {
            cout << "Akun dengan username tersebut sudah dibuat" <<endl;
        } else {
            insertFirstP(L, P);
        }
    }
}

//----- Counting -----//
int countParent(listP L)
{
    int i = 0;
    adrP P = first(L);
    while(P != NULL) {
        i++;
        P = next(P);
    }
    return i;
}
int countChild(listC L)
{
    adrC C = first(L);
    if(C != NULL) {
        int i = 1;
        while(next(C) != first(L)) {
            i++;
            C = next(C);
        }
        return i;
    }
    return 0;
}
int countFollowing(listP LP, string x)
{
    int i = 0;
    listC LC;
    adrP P = first(LP);
    while(P != NULL) {
        first(LC) = child(P);
        if(first(LC) == NULL || info(P).usn == x) {
            P = next(P);
        } else {
            adrC C = findElmC(LC, x);
            if(C != NULL) {
                i++;
            }
            P = next(P);
        }
    }
    return i;
}
void menuCount(listP L)
{
    int menu;
    cout<<"====== Pilih Akun Yang Akan Dihitung ======"<<endl
        <<"1. Banyak Akun"<<endl
        <<"2. Follower dari Akun Tertentu"<<endl
        <<"3. Following dari Akun Tertentu"<<endl;
    cout << "Pilihan : ";
    cin >> menu;
    if(menu == 1) {
        cout << "Banyak akun sekarang adalah : ";
        cout << countParent(L) << endl;
    } else if(menu == 2) {
        cout << "Masukkan username akun yang akan dihitung : ";
        string x; cin >> x; adrP P = findElmP(L, x);
        if(P != NULL) {
            listC follower; createListC(follower); first(follower) = child(P);
            cout << endl << "Banyak follower akun dari " << x << " adalah " << countChild(follower) << endl;
        } else {
            cout << endl << "Akun Tidak Ditemukan" << endl;
        }
    } else if(menu == 3) {
        cout << "Masukkan username akun yang akan dihitung : ";
        string x; cin >> x; adrP P = findElmP(L, x);
        if(P != NULL) {
            cout << endl << "Banyak following akun dari " << x << " adalah " << countFollowing(L, x) << endl;
        } else {
            cout << endl << "Akun Tidak Ditemukan" << endl;
        }
    }
}

//----- Delete Akun ------//
void deact(listP &L)
{
    cout << "Masukkan username akun yang akan dihapus : ";
    string deleted; cin >> deleted;
    adrP P = findElmP(L, deleted);
    //hapus parent nya
    deleteParentbyUsn(L, P);
    //hapus child nya di setiap parent
    deleteChildbyUsn(L, deleted);
}

