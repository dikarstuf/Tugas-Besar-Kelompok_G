#ifndef KHUSUS_H_INCLUDED
#define KHUSUS_H_INCLUDED
#include "../../MLL-01/header/keanggotaan.h"
#include "../../MLL-01/header/mahasiswa.h"
#include "../../MLL-01/header/komunitas.h"
#include "../../BST/header/aktivitasBST.h"

void khusus1(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. -
   F.S. Melakukan pencatatan aktivitas mahasiswa dengan memilih mahasiswa dan komunitas
        yang diikuti (mahasiswa harus tergabung dalam komunitas tersebut).
*/

void khusus2(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. -
   F.S. Menyimpan aktivitas mahasiswa ke BST berdasarkan id aktivitas (unik dan acak).
*/

void khusus3(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. -
   F.S. Menampilkan daftar komunitas yang diikuti mahasiswa beserta seluruh aktivitas
        dan poin keaktifan yang diperoleh pada tiap komunitas.
*/

void khusus4(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. -
   F.S. Menghitung total poin keaktifan mahasiswa berdasarkan seluruh aktivitas
        yang tercatat pada BST.
*/

#endif // KHUSUS_H_INCLUDED