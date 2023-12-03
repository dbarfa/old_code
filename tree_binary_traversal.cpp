#include <fstream.h>
#include <iostream.h>
#include <string.h>

struct nod {
    nod *st, *dr;
    int inf;
};
ifstream f("d:\\elev\\date.txt");

void creare(nod*& rad, int n) {
    int s, d;
    if (n == 0)
        rad = NULL;
    else {
        rad = new nod;
        cin >> rad->inf;
        s = (n - 1) / 2;
        d = (n - 1) - s;
        creare(rad->st, s);
        creare(rad->dr, d);
    }
}
void srd(nod* rad) {
    if (rad != NULL) {
        srd(rad->st);
        cout << rad->inf << " ";
        srd(rad->dr);
    }
}
void crear(nod*& rad) {
    int x;
    f >> x;
    if (x != 0) {
        rad = new nod;
        rad->inf = x;
        crear(rad->st);
        crear(rad->dr);
    } else
        rad = NULL;
}
void h(nod* rad, int x, int k) {
    if (rad != NULL) {
        if (x == k)
            cout << rad->inf << " ";
        else {
            h(rad->st, x + 1, k);
            h(rad->dr, x + 1, k);
        }
    }
}
int inalt(nod* rad) {
    int x1, x2 if (rad != NULL) {
        x1 = inalt(rad->st) x2 = inalt(rad->dr) if (x1 < x2) return x2 + 1;
        else return x1 + 1;
    }
    else return -1;
}

void main() {
    nod *rad, *r;
    int n, x, k;
    x = 0;
    r = NULL;
    cout << "n=";
    cin >> n;
    creare(rad, n);
    srd(rad);
    cout << endl;
    crear(r);
    srd(r);
    cout << endl;
    cout << "k=";
    cin >> k;
    h(r, x, k);
}
