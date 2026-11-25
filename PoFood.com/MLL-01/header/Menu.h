#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

// CHILD : Menu (id menu, nama makanan, kategori) -> SINGLE LINKED LIST
// Catatan: Menu adalah katalog jenis menu, bukan satu porsi makanan individual.
//          Menu yang sama dapat ditawarkan oleh beberapa penjual.
struct Menu
{
    string idMenu;
    string namaMakanan;
    string kategori;
};

typedef Menu infotypeMenu;                  // variabel alias untuk info
typedef struct elmMenu *addressMenu;        // variabel alias untuk pointer

// kerangka dari elemen list
struct elmMenu
{
    infotypeMenu info;
    addressMenu next;
};

// kerangka dari list
struct ListMenu
{
    addressMenu first;
};

// pengecekan apakah list kosong
bool isEmpty(const ListMenu &LM);
/* I.S. list LM terdefinisi
   F.S. true jika list kosong dan false jika tidak kosong */

// pembuatan list kosong
void CreateList(ListMenu &LM);
/* I.S. ~
   F.S. terbentuk list kosong */

// manajemen memori
addressMenu createElemen(infotypeMenu x);
/* I.S. info menu x terdefinisi
   F.S. mengembalikan alamat elemen berisi x dengan next NULL */

void dealokasi(addressMenu &P);
/* I.S. pointer P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

// pencarian sebuah elemen list
addressMenu findElm(const ListMenu &LM, const string &idMenu);
/* I.S. list LM dan id menu terdefinisi
   F.S. mengembalikan alamat elemen menu yang cocok atau NULL jika tidak ditemukan */

// penambahan elemen
void insertFirst(ListMenu &LM, addressMenu P);
/* I.S. terdefinisi list LM yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada awal list */

void insertAfter(ListMenu &LM, addressMenu Prec, addressMenu P);
/* I.S. terdefinisi list LM yang mungkin kosong, elemen list P dan elemen list Prec
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

void insertLast(ListMenu &LM, addressMenu P);
/* I.S. terdefinisi list LM yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada akhir list */

// penghapusan sebuah elemen
void deleteFirst(ListMenu &LM, addressMenu &P);
/* I.S. terdefinisi list LM yang mungkin kosong
   F.S. P adalah alamat elemen pertama list yang dilepas;
        elemen selanjutnya menjadi elemen pertama atau list menjadi kosong */

void deleteLast(ListMenu &LM, addressMenu &P);
/* I.S. terdefinisi list LM yang mungkin kosong
   F.S. P adalah alamat elemen terakhir list yang dilepas;
        elemen sebelumnya menjadi elemen terakhir atau list menjadi kosong */

void deleteAfter(ListMenu &LM, addressMenu Prec, addressMenu &P);
/* I.S. terdefinisi list LM yang mungkin kosong dan elemen list Prec
   F.S. P adalah alamat elemen setelah Prec yang dilepas;
        elemen setelah P terhubung langsung dengan Prec */

void printInfo(const ListMenu &LM);
/* I.S. terdefinisi list LM yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

infotypeMenu inputMenu();
/* I.S. ~
   F.S. meminta data menu dari user */

#endif // MENU_H_INCLUDED