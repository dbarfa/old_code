#include <iostream.h>

struct nod {
    int info;
    nod *s, *d;
};

void adaugare(nod*& p, int x) {
    if (p == NULL) {
        p = new nod;
        p->info = x;
        p->s = NULL;
        p->d = NULL;
    } else if (p->info > x)
        adaugare(p->s, x);
    else
        adaugare(p->d, x);
}

void srd(nod* p) {
    if (p != NULL) {
        srd(p->s);
        cout << p->info << " ";
        srd(p->d);
    }
}
int cautare(nod* p, int y) {
    if (p->info != y)
        return 0;
    else {
        if (p->info == y)
            return 1;
        else if (p->info < y)
            return cautare(p->d, y);
        else
            return cautare(p->s, y);
    }
}

void main() {
    nod* p;

    int y, x;
    p = NULL;

    cout << " introdu nodurile arborelui " << endl;
    cin >> x;
    while (x) {
        adaugare(p, x);
        cin >> x;
    }
    cout << "\n parcurgerea " << endl;
    srd(p);
    cout << "introdu elementul de cautat " << endl;
    cin >> y;
    if (cautare(p, y))
        cout << " Valoarea y se gaseste " << endl;
    else {
        adaugare(p, y);
        cout << " noul arbore binar este " << endl;
        srd(p);
    }
}
