#ifndef PENJUAL_H_INCLUDED
#define PENJUAL_H_INCLUDED
#include "penawaran.h"
#include <string>
#include <iostream>

using namespace std;

// PARENT : Penjual Makanan (id penjual, nama, kontak) -> SINGLE LINKED LIST
struct Penjual
{
    string idPenjual;
    string nama;
    string kontak;
};

typedef Penjual infotypePenjual;                // variabel alias untuk info
typedef struct elmPenjual *addressPenjual;      // variabel alias untuk pointer

// kerangka dari elemen list
struct elmPenjual
{
    infotypePenjual info;
    ListPenawaran LP;           // list relasi (DLL) penawaran menu milik penjual ini
    addressPenjual next;
};

// kerangka dari list
struct ListPenjual
{
    addressPenjual first;
};

// pengecekan apakah list kosong
bool isEmpty(const ListPenjual &LPj);
/* I.S. list LPj terdefinisi
   F.S. true jika list kosong dan false jika tidak kosong */

// pembuatan list kosong
void CreateList(ListPenjual &LPj);
/* I.S. ~
   F.S. terbentuk list kosong */

// manajemen memori
addressPenjual createElemen(infotypePenjual x);
/* I.S. info penjual x terdefinisi
   F.S. mengembalikan alamat elemen berisi x dengan next NULL
        dan daftar penawaran dalam keadaan kosong */

void dealokasi(addressPenjual &P);
/* I.S. pointer P terdefinisi
   F.S. elemen penjual dan seluruh elemen penawaran relasinya di-dealokasi;
        elemen menu yang dirujuk tidak ikut dihapus */

// pencarian sebuah elemen list
addressPenjual findElm(const ListPenjual &LPj, const string &idPenjual);
/* I.S. list LPj dan id penjual terdefinisi
   F.S. mengembalikan alamat elemen penjual yang cocok atau NULL jika tidak ditemukan */

// penambahan elemen
void insertFirst(ListPenjual &LPj, addressPenjual P);
/* I.S. terdefinisi list LPj yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada awal list */

void insertAfter(ListPenjual &LPj, addressPenjual Prec, addressPenjual P);
/* I.S. terdefinisi list LPj yang mungkin kosong, elemen list P dan elemen list Prec
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

void insertLast(ListPenjual &LPj, addressPenjual P);
/* I.S. terdefinisi list LPj yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada akhir list */

// penghapusan sebuah elemen
void deleteFirst(ListPenjual &LPj, addressPenjual &P);
/* I.S. terdefinisi list LPj yang mungkin kosong
   F.S. P adalah alamat elemen pertama list yang dilepas;
        elemen selanjutnya menjadi elemen pertama atau list menjadi kosong */

void deleteLast(ListPenjual &LPj, addressPenjual &P);
/* I.S. terdefinisi list LPj yang mungkin kosong
   F.S. P adalah alamat elemen terakhir list yang dilepas;
        elemen sebelumnya menjadi elemen terakhir atau list menjadi kosong */

void deleteAfter(ListPenjual &LPj, addressPenjual Prec, addressPenjual &P);
/* I.S. terdefinisi list LPj yang mungkin kosong dan elemen list Prec
   F.S. P adalah alamat elemen setelah Prec yang dilepas;
        elemen setelah P terhubung langsung dengan Prec */

void printInfo(const ListPenjual &LPj);
/* I.S. terdefinisi list LPj yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua penjual beserta
        daftar penawaran menu miliknya */

bool isMenuDitawarkan(const ListPenjual &LPj, addressMenu PM);
/* I.S. terdefinisi list penjual dan alamat menu PM
   F.S. true jika menu PM masih ditawarkan oleh minimal satu penjual */

void buatDataDummy(ListPenjual &LPj, ListMenu &LM);
/* I.S. list LPj dan LM terdefinisi (kosong)
   F.S. terisi data dummy: minimal 5 penjual, 5 menu, dan 10 penawaran */

infotypePenjual inputPenjual();
/* I.S. ~
   F.S. meminta data penjual dari user */

#endif // PENJUAL_H_INCLUDED