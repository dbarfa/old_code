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

void main() {
    creare(rad1);
    creare(rad2);
    cout << "\n parcurgerea SRD primului arbore " << endl;
    srd(rad1);
    cout << "\n parcurgrea SRD al 2 arbore " << endl;
    srd(rad2);
}
