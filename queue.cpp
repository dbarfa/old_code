#include <fstream.h>

struct coada {
    int info;
    coada* urm;
};

coada *prim, *ultim;
int x;
void adaug_P(coada*& prim, int nr) {
    prim = new coada;
    prim->info = nr;
    prim->urm = NULL;
    ultim = prim;
}

void adaug(coada*& ultim, int nr) {
    coada* p;
    p = new coada;
    p->info = nr;
    p->urm = NULL;
    ultim->urm = p;
    ultim = p;
}

void creare(coada*& prim, coada*& ultim, int nr, char fis[20]) {
    ifstream f(fis);
    prim = ultim = NULL;
    f >> nr;
    adaug_P(prim, nr);
    while (f >> nr)
        adaug(ultim, nr);
    f.close();
}

void afisare(coada* p) {
    while (p) {
        cout << p->info << " ";
        p = p->urm;
    }
}

void main() {
    creare(prim, ultim, x, "d:\\elev\\lista.txt");
    afisare(prim);
}
