#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "pofood.h"


string inputTeks(string label);
int inputAngka(string label);         

void tampilMenuUtama();

void menuTambahPenjual(Pofood &P);
void menuTambahMenu(Pofood &P);
void menuTambahPenawaran(Pofood &P);
void menuHapusPenjual(Pofood &P);
void menuHapusMenu(Pofood &P);
void menuHapusPenawaran(Pofood &P);
void menuPesan(Pofood &P);
void menuPenawaranTermurah(Pofood P);
void menuRiwayat(Pofood P);

void jalankanAplikasi(Pofood &P);      

#endif