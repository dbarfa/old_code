#include <fstream.h>
#include <iostream.h>

void citire(int a[10][10], int& n) {
    int i, j;
    ifstream f("D:\\elev\\FISIREA.txt");
    f >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
    while (f >> i >> j)
        a[i][j] = 1;
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

int exterior(int a[10][10], int n, int nod) {
    int s = 0;
    for (int i = 1; i <= n; i++)
        s = s + a[nod][i];
    return s;
}

int interior(int a[10][10], int n, int nod) {
    int z = 0;
    for (int i = 1; i <= n; i++)
        z = z + a[i][nod];
    return z;
}
int turneu(int a[10][10], int n) {
    int i, j, ok = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] == a[j][i])
                ok = 0;
    return ok;
}
void transformare(int a[10][10], int d[10][10], int n) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = a[i][j];
    for (int k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[k][j] == 1 || d[k][i] == 1)
                    for (j = 1; j <= n; j++)
                        if (d[k][j] == 1 || d[j][k])
                            d[i][j] = 1;
}
void afisare1(int d[10][10], int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        cout << endl;
        for (j = 1; j <= n; j++)
            cout << d[i][j] << " ";
    }
}

void main() {
    int a[10][10], n, nod, s, z, d[10][10];
    citire(a, n);
    afisare(a, n);
    for (int i = 1; i <= n; i++)
        if (exterior(a, n, i) == interior(a, n, i))
            cout << i;
    cout << endl;
    if (turneu(a, n))
        cout << "este turneu";
    else
        cout << "nu este turneu ";
    transformare(a, d, n);
    afisare1(d, n);
}
