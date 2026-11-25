#ifndef PENAWARAN_H_INCLUDED
#define PENAWARAN_H_INCLUDED
#include "menu.h"
#include <string>
#include <iostream>

using namespace std;

// RELASI : Penawaran Menu (harga, stok, status) -> DOUBLE LINKED LIST
// status berisi salah satu dari: "tersedia", "habis", "PO"
struct Penawaran
{
    int harga;
    int stok;
    string status;
};

typedef Penawaran infotypePenawaran;                // variabel alias untuk info
typedef struct elmPenawaran *addressPenawaran;      // variabel alias untuk pointer

// kerangka dari elemen list
struct elmPenawaran
{
    infotypePenawaran info;
    addressPenawaran next;
    addressPenawaran prev;
    addressMenu pMenu;          // menunjuk elemen menu yang ditawarkan
};

// kerangka dari list
struct ListPenawaran
{
    addressPenawaran first;
    addressPenawaran last;
};

// pengecekan apakah list kosong
bool isEmpty(const ListPenawaran &LP);
/* I.S. list LP terdefinisi
   F.S. true jika list kosong dan false jika tidak kosong */

// pembuatan list kosong
void CreateList(ListPenawaran &LP);
/* I.S. ~
   F.S. terbentuk list kosong (first = NULL, last = NULL) */

// manajemen memori
addressPenawaran createElemen(infotypePenawaran x, addressMenu pM);
/* I.S. info penawaran x dan alamat menu pM terdefinisi
   F.S. mengembalikan alamat elemen penawaran berisi x, next dan prev NULL,
        dan pMenu menunjuk pM */

void dealokasi(addressPenawaran &P);
/* I.S. pointer P terdefinisi
   F.S. elemen penawaran di-dealokasi; elemen menu yang ditunjuk tidak ikut dihapus */

// pencarian sebuah elemen list
addressPenawaran findElm(const ListPenawaran &LP, const string &idMenu);
/* I.S. list LP milik seorang penjual dan id menu terdefinisi
   F.S. mengembalikan alamat elemen penawaran yang menunjuk menu tersebut
        atau NULL jika tidak ditemukan */

// penambahan elemen
void insertFirst(ListPenawaran &LP, addressPenawaran P);
/* I.S. terdefinisi list LP yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada awal list */

void insertAfter(ListPenawaran &LP, addressPenawaran Prec, addressPenawaran P);
/* I.S. terdefinisi list LP yang mungkin kosong, elemen list P dan elemen list Prec
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec
        (next dan prev kedua sisi diperbarui; last diperbarui jika Prec elemen terakhir) */

void insertLast(ListPenawaran &LP, addressPenawaran P);
/* I.S. terdefinisi list LP yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada akhir list */

// penghapusan sebuah elemen
void deleteFirst(ListPenawaran &LP, addressPenawaran &P);
/* I.S. terdefinisi list LP yang mungkin kosong
   F.S. P adalah alamat elemen pertama list yang dilepas;
        elemen selanjutnya menjadi elemen pertama atau list menjadi kosong */

void deleteLast(ListPenawaran &LP, addressPenawaran &P);
/* I.S. terdefinisi list LP yang mungkin kosong
   F.S. P adalah alamat elemen terakhir list yang dilepas;
        elemen sebelumnya menjadi elemen terakhir atau list menjadi kosong */

void deleteAfter(ListPenawaran &LP, addressPenawaran Prec, addressPenawaran &P);
/* I.S. terdefinisi list LP yang mungkin kosong dan elemen list Prec
   F.S. P adalah alamat elemen setelah Prec yang dilepas;
        elemen setelah P terhubung langsung dengan Prec (dua arah) */

void printInfo(const ListPenawaran &LP);
/* I.S. terdefinisi list LP yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

infotypePenawaran inputPenawaran();
/* I.S. ~
   F.S. meminta data penawaran dari user */

#endif // PENAWARAN_H_INCLUDED