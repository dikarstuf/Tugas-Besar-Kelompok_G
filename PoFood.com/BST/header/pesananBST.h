#ifndef PESANANBST_H_INCLUDED
#define PESANANBST_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

// BST : Pesanan pre-order, key = jumlah pesanan
// (nama pelanggan, id penjual, id menu, jumlah pesanan, total harga,
//  status pembayaran, status pengambilan/pengiriman)
struct Pesanan
{
    string namaPelanggan;
    string idPenjual;
    string idMenu;
    int jumlahPesanan;              // KEY
    int totalHarga;
    string statusPembayaran;        // misal: "lunas" / "belum bayar"
    string statusPengambilan;       // misal: "menunggu" / "diambil" / "dikirim"
};

typedef Pesanan infotypePesanan;                // variabel alias untuk info
typedef struct elemenNode *addressNode;         // variabel alias untuk pointer

// kerangka dari node
struct elemenNode
{
    infotypePesanan info;
    addressNode left;
    addressNode right;
};

// kerangka dari tree
struct BST
{
    addressNode root;
};

/* Catatan key: jumlah pesanan TIDAK unik. Node dengan key sama
   disisipkan ke subtree KANAN (key sub-kiri < key node <= key sub-kanan). */

// pengecekan apakah tree kosong
bool isEmpty(const BST &T);
/* I.S. tree T terdefinisi
   F.S. true jika tree kosong dan false jika tidak kosong */

// pembuatan tree kosong
void CreateTree(BST &T);
/* I.S. ~
   F.S. terbentuk tree kosong (root = NULL) */

// manajemen memori
addressNode createNode(infotypePesanan x);
/* I.S. info pesanan x terdefinisi
   F.S. mengembalikan alamat node berisi x dengan left dan right NULL */

void dealokasi(addressNode &P);
/* I.S. pointer P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

void dealokasiTree(BST &T);
/* I.S. tree T terdefinisi
   F.S. seluruh node tree di-dealokasi dan tree menjadi kosong */

// penambahan node
void insertNode(BST &T, addressNode P);
/* I.S. tree T yang mungkin kosong dan node P terdefinisi
   F.S. node P tersisip pada posisi yang benar berdasarkan key jumlah pesanan */

// penghapusan node
void deleteNode(BST &T, int key, addressNode &P);
/* I.S. tree T yang mungkin kosong dan key terdefinisi
   F.S. satu node pertama yang ditemukan dengan key tersebut dilepas dari tree
        dan alamatnya dikembalikan di P (P = NULL jika key tidak ditemukan);
        struktur BST tetap valid (kasus 0, 1, dan 2 anak) */

// pencarian node
addressNode findNode(const BST &T, int key);
/* I.S. tree T yang mungkin kosong dan key terdefinisi
   F.S. mengembalikan alamat node pertama yang ditemukan dengan key tersebut
        atau NULL jika tidak ditemukan */

// penelusuran (traversal)
void inOrder(const BST &T);
/* I.S. tree T yang mungkin kosong
   F.S. menampilkan seluruh node secara in-order (kiri, akar, kanan) */

void preOrder(const BST &T);
/* I.S. tree T yang mungkin kosong
   F.S. menampilkan seluruh node secara pre-order (akar, kiri, kanan) */

void postOrder(const BST &T);
/* I.S. tree T yang mungkin kosong
   F.S. menampilkan seluruh node secara post-order (kiri, kanan, akar) */

// informasi tree
addressNode minNode(const BST &T);
/* I.S. tree T yang mungkin kosong
   F.S. mengembalikan alamat node dengan key terkecil atau NULL jika tree kosong */

addressNode maxNode(const BST &T);
/* I.S. tree T yang mungkin kosong
   F.S. mengembalikan alamat node dengan key terbesar atau NULL jika tree kosong */

int tinggi(const BST &T);
/* I.S. tree T yang mungkin kosong
   F.S. mengembalikan tinggi tree = jumlah EDGE pada lintasan terpanjang
        dari root ke leaf (sesuai definisi di materi Tree):
        tree kosong = -1, tree satu node = 0 */

int jumlahNode(const BST &T);
/* I.S. tree T yang mungkin kosong
   F.S. mengembalikan banyaknya node pada tree */

void printNode(addressNode P);
/* I.S. node P terdefinisi (tidak NULL)
   F.S. menampilkan seluruh info pesanan pada node P dalam satu entri */

// operasi tambahan untuk fungsional khusus dan bonus
int pendapatanPenjual(const BST &T, const string &idPenjual);
/* I.S. tree T yang mungkin kosong dan id penjual terdefinisi
   F.S. mengembalikan jumlah total harga seluruh pesanan milik penjual tersebut */

int totalTransaksi(const BST &T);
/* I.S. tree T yang mungkin kosong
   F.S. mengembalikan jumlah total harga seluruh pesanan pada tree */

int jumlahPesananMenu(const BST &T, const string &idMenu);
/* I.S. tree T yang mungkin kosong dan id menu terdefinisi
   F.S. mengembalikan total jumlah porsi yang dipesan untuk menu tersebut */

void printRiwayatPelanggan(const BST &T, const string &namaPelanggan);
/* I.S. tree T yang mungkin kosong dan nama pelanggan terdefinisi
   F.S. menampilkan seluruh pesanan milik pelanggan tersebut;
        menampilkan pesan jika tidak ada */

// data dummy dan input
void buatDataDummy(BST &T);
/* I.S. tree T terdefinisi (kosong)
   F.S. tree terisi data dummy minimal 10 node */

infotypePesanan inputPesanan();
/* I.S. ~
   F.S. meminta data pesanan dari user (total harga dihitung di luar fungsi ini) */

#endif // PESANANBST_H_INCLUDED