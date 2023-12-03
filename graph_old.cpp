#include <fstream.h>

void citire(int a[10][10], int& n) {
    int i, j;
    ifstream f("d:\\elev\\graf.txt");
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

void afisvect(int v[10], int n) {
    int i;
    for (i = 1; i <= n; i++)
        cout << v[i] << " ";
}

void vectgrade(int a[10][10], int v[10], int n) {
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j])
                v[i]++;
}

int muchii(int a[10][10], int n) {
    int i, j, nr;
    nr = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j])
                nr++;

    nr = nr / 2;
    return nr;
}

int izolate(int v[10], int n) {
    int i, j, nr;
    nr = 0;
    for (i = 1; i <= n; i++)
        if (v[i] == 0)
            nr++;

    return nr;
}

void terminale(int v[10], int n) {
    int i;
    for (i = 1; i <= n; i++)
        if (v[i] == 1)
            cout << i << " ";
}

void minim(int v[10], int n) {
    int i, j, max;
    max = v[1];
    for (i = 2; i <= n; i++)
        if (max < v[i])
            max = v[i];
    cout << "\nVarfurile care au gradul maxim " << max << " sunt:";
    for (i = 1; i <= n; i++)
        if (max == v[i])
            cout << i << " ";
}

void main() {
    int a[10][10], n, v[10];
    citire(a, n);
    cout << "\nMatricea de adiacenta " << endl;
    afisare(a, n);
    cout << "\nSirul grafic al grafului este " << endl;
    vectgrade(a, v, n);
    afisvect(v, n);
    cout << "\nNr de muchii= " << muchii(a, n) << endl;
    cout << "\nSunt " << izolate(v, n) << " varfuri izolate in graf " << endl;
    cout << "\nIn graf varfurile terminale sunt ";
    terminale(v, n);
    maxim(v, n);
}
