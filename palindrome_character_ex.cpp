#include <iostream.h>
#include <string.h>

void citire(char a[100][20], int& n) {
    int i;
    cout << "\nCate cuvinte citesti ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin.get();
        cout << "\nIntrodu cuvantul ";
        cin.get(a[i], 20);
    }
}
void afisare(char a[100][20], int n) {
    int i;
    for (i = 1; i <= n; i++)
        cout << a[i] << " ";
}
void sortare(char a[100][20], int n) {
    int i, j;
    char aux[20];
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if (strcmp(a[i], a[j]) > 0) {
                strcpy(aux, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], aux);
            }
}
int palindrom(char a[20]) {
    char b[20];
    strcpy(b, a);
    strrev(b);
    if (strcmp(a, b) == 0)
        return 1;
    else
        return 0;
}
void cate_palindrom(char a[100][20], int n) {
    int i, k = 0;
    for (i = 1; i <= n; i++)
        if (palindrom(a[i]))
            k++;
    cout << "\n Sunt " << k << " cuvinte palindrom ";
}
void cate_a(char a[100][20], int n) {
    int i, k = 0;
    cout << "\ncuvintele care incep cu caracterul a" << endl;
    for (i = 1; i <= n; i++)
        if (a[i][0] == 'a') {
            k++;
            cout << a[i] << " ";
        }
    if (k == 0)
        cout << "\n Nu sunt cuvinte care incep cu caracterul a";
}
void cate_x(char a[100][20], int n) {
    int i, m, k = 0;
    char x;
    cout << "\nCaracterul x ";
    cin >> x;
    for (i = 1; i <= n; i++) {
        m = strlen(a[i]) - 1;
        if (a[i][m] == x)
            k++;
    }
    cout << "\nSunt " << k << " cuvinte care incep cu caracterul " << x;
}
int main() {
    char a[100][20];
    int n;
    citire(a, n);
    afisare(a, n);
    sortare(a, n);
    cout << "\nCuvintele in ordine alfabetica " << endl;
    afisare(a, n);
    cate_palindrom(a, n);
    cate_a(a, n);
    cate_x(a, n);
    return 0;
}
