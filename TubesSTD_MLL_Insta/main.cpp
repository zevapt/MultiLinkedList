#include "insta.h"

using namespace std;

int main()
{
    listP LP;
    createListP(LP);
    infotypeP dataP;
    bool menu = true;
    //bool menu = false;

    //TEST CASE AKUN PARENT
    /*dataP.usn = "zeva";
    P = alokasiP(dataP);
    insertFirstP(LP, P);

    dataP.usn = "ardy";
    P = alokasiP(dataP);
    insertFirstP(LP, P);

    dataP.usn = "dinar";
    P = alokasiP(dataP);
    insertFirstP(LP, P);

    dataP.usn = "verta";
    P = alokasiP(dataP);
    insertFirstP(LP, P);
    printInfoP(LP);*/

    ///SANDBOX
    /*P = findElmP(LP, "ardy");
    cout << info(next(P)).usn;
    printInfoPnC(LP);
    addC(LP);
    printInfoPnC(LP);
    */


    while(menu) {
        system("cls");
        cout << "===== TUGAS BESAR STRUKTUR DATA =====" <<endl;
        cout << "========== AMIN CEPE TEAM ===========" <<endl
         <<endl
         << "      1.  Insert Akun Baru"<<endl
         << "      2.  Follow Akun"<<endl // Berdasarkan username
         << "      3.  Unfollow Akun"<<endl // Berdasarkan username
         << "      4.  Print List Akun"<<endl
         << "      5.  Print List Akun dan Followernya"<<endl
         << "      6.  Print List Follower dari Akun Tertentu"<<endl
         << "      7.  Print List Following dari Akun Tertentu"<<endl
         << "      8.  Deactivate Akun"<<endl //Berdasarkan username
         << "      9.  Search Akun"<<endl //Berdasarkan usn
         << "      10. Search Follower dari Akun Tertentu"<<endl
         << "      11. Hitung Total Akun/Follower dari Akun Tertentu"<<endl
         << "      0.  EXIT"<<endl;
        cout << endl;
        cout << "Pilih Menu (Angka): "; int pil;
        cin >> pil; cin.ignore();
        if(pil == 1) {
            system("cls"); addP(LP); getch(); //aman
        } else if(pil == 2) {
            system("cls"); addC(LP); getch(); //aman
        } else if(pil == 3) {
            system("cls"); unfoll(LP); getch();//aman
        } else if(pil == 4) {
            system("cls"); printInfoP(LP); getch();//aman
        } else if(pil == 5) {
            system("cls"); printInfoPnC(LP); getch();//aman
        } else if(pil == 6) {
            system("cls"); printCertainP(LP); getch();//aman
        } else if(pil == 7) {
            system("cls"); printFollP(LP); getch();
        } else if(pil == 8) {
            system("cls"); deact(LP); getch(); //aman
        } else if(pil == 9) {
            system("cls"); searchParent(LP); getch(); //aman
        } else if(pil == 10) {
            system("cls"); searchChild(LP); getch(); //aman
        } else if(pil == 11) {
            system("cls"); menuCount(LP); getch(); //aman
        } else if(pil == 0) {
            system("cls"); cout << "terimakasih sudah menggunakan program ini\n";menu = false;
        }
    }
    return 0;
}
