#include <fstream.h>
#include <iostream.h>

struct coada {
    int info;
    coada* urm;
};
coada *prim1, *prim2, *ultim1, *ultim2;
int x;

void adaug_p(coada*& prim, coada*& ultim, int nr) {
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
    adaug_p(prim, ultim, nr);
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
    int OK = 1;
    creare(prim1, ultim1, x, "D:\\Elev\\text.txt");
    cout << "\n Prima coada este :";
    afisare(prim1);
    creare(prim2, ultim2, x, "D:\\Elev\\text1.txt");
    cout << "\n A doua coada este: ";
    afisare(prim2);
    while (prim1 && prim2 && OK) {
        if (prim1->info != prim2->info)
            OK = 0;
        prim1 = prim1->urm;
        prim2 = prim2->urm;
    }
    if (OK)
        cout << "\n Cele doua cozi sunt identice";
    else
        cout << "\n Cele doua cozi nu sunt identice";
}
