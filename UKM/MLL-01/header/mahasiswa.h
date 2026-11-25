#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
#include "keanggotaan.h"
#include <string>
#include <iostream>

using namespace std;

// PARENT : Mahasiswa (NIM, nama, prodi, angkatan) -> SINGLE LINKED LIST
struct Mahasiswa
{
    string nim;
    string nama;
    string prodi;
    int angkatan;
};

typedef Mahasiswa infotypeM;                // variabel alias untuk info
typedef struct elmMahasiswa *addressM;      // variabel alias untuk pointer

// kerangka dari elemen list
struct elmMahasiswa
{
    infotypeM info;
    ListKeanggotaan LK;         // list relasi (DLL) milik mahasiswa ini
    addressM next;
};

// kerangka dari list
struct ListMahasiswa
{
    addressM first;
};

// pengecekan apakah list kosong
bool isEmpty(const ListMahasiswa &LM);
/* I.S. list LM terdefinisi
   F.S. true jika list kosong dan false jika tidak kosong */

void CreateList(ListMahasiswa &LM);
/* I.S. ~
   F.S. terbentuk list kosong */

// manajemen memori
addressM createElemen(infotypeM x);
/* I.S. info mahasiswa x terdefinisi
   F.S. mengembalikan alamat elemen berisi x dengan next NULL
        dan daftar keanggotaan dalam keadaan kosong */

void dealokasi(addressM &P);
/* I.S. pointer P terdefinisi
   F.S. elemen mahasiswa dan seluruh elemen keanggotaan relasinya di-dealokasi;
        elemen komunitas yang dirujuk tidak ikut dihapus */

// pencarian sebuah elemen list
addressM findElm(const ListMahasiswa &LM, const string &nim);
/* I.S. list LM dan NIM terdefinisi
   F.S. mengembalikan alamat elemen mahasiswa yang cocok atau NULL jika tidak ditemukan */

// penambahan elemen
void insertFirst(ListMahasiswa &LM, addressM P);
/* I.S. terdefinisi list LM yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada awal list */

void insertAfter(ListMahasiswa &LM, addressM Prec, addressM P);
/* I.S. terdefinisi list LM yang mungkin kosong, elemen list P dan elemen list Prec
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

void insertLast(ListMahasiswa &LM, addressM P);
/* I.S. terdefinisi list LM yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada akhir list */

// penghapusan sebuah elemen
void deleteFirst(ListMahasiswa &LM, addressM &P);
/* I.S. terdefinisi list LM yang mungkin kosong
   F.S. P adalah alamat elemen pertama list yang dilepas;
        elemen selanjutnya menjadi elemen pertama atau list menjadi kosong */

void deleteLast(ListMahasiswa &LM, addressM &P);
/* I.S. terdefinisi list LM yang mungkin kosong
   F.S. P adalah alamat elemen terakhir list yang dilepas;
        elemen sebelumnya menjadi elemen terakhir atau list menjadi kosong */

void deleteAfter(ListMahasiswa &LM, addressM Prec, addressM &P);
/* I.S. terdefinisi list LM yang mungkin kosong dan elemen list Prec
   F.S. P adalah alamat elemen setelah Prec yang dilepas;
        elemen setelah P terhubung langsung dengan Prec */

void printInfo(const ListMahasiswa &LM);
/* I.S. terdefinisi list LM yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

bool isKomunitasDirujuk(const ListMahasiswa &LM, addressKom PKom);
/* I.S. terdefinisi list mahasiswa dan alamat komunitas
   F.S. true jika komunitas masih direferensikan oleh keanggotaan mahasiswa */

infotypeM inputMahasiswa();
/* I.S. ~
   F.S. meminta data mahasiswa dari user */

#endif // MAHASISWA_H_INCLUDED