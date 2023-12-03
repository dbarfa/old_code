#include <string.h>
#include <iostream>

using namespace std;

void citire(char a[100][20], int& n) {
    cout << "\n cate cuvinte citeste";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin.get();
        cout << "\n introdu cuvantul";
        cin.get(a[i], 20);
    }
}
void afisare(char a[100][20], int n) {
    for (int i = 1; i <= n; i++)
        cout << a[i] << endl;
}
void rezolvare(char a[100][20], int n) {
    int ok = 0;
    for (int i = 1; i < ; i++)
        for (int j = i + 1; j <= n; j++)
            if (strstr(a[i], a[j])) {
                cout << a[i] << " " << a[j] << endl;
                ok = 1;
                if (OK == 0)
                    cout << "\n Fara solutii";
            }
}
int main() {
    char cuv[100][20];
    int n;
    citire(cuv, n) afisare(cuv, n) rezolvare(cuv, n) return 0;
}

