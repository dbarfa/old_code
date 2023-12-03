
#include <fstream.h>
#include <iostream.h>
const H = -1;

void citire(int c[10][10], int& n) {
    int i, j, k;
    ifstream f("d:\\elev\\fisirea.txt");
    f >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            c[i][j] = H;
    for (i = 1; i <= n; i++)
        c[i][i] = 0;
    while (f >> i >> j >> k)

        c[i][j] = c[j][i] = k;
    f.close();
}

void afisare(int c[10][10], int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        cout << endl << " ";
        for (j = 1; j <= n; j++)
            cout << c[i][j] << " || ";
    }
}

void vect(int v[10], int& nr) {
    cout << "cate elemente sunt in sir ";
    cin >> nr;

    for (int i = 1; i <= nr; i++)

        cin >> v[i];
}

void afisarevect(int v[10], int nr) {
    cout << "elementele vecturului sunt ";
    for (int i = 1; i <= nr; i++)

        cout << v[i] << " ";
}

void main() {
    int v[10], c[10][10], n, nr;
    citire(c, n);
    afisare(c, n);
    cout << endl;
    vect(v, nr);
    afisarevect(v, nr);
}
