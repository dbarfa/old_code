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

int max(nod* p) {
    if (p->d != NULL)
        return max(p->d);
    else
        return p->info;
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

    cout << "\n Cheia maxima este " << max(p->d);
}
