#include <fstream.h>
#include <iostream.h>
#include <string.h>

struct stiva {
    int info;
    stiva* leg;
};
stiva *vf, *vf2;

void adaug(stiva*& vf, int nr) {
    stiva* q;
    q = new stiva;
    q->info = nr;
    q->leg = vf;
    vf = q;
}

void creare(stiva*& vf, int x, char fis[20]) {
    ifstream f(fis);
    vf = NULL;
    while (f >> x)
        adaug(vf, x);
    f.close();
}

void afisare(stiva* p) {
    while (p) {
        cout << p->info << " ";
        p = p->leg;
    }
}

void main() {
    int nr;
    creare(vf, nr, "D:\\elev\\stiva1.txt");
    cout << "\n Prima stiva este : ";
    afisare(vf);
    creare(vf2, nr, "D:\\elev\\stiva2.txt");
    cout << "\n A doua stiva este : ";
    afisare(vf2);
    int OK = 1;
    while (vf && vf2 && OK) {
        if (vf->info != vf2->info)
            OK = 0;
        vf = vf->leg;
        vf2 = vf2->leg;
    }
    if (OK)
        cout << "\n Cele doua stive sunt identice";
    else
        cout << "\n Cele doua stive nu sunt identice";
}
