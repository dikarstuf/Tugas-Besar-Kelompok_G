#ifndef DUMMY_H_INCLUDED
#define DUMMY_H_INCLUDED
#include "MLL-01/header/keanggotaan.h"
#include "MLL-01/header/mahasiswa.h"
#include "MLL-01/header/komunitas.h"
#include "BST/header/aktivitasBST.h"

void dummyMahasiswa(ListMahasiswa &LM);
/* I.S. LM terdefinisi dan kosong
   F.S. LM berisi minimal 5 data mahasiswa */

void dummyKomunitas(ListKomunitas &LKom);
/* I.S. LKom terdefinisi dan kosong
   F.S. LKom berisi minimal 5 data komunitas */

void dummyKeanggotaan(ListMahasiswa &LM, ListKomunitas &LKom);
/* I.S. LM berisi 5 mahasiswa dan LKom berisi 5 komunitas
   F.S. daftar keanggotaan pada elemen mahasiswa berisi minimal 10 relasi ke komunitas */

void dummyAktivitas(BST &T);
/* I.S. T terdefinisi dan kosong
   F.S. T berisi minimal 10 data aktivitas mahasiswa */

#endif // DUMMY_H_INCLUDED