#include <fstream.h>
#include <iostream.h>
void creare(int a[20][20], int& n) {
    int i, j, x;
    ifstream f("D:\\elev\\matrice1.txt");
    f >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            f >> x;
            a[i][j] = x;
        }
    f.close();
}

void afisare(int a[20][20], int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        cout << endl;
        for (j = 1; j <= n; j++)
            cout << a[i][j] << " ";
    }
}

int matrice(int a[20][20], int n) {
    int i, j, ok = 1;
    for (i = 1; i <= n; i++)
        if (a[i][i] != 0)
            ok = 0;
    if (ok == 1)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (a[i][j] != 1 && a[i][j] != 0)
                    ok = 0;
    return ok;
}

int simetric(int a[20][20], int n) {
    int i, j, ok = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] != a[j][i])
                ok = 0;
    return ok;
}

int grad(int a[20][20], int n, int x) {
    int i, s = 0;
    for (i = 1; i <= n; i++)
        if (a[i][x] == 1)
            s++;
    return s;
}

int gradinterior(int a[20][20], int n, int x) {
    int i, s = 0;
    for (i = 1; i <= n; i++)
        if (a[i][x] == 1)
            s++;
    return s;
}

int gradexterior(int a[20][20], int n, int x) {
    int j, s = 0;
    for (j = 1; j <= n; j++)
        if (a[x][j] == 1)
            s++;
    return s;
}

void crearemi(int a[20][20], int n, int b[20][20], int& m) {
    int i, j, x = 0, nr = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            x = x + a[i][j];
    m = x;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            b[i][j] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) {
                nr++;
                b[i][nr] = -1;
                b[j][nr] = 1;
            }
}
void afisaremi(int b[20][20], int n, int m) {
    int i, j;
    for (i = 1; i <= n; i++) {
        cout << endl;
        for (j = 1; j <= m; j++)
            cout << b[i][j] << " ";
    }
}

void main() {
    int a[20][20], n, i, j, x, max, nr, nr1, m, b[20][20];
    creare(a, n);
    if (matrice(a, n) == 1)
        if (simetric(a, n) == 1) {
            cout << "este matrice de adiacenta pt graf neorientat";
            max = grad(a, n, 1);
            for (i = 1; i <= n; i++)
                if (grad(a, n, i) > max)
                    max = grad(a, n, i);
            cout << endl << "nodurile de grad maxim ";
            for (i = 1; i <= n; i++)
                if (grad(a, n, i) == max)
                    cout << i << " ";
            cout << endl;
            nr = 0;
            for (i = 1; i <= n; i++)
                if (grad(a, n, i) == 1)
                    nr++;
            cout << "sunt " << nr << " noduri terminale";
        } else {
            cout << "este matrice de adiacenta pe graf orientat";
            nr1 = 0;
            cout << endl << "numarul de arce este ";
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    nr1 = nr1 + a[i][j];
            cout << nr1 << endl;
            cout << "nodurile pt care gri = gre ";
            for (i = 1; i <= n; i++)
                if (gradinterior(a, n, i) == gradexterior(a, n, i))
                    cout << i << " ";
            crearemi(a, n, b, m);
            cout << endl << endl;
            afisaremi(b, n, m);
        }
    else
        cout << "nu este matrice de adiacenta";
    return 0; 
}  
