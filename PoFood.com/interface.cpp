#include "interface.h"
#include <cstdlib>

string inputTeks(string label) {
    string s;
    do {
        cout << label;
        if (!getline(cin, s)) exit(0);   // input ditutup
    } while (s.empty());
    return s;
}

int inputAngka(string label) {
    while (true) {
        string s = inputTeks(label);
        // maksimal 7 digit agar tidak overflow
        if (s.length() <= 7 && s.find_first_not_of("0123456789") == string::npos) {
            return atoi(s.c_str());
        }
        cout << "Masukkan angka 0 - 9999999.\n";
    }
}

static void hasil(bool sukses, string pesanGagal) {
    if (sukses) cout << "Berhasil.\n";
    else cout << "Gagal: " << pesanGagal << endl;
}

void tampilMenuUtama() {
    cout << "\n=============== POFOOD.COM ===============\n";
    cout << " 1. Tambah penjual\n";
    cout << " 2. Tambah menu\n";
    cout << " 3. Tambah penawaran menu\n";
    cout << " 4. Hapus penjual\n";
    cout << " 5. Hapus menu\n";
    cout << " 6. Hapus penawaran\n";
    cout << " 7. Tampilkan penjual\n";
    cout << " 8. Tampilkan menu\n";
    cout << " 9. Tampilkan penawaran per penjual\n";
    cout << "10. Buat pesanan pre-order\n";
    cout << "11. Tampilkan semua pesanan\n";
    cout << "12. Penjual dengan pendapatan tertinggi\n";
    cout << "13. Total transaksi aplikasi\n";
    cout << "14. Menu dengan pemesanan terbanyak\n";
    cout << "15. Penawaran termurah suatu menu\n";
    cout << "16. Riwayat transaksi pelanggan\n";
    cout << " 0. Keluar\n";
    cout << "==========================================\n";
}

void menuTambahPenjual(Pofood &P) {
    Penjual x;
    x.idPenjual = inputTeks("ID penjual : ");
    x.nama = inputTeks("Nama       : ");
    x.kontak = inputTeks("Kontak     : ");
    hasil(insertPenjual(P, x), "ID penjual sudah dipakai.");
}

void menuTambahMenu(Pofood &P) {
    Menu x;
    x.idMenu = inputTeks("ID menu      : ");
    x.namaMakanan = inputTeks("Nama makanan : ");
    x.kategori = inputTeks("Kategori     : ");
    hasil(insertMenu(P, x), "ID menu sudah dipakai.");
}

void menuTambahPenawaran(Pofood &P) {
    string idP = inputTeks("ID penjual : ");
    string idM = inputTeks("ID menu    : ");
    if (findPenjual(P, idP) == NULL || findMenu(P, idM) == NULL) {
        cout << "Gagal: penjual atau menu tidak ditemukan.\n";
        return;
    }
    Penawaran x;
    x.harga = inputAngka("Harga      : ");
    x.stok = inputAngka("Stok       : ");
    if (x.stok == 0) {
        x.status = "habis";
    } else {
        int pilih;
        do {
            pilih = inputAngka("Status (1. tersedia, 2. PO) : ");
        } while (pilih != 1 && pilih != 2);
        x.status = (pilih == 1) ? "tersedia" : "PO";
    }
    hasil(insertRelasi(P, idP, idM, x), "penawaran sudah ada.");
}

void menuHapusPenjual(Pofood &P) {
    string id = inputTeks("ID penjual : ");
    hasil(deletePenjual(P, id), "penjual tidak ditemukan.");
}

void menuHapusMenu(Pofood &P) {
    string id = inputTeks("ID menu : ");
    hasil(deleteMenu(P, id), "menu tidak ditemukan.");
}

void menuHapusPenawaran(Pofood &P) {
    string idP = inputTeks("ID penjual : ");
    string idM = inputTeks("ID menu    : ");
    hasil(deleteRelasi(P, idP, idM), "penawaran tidak ditemukan.");
}

void menuPesan(Pofood &P) {
    showPenawaran(P);
    cout << endl;
    string nama = inputTeks("Nama pelanggan : ");
    string idP = inputTeks("ID penjual     : ");
    string idM = inputTeks("ID menu        : ");

    adrRelasi r = findRelasi(P, idP, idM);
    if (r == NULL) {
        cout << "Gagal: penawaran tidak ditemukan.\n";
        return;
    }
    if (r->info.status == "habis") {
        cout << "Gagal: menu sedang habis.\n";
        return;
    }
    int jumlah = inputAngka("Jumlah pesanan : ");
    if (jumlah == 0 || jumlah > r->info.stok) {
        cout << "Gagal: jumlah harus 1 sampai " << r->info.stok << ".\n";
        return;
    }
    int bayar, kirim;
    do {
        bayar = inputAngka("Pembayaran (1. lunas, 2. belum bayar) : ");
    } while (bayar != 1 && bayar != 2);
    do {
        kirim = inputAngka("Pengiriman (1. diproses, 2. diambil, 3. dikirim) : ");
    } while (kirim < 1 || kirim > 3);

    string statusBayar = (bayar == 1) ? "lunas" : "belum bayar";
    string statusKirim = (kirim == 1) ? "diproses" : (kirim == 2) ? "diambil" : "dikirim";
    int total = jumlah * r->info.harga;

    bool sukses = buatPesanan(P, nama, idP, idM, jumlah, statusBayar, statusKirim);
    hasil(sukses, "pesanan tidak dapat diproses.");
    if (sukses) {
        cout << "Total harga : Rp" << total << endl;
        cout << "Sisa stok   : " << r->info.stok << endl;
    }
}

void menuPenawaranTermurah(Pofood P) {
    showMenu(P);
    string id = inputTeks("ID menu : ");
    showPenawaranTermurah(P, id);
}

void menuRiwayat(Pofood P) {
    string nama = inputTeks("Nama pelanggan : ");
    showRiwayatPelanggan(P, nama);
}

void jalankanAplikasi(Pofood &P) {
    int pilihan;
    do {
        tampilMenuUtama();
        pilihan = inputAngka("Pilih : ");
        cout << endl;
        switch (pilihan) {
            case 1:  menuTambahPenjual(P); break;
            case 2:  menuTambahMenu(P); break;
            case 3:  menuTambahPenawaran(P); break;
            case 4:  menuHapusPenjual(P); break;
            case 5:  menuHapusMenu(P); break;
            case 6:  menuHapusPenawaran(P); break;
            case 7:  showPenjual(P); break;
            case 8:  showMenu(P); break;
            case 9:  showPenawaran(P); break;
            case 10: menuPesan(P); break;
            case 11:
                if (P.root == NULL) cout << "Belum ada pesanan.\n";
                else showPesanan(P.root);
                break;
            case 12: showPendapatanTertinggi(P); break;
            case 13: showTotalTransaksi(P); break;
            case 14: showMenuTerlaris(P); break;
            case 15: menuPenawaranTermurah(P); break;
            case 16: menuRiwayat(P); break;
            case 0:  cout << "Terima kasih.\n"; break;
            default: cout << "Pilihan tidak tersedia.\n";
        }
    } while (pilihan != 0);
}