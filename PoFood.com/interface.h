#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include "MLL-01/header/keanggotaan.h"
#include "MLL-01/header/mahasiswa.h"
#include "MLL-01/header/komunitas.h"
#include "BST/header/aktivitasBST.h"

void menu(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. list mahasiswa, list komunitas, dan BST terdefinisi
   F.S. menu utama ditampilkan dan pilihan pengguna diproses */

void menuFiturUmum(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. list mahasiswa, list komunitas, dan BST terdefinisi
   F.S. menu fitur umum ditampilkan dan pilihan pengguna diproses */

void menuFiturUmumKeanggotaan(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. list mahasiswa, list komunitas, dan BST terdefinisi
   F.S. menu keanggotaan ditampilkan dan pilihan pengguna diproses */

void menuFiturUmumMahasiswa(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. list mahasiswa, list komunitas, dan BST terdefinisi
   F.S. menu mahasiswa ditampilkan dan pilihan pengguna diproses */

void menuFiturUmumKomunitas(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. list mahasiswa, list komunitas, dan BST terdefinisi
   F.S. menu komunitas ditampilkan dan pilihan pengguna diproses */

void menuFiturUmumAktivitas(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. list mahasiswa, list komunitas, dan BST terdefinisi
   F.S. menu aktivitas (BST) ditampilkan dan pilihan pengguna diproses */

void menuFiturKhusus(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. list mahasiswa, list komunitas, dan BST terdefinisi
   F.S. menu fitur khusus ditampilkan dan pilihan pengguna diproses */

void menuFiturBonus(ListMahasiswa &LM, ListKomunitas &LKom, BST &T);
/* I.S. list mahasiswa, list komunitas, dan BST terdefinisi
   F.S. menu fitur bonus ditampilkan dan pilihan pengguna diproses */

#endif // INTERFACE_H_INCLUDED