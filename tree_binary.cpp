#include <iostream.h>

struct nod {
    int info;
    nod *s, *d;
};

void creare(nod*& rad) {
    int x;
    cin >> x;
    if (x != NULL) {
        rad = new nod;
        rad->info = x;
        creare(rad->s);
        creare(rad->d);
    } else
        rad = NULL;
}

void RSD(nod* rad) {
    if (rad != NULL) {
        cout << rad->info << " ";
        RSD(rad->s);
        RSD(rad->d);
    }
}

void SRD(nod* rad) {
    if (rad != NULL) {
        SRD(rad->s);
        cout << rad->info << " ";
        SRD(rad->d);
    }
}

void SDR(nod* rad) {
    if (rad != NULL) {
        SDR(rad->s);
        SDR(rad->d);
        cout << rad->info << " ";
    }
}
