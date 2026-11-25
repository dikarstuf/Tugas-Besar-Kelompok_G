#ifndef KEANGGOTAAN_H_INCLUDED
#define KEANGGOTAAN_H_INCLUDED
#include "komunitas.h"
#include <string>
#include <iostream>

using namespace std;

// RELASI : Keanggotaan (tanggal bergabung, jabatan, status anggota)
//          -> DOUBLE LINKED LIST
struct Keanggotaan
{
    string tanggalBergabung;
    string jabatan;
    string statusAnggota;
};

typedef Keanggotaan infotypeKA;                 // variabel alias untuk info
typedef struct elmKeanggotaan *addressKA;       // variabel alias untuk pointer

// kerangka dari elemen list
struct elmKeanggotaan
{
    infotypeKA info;
    addressKA next;
    addressKA prev;
    addressKom pKomunitas;      // menunjuk elemen komunitas
};

// kerangka dari list
struct ListKeanggotaan
{
    addressKA first;
    addressKA last;
};

// pengecekan apakah list kosong
bool isEmpty(const ListKeanggotaan &LK);
/* I.S. list LK terdefinisi
   F.S. true jika list kosong dan false jika tidak kosong */

// pembuatan list kosong
void CreateList(ListKeanggotaan &LK);
/* I.S. ~
   F.S. terbentuk list kosong (first = NULL, last = NULL) */

// manajemen memori
addressKA createElemen(infotypeKA x, addressKom pKom);
/* I.S. info keanggotaan x dan alamat komunitas terdefinisi
   F.S. mengembalikan alamat elemen keanggotaan berisi x, next dan prev NULL,
        dan pKomunitas menunjuk pKom */

void dealokasi(addressKA &P);
/* I.S. pointer P terdefinisi
   F.S. elemen keanggotaan di-dealokasi; elemen komunitas yang ditunjuk tidak ikut dihapus */

// pencarian sebuah elemen list
addressKA findElm(const ListKeanggotaan &LK, const string &kodeKomunitas);
/* I.S. list LK milik mahasiswa dan kode komunitas terdefinisi
   F.S. mengembalikan alamat elemen keanggotaan yang menunjuk komunitas tersebut
        atau NULL jika tidak ditemukan */

// penambahan elemen
void insertFirst(ListKeanggotaan &LK, addressKA P);
/* I.S. terdefinisi list LK yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada awal list */

void insertAfter(ListKeanggotaan &LK, addressKA Prec, addressKA P);
/* I.S. terdefinisi list LK yang mungkin kosong, elemen list P dan elemen list Prec
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec
        (next dan prev kedua sisi diperbarui; last diperbarui jika Prec elemen terakhir) */

void insertLast(ListKeanggotaan &LK, addressKA P);
/* I.S. terdefinisi list LK yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada akhir list */

// penghapusan sebuah elemen
void deleteFirst(ListKeanggotaan &LK, addressKA &P);
/* I.S. terdefinisi list LK yang mungkin kosong
   F.S. P adalah alamat elemen pertama list yang dilepas;
        elemen selanjutnya menjadi elemen pertama atau list menjadi kosong */

void deleteLast(ListKeanggotaan &LK, addressKA &P);
/* I.S. terdefinisi list LK yang mungkin kosong
   F.S. P adalah alamat elemen terakhir list yang dilepas;
        elemen sebelumnya menjadi elemen terakhir atau list menjadi kosong */

void deleteAfter(ListKeanggotaan &LK, addressKA Prec, addressKA &P);
/* I.S. terdefinisi list LK yang mungkin kosong dan elemen list Prec
   F.S. P adalah alamat elemen setelah Prec yang dilepas;
        elemen setelah P terhubung langsung dengan Prec (dua arah) */

void printInfo(const ListKeanggotaan &LK);
/* I.S. terdefinisi list LK yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

infotypeKA inputKeanggotaan();
/* I.S. ~
   F.S. meminta data keanggotaan dari user */

#endif // KEANGGOTAAN_H_INCLUDED