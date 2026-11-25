#include "../header/Menu.h"

bool isEmpty(const ListMenu &LM)
{
    return LM.first == NULL;
}

void CreateList(ListMenu &LM)
{
    LM.first = NULL;
}

addressMenu createElemen(infotypeMenu x)
{
    addressMenu P = new elmMenu;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(addressMenu &P)
{
    delete P;
    P = NULL;
}

addressMenu findElm(const ListMenu &LM, const string &idMenu)
{
    addressMenu P = LM.first;
    while (P != NULL && P->info.idMenu != idMenu)
    {
        P = P->next;
    }
    return P;
}

void insertFirst(ListMenu &LM, addressMenu P)
{
    P->next = LM.first;
    LM.first = P;
}

void insertAfter(ListMenu &LM, addressMenu Prec, addressMenu P)
{
    if (Prec == NULL)
    {
        insertFirst(LM, P);
    }
    else
    {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(ListMenu &LM, addressMenu P)
{
    if (isEmpty(LM))
    {
        insertFirst(LM, P);
    }
    else
    {
        addressMenu Q = LM.first;
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirst(ListMenu &LM, addressMenu &P)
{
    if (isEmpty(LM))
    {
        P = NULL;
    }
    else
    {
        P = LM.first;
        LM.first = P->next;
        P->next = NULL;
    }
}

void deleteLast(ListMenu &LM, addressMenu &P)
{
    if (isEmpty(LM))
    {
        P = NULL;
    }
    else if (LM.first->next == NULL)
    {
        deleteFirst(LM, P);
    }
    else
    {
        addressMenu Q = LM.first;
        while (Q->next->next != NULL)
        {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

void deleteAfter(ListMenu &LM, addressMenu Prec, addressMenu &P)
{
    if (Prec == NULL)
    {
        deleteFirst(LM, P);
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

void printInfo(const ListMenu &LM)
{
    if (isEmpty(LM))
    {
        cout << "(List menu kosong)" << endl;
    }
    else
    {
        addressMenu P = LM.first;
        int i = 1;
        while (P != NULL)
        {
            cout << i << ". [" << P->info.idMenu << "] " << P->info.namaMakanan
                 << " | Kategori: " << P->info.kategori << endl;
            i++;
            P = P->next;
        }
    }
}

infotypeMenu inputMenu()
{
    infotypeMenu x;
    cout << "ID menu       : ";
    getline(cin >> ws, x.idMenu);
    cout << "Nama makanan  : ";
    getline(cin, x.namaMakanan);
    cout << "Kategori      : ";
    getline(cin, x.kategori);
    return x;
}