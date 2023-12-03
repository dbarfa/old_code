#include <string.h>
#include <iostream>

using namespace std;

void citire(char a[100][20], int& n) {
    cout << "\n cate cuvinte citesti  ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin.get();
        cout << "\n introdu cuvantul  ";
        cin.get(a[i], 20);
    }
}
void afisare(char a[100][20], int n) {
    for (int i = 1; i <= n; i++)
        cout << a[i] << endl;
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
void cerinta_a(char a[100][20], int n) {
    cout << "\nCuvintele care au proprietatea de palindrom:" << endl;
    for (int i = 1; i <= n; i++)
        if (palindrom(a[i]))
            cout << a[i] << endl;
}
int main() {
    char s[100][20];
    int n;
    citire(s, n);
    cout << "\nCuvintele citite sunt:" << endl;
    afisare(s, n);
    cerinta_a(s, n);
}
