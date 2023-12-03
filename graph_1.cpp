#include <fstream.h>
#include <iostream.h>

void citire(int a[10][10], int& n) {
    int i, j;
    ifstream f("d:\\elev\\G1.txt");
    f >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
    while (f >> i >> j)
        a[i][j] = a[i][j] = 1;
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
void afisarevector(int v[10], int n) {
    int i;
    for (i = 2; i <= n; i++)
        cout << v[i] << " ";
}
void vectorgrad(int a[10][10], int v[10], int n) {
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j])
                v[i]++;
}
void max(int a[10][10], int v[10], int n) {
    int i, j, max;
    max = v[1];
    for (i = 2; i <= n; i++)
        if (max < v[i])
            max = v[i];
    cout << "\n Varfurile cu grad max" << max << " sunt:";
    for (i = 1; i <= n; i++)
        if (max == v[i])
            cout << i << " ";
}

void main() {
    int a[10][10], n, v[10];
    citire(a, n);
    cout << "\n matricea de adi" << endl;
    afisare(a, n);
    cout << "\n sirul grafic" << endl;
    vectorgrad(a, v, n);
    afisarevector(v, n);
    max(a, v, n);
}
