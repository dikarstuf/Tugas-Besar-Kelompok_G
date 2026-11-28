#include "dummy.h"

void dummyPenjual(Pofood &P) {
    insertPenjual(P, {"P01", "Dapur Sari", "081200000001"});
    insertPenjual(P, {"P02", "Kedai Bima", "081200000002"});
    insertPenjual(P, {"P03", "Jajan Rara", "081200000003"});
    insertPenjual(P, {"P04", "Warung Dito", "081200000004"});
    insertPenjual(P, {"P05", "Manis Lala", "081200000005"});
}

void dummyMenu(Pofood &P) {
    insertMenu(P, {"M01", "Dimsum Mentai", "Camilan"});
    insertMenu(P, {"M02", "Dessert Box Cokelat", "Dessert"});
    insertMenu(P, {"M03", "Seblak", "Makanan Berat"});
    insertMenu(P, {"M04", "Croffle", "Dessert"});
    insertMenu(P, {"M05", "Rice Bowl Ayam", "Makanan Berat"});
    insertMenu(P, {"M06", "Cireng Isi", "Camilan"});
}

void dummyPenawaran(Pofood &P) {
    //                             harga, stok, status
    insertRelasi(P, "P01", "M01", {25000, 30, "tersedia"});
    insertRelasi(P, "P01", "M05", {22000, 20, "tersedia"});
    insertRelasi(P, "P02", "M01", {23000, 25, "PO"});
    insertRelasi(P, "P02", "M03", {18000, 15, "tersedia"});
    insertRelasi(P, "P03", "M03", {16000, 10, "tersedia"});
    insertRelasi(P, "P03", "M06", {12000, 40, "tersedia"});
    insertRelasi(P, "P04", "M05", {20000, 18, "PO"});
    insertRelasi(P, "P04", "M06", {13000,  0, "habis"});
    insertRelasi(P, "P05", "M02", {35000, 12, "PO"});
    insertRelasi(P, "P05", "M04", {17000, 24, "tersedia"});
}

void dummyPesanan(Pofood &P) {
    // memakai buatPesanan agar stok dan total harga otomatis diperbarui.
    // Urutan jumlah sengaja diacak supaya BST tidak miring ke satu sisi.
    buatPesanan(P, "Andi",  "P01", "M01",  5, "lunas",       "diproses");
    buatPesanan(P, "Budi",  "P02", "M03",  3, "belum bayar", "diproses");
    buatPesanan(P, "Citra", "P05", "M02",  8, "lunas",       "dikirim");
    buatPesanan(P, "Andi",  "P03", "M06",  2, "lunas",       "diambil");
    buatPesanan(P, "Dewi",  "P04", "M05",  4, "belum bayar", "diproses");
    buatPesanan(P, "Eka",   "P01", "M05",  6, "lunas",       "dikirim");
    buatPesanan(P, "Budi",  "P02", "M01", 10, "lunas",       "diproses");
}

void isiDummy(Pofood &P) {
    dummyPenjual(P);
    dummyMenu(P);
    dummyPenawaran(P);
    dummyPesanan(P);
}