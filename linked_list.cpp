
#include <fstream.h>
#include <string.h>

struct nod {
    int info;
    nod* urm;
};
nod *prim, *ultim, *p;
void adaug_prim(nod*& prim, nod*& ultim) {
    int nr;
    prim = new nod;
    prim->info = nr;
    prim->urm = NULL;
    ultim = prim;
}
void adaug_in_fata(nod* prim) {
    int nr;
    nod* p;
    p->info = nr;
    p->urm = prim;
    prim = p;
}
void adaug_dupa(nod* ultim) {
    int nr;
    nod* p;
    p = new nod;
    p->info = nr;
    p->urm = NULL;
    ultim->urm = p;
    ultim = p;
}
void creare(nod*& prim, nod*& ultim) {
    int nr;
    ifstream f("D:\Elev\lista.txt");
    prim = ultim = NULL;
    f >> nr;
    adaug_prim(prim, ultim);
    while (f >> nr)
        adaug_dupa(ultim);
    fclose();
}
int maxim(nod* p) {
    int max;
    max = prim->info;
    for (p = prim; p != NULL; p = p->urm)
        if (p->info > max)
            max = p->info;
    return max;
}
void main() {
    creare(prim, ultim); 
    cout << "Valoarea maxima: " << maxim(prim) << endl;
}
