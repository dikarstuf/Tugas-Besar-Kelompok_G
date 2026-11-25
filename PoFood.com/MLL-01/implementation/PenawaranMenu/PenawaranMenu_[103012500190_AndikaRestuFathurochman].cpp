#include "../../header/matakuliah.h"
#include "../header/penawaran.h"

bool isEmpty(const ListPenawaran &LP)
{
    return LP.first == NULL;
}

void CreateList(ListPenawaran &LP)
{
    LP.first = NULL;
    LP.last = NULL;
}

addressPenawaran createElemen(infotypePenawaran x, addressMenu pM)
{
    addressPenawaran P = new elmPenawaran;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    P->pMenu = pM;
    return P;
}

void dealokasi(addressPenawaran &P)
{
    delete P;
    P = NULL;
}

addressPenawaran findElm(const ListPenawaran &LP, const string &idMenu)
{
    addressPenawaran P = LP.first;
    bool ketemu = false;
    while (P != NULL && !ketemu)
    {
        if (P->pMenu != NULL && P->pMenu->info.idMenu == idMenu)
        {
            ketemu = true;
        }
        else
        {
            P = P->next;
        }
    }
    return P;
}

void insertFirst(ListPenawaran &LP, addressPenawaran P)
{
    if (isEmpty(LP))
    {
        LP.first = P;
        LP.last = P;
    }
    else
    {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertLast(ListPenawaran &LP, addressPenawaran P)
{
    if (isEmpty(LP))
    {
        insertFirst(LP, P);
    }
    else
    {
        P->prev = LP.last;
        LP.last->next = P;
        LP.last = P;
    }
}

void insertAfter(ListPenawaran &LP, addressPenawaran Prec, addressPenawaran P)
{
    if (Prec == NULL)
    {
        insertFirst(LP, P);
    }
    else if (Prec == LP.last)
    {
        insertLast(LP, P);
    }
    else
    {
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next->prev = P;
        Prec->next = P;
    }
}

void deleteFirst(ListPenawaran &LP, addressPenawaran &P)
{
    if (isEmpty(LP))
    {
        P = NULL;
    }
    else if (LP.first == LP.last)
    {
        P = LP.first;
        LP.first = NULL;
        LP.last = NULL;
    }
    else
    {
        P = LP.first;
        LP.first = P->next;
        LP.first->prev = NULL;
        P->next = NULL;
    }
}

void deleteLast(ListPenawaran &LP, addressPenawaran &P)
{
    if (isEmpty(LP))
    {
        P = NULL;
    }
    else if (LP.first == LP.last)
    {
        deleteFirst(LP, P);
    }
    else
    {
        P = LP.last;
        LP.last = P->prev;
        LP.last->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfter(ListPenawaran &LP, addressPenawaran Prec, addressPenawaran &P)
{
    if (Prec == NULL)
    {
        deleteFirst(LP, P);
    }
    else if (Prec->next == NULL)
    {
        P = NULL;
    }
    else if (Prec->next == LP.last)
    {
        deleteLast(LP, P);
    }
    else
    {
        P = Prec->next;
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = NULL;
        P->prev = NULL;
    }
}

void printInfo(const ListPenawaran &LP)
{
    if (isEmpty(LP))
    {
        cout << "   (belum menawarkan menu)" << endl;
    }
    else
    {
        addressPenawaran P = LP.first;
        while (P != NULL)
        {
            cout << "   - ";
            if (P->pMenu != NULL)
            {
                cout << "[" << P->pMenu->info.idMenu << "] " << P->pMenu->info.namaMakanan;
            }
            else
            {
                cout << "(menu tidak ada)";
            }
            cout << " | Harga: Rp" << P->info.harga
                 << " | Stok: " << P->info.stok
                 << " | Status: " << P->info.status << endl;
            P = P->next;
        }
    }
}

infotypePenawaran inputPenawaran()
{
    infotypePenawaran x;
    cout << "Harga (Rp)                      : ";
    cin >> x.harga;
    cout << "Stok                            : ";
    cin >> x.stok;
    do
    {
        cout << "Status (tersedia / habis / PO)  : ";
        cin >> x.status;
    } while (x.status != "tersedia" && x.status != "habis" && x.status != "PO");
    return x;
}