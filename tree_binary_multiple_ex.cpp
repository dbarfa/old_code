#include <fstream.h>
#include <iostream.h>

struct nod {
    nod *st, *dr;
    int info;
};
nod *rad1, *rad2;
ifstream f("d:\\elev\\vector.txt");
void creare(nod*& p) {
    int n;
    f >> n;

    if (n == 0)
        p = NULL;
    else {
        p = new nod;
        p->info = n;
        creare(p->st);
        creare(p->dr);
    }
}

void srd(nod* p) {
    if (p != NULL) {
        srd(p->st);
        cout << p->info << " ";
        srd(p->dr);
    }
}
int identic(nod* p1, nod* p2) {
    if (p1 != NULL && p2 != NULL) {
        if (p1->info == p2->info && p1->st == p2->st && p1->dr == p2->dr)
            return 1;
        return identic(p1->st, p2->st) && identic(p1->dr, p2->dr);

    } else
        return 0;
}
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int inaltime(nod* p) {
    if (p == NULL)
        return 0;
    else
        return 1 + max(inaltime(p->st), inaltime(p->dr));
}
int produs(nod* p) {
    if (p == NULL)
        return 1;
    else if (p->info % 2 == 0)
        return p->info * produs(p->st) * produs(p->dr);
    else
        return produs(p->st) * produs(p->dr);
}

int suma(nod* p) {
    if (p == NULL)
        return 1;
    else if (p->info % 2 == 1)
        return p->info + suma(p->st) + suma(p->dr);
    else
        return suma(p->st) + suma(p->dr);
}

int terminale(nod* p) {
    if (p == NULL)
        return 0;
    else if (p->st == NULL && p->dr == NULL)
        return 1;

    else
        return terminale(p->st) + terminale(p->dr);
}

void main() {
    creare(rad1);
    creare(rad2);
    cout << "\n parcurgerea SRD primului arbore " << endl;
    srd(rad1);
    cout << "\n parcurgrea SRD al 2 arbore " << endl;
    srd(rad2);
    cout << "\nSunt cei doi arbori identici ? ";
    if (identic(rad1, rad2))
        cout << "\nDA";
    else
        cout << "\nNU";
    cout << "\nInaltimea arborelui 2 este ";
    cout << inaltime(rad2);
    cout << endl;
    cout << "\nProdusul nodurilor pare din al 2 arbore este ";
    cout << produs(rad2);
    cout << "\nSuma nodurilor impare din primul arbore este ";
    cout << suma(rad1);
    cout << "\nCate noduri terminale are primul graf ";
    cout << terminale(rad1);
}
