#ifndef AKTIVITASBST_H_INCLUDED
#define AKTIVITASBST_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

// BST : Aktivitas mahasiswa (id aktivitas, NIM, kode komunitas, nama kegiatan, poin keaktifan)
// key BST : idAktivitas
struct Aktivitas
{
    int idAktivitas;
    string nim;
    string kodeKomunitas;
    string namaKegiatan;
    int poinKeaktifan;
};

typedef Aktivitas infotypeA;         // variabel alias untuk infor
typedef  struct nodeAktivitas *addressA;   // variabel alias untuk pointer

// kerangka dari elemen node
struct nodeAktivitas
{
    infotypeA info;
    addressA left;
    addressA right;
};

// kerangka dari BST
struct BST
{
    addressA root;
};

// pengecekan apakah BST kosong
bool isEmpty(const BST &T);
/* I.S. BST T terdefinisi
   F.S. true jika BST kosong dan false jika tidak kosong */

// pembuatan BST kosong
void CreateBST(BST &T);
/* I.S. ~
   F.S. terbentuk BST kosong */

// manajemen memori
addressA createElemen(infotypeA x);
/* I.S. info aktivitas x terdefinisi
   F.S. mengembalikan alamat node berisi x dengan anak kiri dan kanan NULL */

void dealokasi(addressA &P);
/* I.S. pointer P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

// pencarian sebuah elemen node
addressA findNode(const BST &T, int idAktivitas);
/* I.S. BST T dan id aktivitas terdefinisi
   F.S. mengembalikan alamat node yang cocok atau NULL jika tidak ditemukan */

// penambahan elemen
void insertNode(BST &T, addressA P);
/* I.S. terdefinisi BST T yang mungkin kosong dan elemen node P
   F.S. menempatkan elemen beralamat P berdasarkan key idAktivitas
        (id lebih kecil ke kiri, id lebih besar ke kanan);
        node tidak ditambahkan jika id sudah ada */

// penghapusan node yang sudah diketahui alamatnya
void deleteNode(BST &T, addressA P);
/* I.S. terdefinisi BST T yang mungkin kosong dan elemen node P
   F.S. P adalah alamat dari elemen yang akan dihapus.
        elemen lain menggantikan posisi elemen P yang dihapus
        sesuai aturan BST */

void deleteAktivitas(BST &T, int idAktivitas);
/* I.S. terdefinisi BST T dan id aktivitas
   F.S. node dengan id yang cocok dihapus jika ditemukan */

void printInOrder(const BST &T);
/* I.S. terdefinisi BST T
   F.S. seluruh aktivitas ditampilkan dengan traversal in-order */

void printPreOrder(const BST &T);
/* I.S. terdefinisi BST T
   F.S. seluruh aktivitas ditampilkan dengan traversal pre-order */

void printPostOrder(const BST &T);
/* I.S. terdefinisi BST T
   F.S. seluruh aktivitas ditampilkan dengan traversal post-order */

addressA findMin(const BST &T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan node dengan id aktivitas minimum atau NULL jika BST kosong */

addressA findMax(const BST &T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan node dengan id aktivitas maksimum atau NULL jika BST kosong */

int tinggiBST(const BST &T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan tinggi BST; tinggi pohon kosong adalah 0 */

int jumlahNode(const BST &T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan jumlah node dalam BST */

int totalPoin(const BST &T, const string &nim);
/* I.S. terdefinisi BST T dan NIM
   F.S. mengembalikan jumlah poin keaktifan seluruh aktivitas milik NIM tersebut */

infotypeA inputAktivitas();
/* I.S. ~
   F.S. meminta data aktivitas dari user */

#endif // AKTIVITASBST_H_INCLUDED