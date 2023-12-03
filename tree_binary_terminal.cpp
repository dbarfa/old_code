#include <iostream.h>

struct nod {
    int info;
    nod *s, *d;
};

void creare(nod*& rad) {
    int x;
    cin >> x;
    if (x != 0) {
        rad = new nod;
        rad->info = x;
        creare(rad->s);
        creare(rad->d);

    } else
        rad = NULL;
}

void rsd(nod* rad) {
    if (rad != NULL) {
        cout << rad->info;
        rsd(rad->s);
        rsd(rad->d);
    }
}

void srd(nod* rad) {
    if (rad != NULL) {
        srd(rad->s);
        cout << rad->info;
        srd(rad->d);
    }
}

int produs(nod* p) {
    if (p == NULL)
        return 1;
    else if (p->info % 2 == 0)
        return p->info * produs(p->s) * produs(p->d);
    else
        return produs(p->s) * produs(p->d);
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
        return 1 + max(inaltime(p->s), inaltime(p->d));
}

int terminale(nod* p) {
    if (p == NULL)
        return 0;
    else if (p->s == NULL && p->d == NULL)
        return 1;

    else
        return terminale(p->s) + terminale(p->d);
}

void main() {
    nod* rad;

    rad = NULL;
    creare(rad);
    cout << "\n arborele parcurs este " << endl;
    rsd(rad);
    cout << "\n arborelae parcurs in rsd " << endl;
    srd(rad);
    cout << "\n produsul este " << produs(rad) << endl;

    cout << "\n inaltimea este " << inaltime(rad);
    cout << "\n nr de frunze " << terminale(rad);
}
