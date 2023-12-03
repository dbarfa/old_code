#include <fstream.h>
#include <iostream.h>

void citire(int a[10][10], int& n) {
    int i, j;
    ifstream f("D:\\elev\\TEXT.txt");
    f >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
    while (f >> i >> j)
        a[i][j] = a[j][i] = 1;
    f.close();
}

void afisare(int a[10][10], int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        cout << endl;
        for (j = 1; j <= n; j++)
            cout << a[i][j] << " ";
    }
}
void adancime(int a[10][10], int v[10], int nod, int& nr, int n) {
    int vecin, viz[10], p, ok;
    for (int i = 1; i <= n; i++)
        viz[i] = 0;
    v[1] = nod;
    viz[nod] = 1;
    p = 1;
    nr = 1;
    while (p > 0) {
        ok = 0;
        for (i = 1; i <= n; i++)
            if (a[v[p]][i] == 1 && viz[i] == 0) {
                vecin = i;
                i = n;
                ok = 1;
            }
        if (ok) {
            nr++;
            v[nr] = vecin;
            viz[vecin] = 1;
            p = nr;
        } else
            p--;
    }
}

void afisvect(int v[10], int n) {
    int i;
    for (i = 1; i <= n; i++)
        cout << v[i];
}

void main() {
    int a[10][10], v[10], nod, nr, n;
    citire(a, n);
    afisare(a, n);
    cin >> nod;
    adancime(a, v, nod, nr, n);
    afisvect(v, n);
}
