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

void main() {
    creare(rad1);
    creare(rad2);
    cout << "\n parcurgerea SRD primului arbore " << endl;
    srd(rad1);
    cout << "\n parcurgrea SRD al 2 arbore " << endl;
    srd(rad2);
    if (identic(rad1, rad2))
        cout << "\nDA";
    else
        cout << "\nNU";
}
