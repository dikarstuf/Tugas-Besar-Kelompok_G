#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
#include "keanggotaan.h"
#include <string>
#include <iostream>

using namespace std;

// PARENT : Mahasiswa (NIM, nama, prodi, angkatan)
struct Mahasiswa
{
    string nim;
    string nama;
    string prodi;
    int angkatan;
};

typedef Mahasiswa infotypeM;         // variabel alias untuk infor
typedef  struct elmMahasiswa *addressM;   // variabel alias untuk pointer

// kerangka dari elemen list
struct elmMahasiswa
{
    infotypeM info;
    ListKeanggotaan LK;
    addressM next;
    addressM prev;
};

// kerangka dari list
struct ListMahasiswa
{
    addressM first;
    addressM last;
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
   F.S. mengembalikan alamat elemen berisi x dengan prev/next NULL
        dan daftar keanggotaan dalam keadaan kosong */

void dealokasi(addressM &P);
/* I.S. pointer P terdefinisi
   F.S. elemen mahasiswa dan seluruh elemen keanggotaan relasinya di-dealokasi;
        elemen komunitas yang dirujuk tidak ikut dihapus */

// pencarian sebuah elemen list
addressM findElm(const ListMahasiswa &LM, const string &nim);
/* I.S. list LM dan NIM terdefinisi
   F.S. mengembalikan alamat elemen mahasiswa yang cocok atau NULL jika tidak ditemukan
*/

// penambahan elemen *
void insertFirst(ListMahasiswa &LM, addressM P);
/* I.S. terdefinisi list LM yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada awal list */

void insertAfter(ListMahasiswa &LM, addressM Prec, addressM P);
/* I.S. terdefinisi list LM yang mungkin kosong, elemen list P dan elemn list prec
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

void insertLast(ListMahasiswa &LM, addressM P);
/* I.S. terdefinisi list LM yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada akhir list */

// penghapusan sebuah elemen
void deleteFirst(ListMahasiswa &LM, addressM &P);
/* I.S. terdefinisi list LM yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen pertama list
        yang akan dihapus dan elemen list selanjutnya akan menjadi
        elemenlist pertama atau tidak ada elemen list pertama*/

void deleteLast(ListMahasiswa &LM, addressM &P);
/* I.S. terdefinisi list LM yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen terakhir list
        yang akan dihapus dan elemen list sebelumnya akan menjadi
        elemenlist terakhir atau tidak ada elemen list terakhir */

void deleteAfter(ListMahasiswa &LM, addressM Prec, addressM &P);
/* I.S. terdefinisi list LM yang mungkin kosong, elemen list P dan elemn list prec
   F.S. P adalah alamat dari alamat elemen list setelah prec
        yang akan dihapus dan elemen list setelah p akan terhubung
        langsung dengan prec atau tidak ada elemen list setelahnya */

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