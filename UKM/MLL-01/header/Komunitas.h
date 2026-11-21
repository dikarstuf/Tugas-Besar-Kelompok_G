#ifndef KOMUNITAS_H_INCLUDED
#define KOMUNITAS_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

// CHILD : Komunitas (kode komunitas, nama, kategori)
struct Komunitas
{
    string kode;
    string nama;
    string kategori;
};

typedef Komunitas infotypeKom;         // variabel alias untuk infor
typedef  struct elmKomunitas *addressKom;   // variabel alias untuk pointer

// kerangka dari elemen list
struct elmKomunitas
{
    infotypeKom info;
    addressKom next;
};

// kerangka dari list
struct ListKomunitas
{
    addressKom first;
};

// pengecekan apakah list kosong
bool isEmpty(const ListKomunitas &LKom);
/* I.S. list LKom terdefinisi
   F.S. true jika list kosong dan false jika tidak kosong */

// pembuatan list kosong
void CreateList(ListKomunitas &LKom);
/* I.S. ~
   F.S. terbentuk list kosong */

// manajemen memori
addressKom createElemen(infotypeKom x);
/* I.S. info komunitas x terdefinisi
   F.S. mengembalikan alamat elemen berisi x dengan next NULL */

void dealokasi(addressKom &P);
/* I.S. pointer P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

// pencarian sebuah elemen list
addressKom findElm(const ListKomunitas &LKom, const string &kodeKomunitas);
/* I.S. list LKom dan kode komunitas terdefinisi
   F.S. mengembalikan alamat elemen komunitas yang cocok atau NULL jika tidak ditemukan
*/

// penambahan elemen *
void insertFirst(ListKomunitas &LKom, addressKom P);
/* I.S. terdefinisi list LKom yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada awal list */

void insertAfter(ListKomunitas &LKom, addressKom Prec, addressKom P);
/* I.S. terdefinisi list LKom yang mungkin kosong, elemen list P dan elemn list prec
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

void insertLast(ListKomunitas &LKom, addressKom P);
/* I.S. terdefinisi list LKom yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada akhir list */

// penghapusan sebuah elemen
void deleteFirst(ListKomunitas &LKom, addressKom &P);
/* I.S. terdefinisi list LKom yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen pertama list
        yang akan dihapus dan elemen list selanjutnya akan menjadi
        elemenlist pertama atau tidak ada elemen list pertama*/

void deleteLast(ListKomunitas &LKom, addressKom &P);
/* I.S. terdefinisi list LKom yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen terakhir list
        yang akan dihapus dan elemen list sebelumnya akan menjadi
        elemenlist terakhir atau tidak ada elemen list terakhir */

void deleteAfter(ListKomunitas &LKom, addressKom Prec, addressKom &P);
/* I.S. terdefinisi list LKom yang mungkin kosong, elemen list P dan elemn list prec
   F.S. P adalah alamat dari alamat elemen list setelah prec
        yang akan dihapus dan elemen list setelah p akan terhubung
        langsung dengan prec atau tidak ada elemen list setelahnya */

void printInfo(const ListKomunitas &LKom);
/* I.S. terdefinisi list LKom yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

infotypeKom inputKomunitas();
/* I.S. ~
   F.S. meminta data komunitas dari user */

#endif // KOMUNITAS_H_INCLUDED