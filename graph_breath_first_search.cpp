#include <fstream.h>
#include <iostream.h>

void citire(int a[10][10], int& n) {
    int i, j;
    ifstream f("D:\\elev\\text.txt");
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
void latime(int a[10][10], int nod, int n, int& nr, int v[10]) {
    int i, p, viz[10];

    for (i = 1; i <= n; i++)
        viz[i] = 0;
    v[1] = nod;
    viz[nod] = 1;
    p = 1;
    nr = 1;
    while (p <= n) {
        for (i = 1; i <= n; i++)
            if (a[v[p]][i] == 1 && viz[i] == 0) {
                nr++;
                v[nr] = i;
                viz[i] = 1;
            }
        p++;
    }
}

void vector(int v[10], int n) {
    int i;
    for (i = 1; i <= n; i++)
        cout << v[i] << " ";
}

void main() {
    int a[10][10], v[10], nr, n, nod;
    citire(a, n);
    afisare(a, n);
    cout << "introdu nod ";
    cin >> nod;
    latime(a, nod, n, nr, v);
    cout << endl;
    vector(v, nr);
}
