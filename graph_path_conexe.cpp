#include <fstream.h>
#include <iostream.h>

void creare(int a[10][10], int& n) {
    int i, j;
    ifstream f("D:\\elev\\masturbinho.txt");
    f >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
    while (f >> i >> j)
        a[i][j] = a[j][i] = 1;
    f.close();
}
void vecnoduri(int v[10], int& nr) {
    int i;
    cout << "\n Numarul de noduri: ";
    cin >> nr;
    for (i = 1; i <= nr; i++) {
        cout << "Nodul " << i << "=";
        cin >> v[i];
    }
}
void afisarevec(int v[10], int nr) {
    int i;
    cout << "\n Vectorul este:";
    for (i = 1; i <= nr; i++)
        cout << v[i] << " ";
}
void afisare(int a[10][10], int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        cout << endl;
        for (j = 1; j <= n; j++)
            cout << a[i][j] << " ";
    }
}
int lant(int a[10][10], int v[10], int nr) {
    int i, ok;
    ok = 1;
    for (i = 1; i <= nr - 1; i++)
        if (a[v[i]][v[i + 1]] == 0)
            ok = 0;
    return ok;
}
int elementar(int v[10], int nr) {
    for (int i = 1; i <= nr; i++)
        for (int j = i + 1; j <= nr; j++)
            if (v[i] == v[j])
                return 0;
    return 1;
}
void transformare(int a[10][10], int n, int d[10][10]) {
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = a[i][j];
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][j] == 0 && k != i && k != j)
                    d[i][j] = d[i][k] * d[k][j];
}
int componenteconexe(int v[10], int d[10][10], int n) {
    int i, k, j;
    for (i = 1; i <= n; i++)
        v[i] = 0;
    for (i = 1; i <= n; i++)
        if (v[i] == 0) {
            k++;
            v[i] = k;
            for (j = 1; j <= n; j++)
                if (d[i][j] == 1)
                    v[j] = k;
        }
    return k;
}

void main() {
    int a[10][10], v[10], n, nr, i, j, d[10][10];
    creare(a, n);
    cout << "\n Matricea de adiacenta este:";
    afisare(a, n);
    cout << endl;
    vecnoduri(v, nr);
    afisarevec(v, nr);

    if (lant(a, v, nr)) {
        cout << "\n Formeaza lant.";
        if (elementar(v, nr))
            cout << "\n Lantul este elementar.";
        else
            cout << "\n Nu este lant elementar.";
    } else
        cout << "\n Nu formeaza lant.";
    transformare(a, n, d);
    cout << "\n Matricea drumurilor este:" << endl;
    afisare(d, n);

    if (componenteconexe(v, d, n))
        cout << "\n Sunt componente conexe ";
    else
        cout << "\n Nu sunt componente conexe ";
}
