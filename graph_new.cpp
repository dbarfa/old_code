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

int complet(a[10][10], int n) {
    int i, j, ok = 1;
    for (i = 1; i < n; i++)
        for (i = i + 1; i <= n; i++)
            if (a[i][j] == 0)
                ok = 0;
    return ok;
}
int regulat(v[10], int n) {
    int i, ok = 1;
    for (i = 1; i <= n; i++)
        if (v[i] != v[i + 1])
            ok = 0;

    return ok;
}
void main() {
    int a[10][10], n, v[10];
    citire(a, n);
    cout << "\n matricea de adiacenta :" << endl;
    afisare(a, n);
    cout << "\n sirul grafic al grafului este " << endl;
    vectgrade(a, v, n);
    afisvect(v, n);
    if (complet(a, n))
        cout << "graful este complet ";
    else
        cout << " graful nu este comlet ";
}
