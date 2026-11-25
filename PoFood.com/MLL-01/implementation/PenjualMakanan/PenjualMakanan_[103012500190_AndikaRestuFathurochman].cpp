#include "../header/PenjualMakanan.h"

bool isEmpty(const ListPenjual &LPj)
{
    return LPj.first == NULL;
}

void CreateList(ListPenjual &LPj)
{
    LPj.first = NULL;
}

addressPenjual createElemen(infotypePenjual x)
{
    addressPenjual P = new elmPenjual;
    P->info = x;
    P->next = NULL;
    CreateList(P->LP);
    return P;
}

void dealokasi(addressPenjual &P)
{
    addressPenawaran K;
    while (!isEmpty(P->LP))
    {
        deleteFirst(P->LP, K);
        dealokasi(K);
    }
    delete P;
    P = NULL;
}

addressPenjual findElm(const ListPenjual &LPj, const string &idPenjual)
{
    addressPenjual P = LPj.first;
    while (P != NULL && P->info.idPenjual != idPenjual)
    {
        P = P->next;
    }
    return P;
}

void insertFirst(ListPenjual &LPj, addressPenjual P)
{
    P->next = LPj.first;
    LPj.first = P;
}

void insertAfter(ListPenjual &LPj, addressPenjual Prec, addressPenjual P)
{
    if (Prec == NULL)
    {
        insertFirst(LPj, P);
    }
    else
    {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(ListPenjual &LPj, addressPenjual P)
{
    if (isEmpty(LPj))
    {
        insertFirst(LPj, P);
    }
    else
    {
        addressPenjual Q = LPj.first;
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirst(ListPenjual &LPj, addressPenjual &P)
{
    if (isEmpty(LPj))
    {
        P = NULL;
    }
    else
    {
        P = LPj.first;
        LPj.first = P->next;
        P->next = NULL;
    }
}

void deleteLast(ListPenjual &LPj, addressPenjual &P)
{
    if (isEmpty(LPj))
    {
        P = NULL;
    }
    else if (LPj.first->next == NULL)
    {
        deleteFirst(LPj, P);
    }
    else
    {
        addressPenjual Q = LPj.first;
        while (Q->next->next != NULL)
        {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

void deleteAfter(ListPenjual &LPj, addressPenjual Prec, addressPenjual &P)
{
    if (Prec == NULL)
    {
        deleteFirst(LPj, P);
    }
    else if (Prec->next == NULL)
    {
        P = NULL;
    }
    else
    {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

void printInfo(const ListPenjual &LPj)
{
    if (isEmpty(LPj))
    {
        cout << "(List penjual kosong)" << endl;
    }
    else
    {
        addressPenjual P = LPj.first;
        int i = 1;
        while (P != NULL)
        {
            cout << i << ". [" << P->info.idPenjual << "] " << P->info.nama
                 << " | Kontak: " << P->info.kontak << endl;
            printInfo(P->LP);
            i++;
            P = P->next;
        }
    }
}

bool isMenuDitawarkan(const ListPenjual &LPj, addressMenu PM)
{
    bool ditawarkan = false;
    addressPenjual P = LPj.first;
    while (P != NULL && !ditawarkan)
    {
        addressPenawaran K = P->LP.first;
        while (K != NULL && !ditawarkan)
        {
            if (K->pMenu == PM)
            {
                ditawarkan = true;
            }
            K = K->next;
        }
        P = P->next;
    }
    return ditawarkan;
}

/* subprogram bantu internal: menambah satu penawaran ke penjual idPenjual */
static void tambahPenawaran(ListPenjual &LPj, const ListMenu &LM, const string &idPenjual,
                            const string &idMenu, int harga, int stok, const string &status)
{
    addressPenjual PJ = findElm(LPj, idPenjual);
    addressMenu PM = findElm(LM, idMenu);
    if (PJ != NULL && PM != NULL)
    {
        insertLast(PJ->LP, createElemen(Penawaran{harga, stok, status}, PM));
    }
}

void buatDataDummy(ListPenjual &LPj, ListMenu &LM)
{
    // 5 penjual (parent)
    insertLast(LPj, createElemen(Penjual{"P01", "Warung Bu Sri",     "081234567801"}));
    insertLast(LPj, createElemen(Penjual{"P02", "Dapur Mama Rina",   "081234567802"}));
    insertLast(LPj, createElemen(Penjual{"P03", "Kedai Pak Joko",    "081234567803"}));
    insertLast(LPj, createElemen(Penjual{"P04", "Cemilan Nusantara", "081234567804"}));
    insertLast(LPj, createElemen(Penjual{"P05", "Pofood Kitchen",    "081234567805"}));

    // 5 menu (child)
    insertLast(LM, createElemen(Menu{"M01", "Nasi Goreng Spesial", "Makanan Berat"}));
    insertLast(LM, createElemen(Menu{"M02", "Ayam Geprek",         "Makanan Berat"}));
    insertLast(LM, createElemen(Menu{"M03", "Es Teh Jumbo",        "Minuman"}));
    insertLast(LM, createElemen(Menu{"M04", "Brownies Panggang",   "Dessert"}));
    insertLast(LM, createElemen(Menu{"M05", "Dimsum Mentai",       "Makanan Ringan"}));

    // 10 penawaran (relasi): satu menu bisa ditawarkan beberapa penjual dengan harga berbeda
    tambahPenawaran(LPj, LM, "P01", "M01", 15000, 20, "tersedia");
    tambahPenawaran(LPj, LM, "P01", "M02", 18000, 15, "tersedia");
    tambahPenawaran(LPj, LM, "P02", "M01", 17000, 10, "tersedia");
    tambahPenawaran(LPj, LM, "P02", "M04", 25000,  0, "habis");
    tambahPenawaran(LPj, LM, "P03", "M02", 16000, 12, "PO");
    tambahPenawaran(LPj, LM, "P03", "M03",  8000, 30, "tersedia");
    tambahPenawaran(LPj, LM, "P04", "M04", 23000,  8, "PO");
    tambahPenawaran(LPj, LM, "P04", "M05", 20000, 25, "tersedia");
    tambahPenawaran(LPj, LM, "P05", "M03",  7500, 40, "tersedia");
    tambahPenawaran(LPj, LM, "P05", "M05", 22000,  0, "habis");
}

infotypePenjual inputPenjual()
{
    infotypePenjual x;
    cout << "ID penjual : ";
    getline(cin >> ws, x.idPenjual);
    cout << "Nama       : ";
    getline(cin, x.nama);
    cout << "Kontak     : ";
    getline(cin, x.kontak);
    return x;
}