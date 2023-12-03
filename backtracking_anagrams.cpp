#include <conio.h>
#include <iostream.h>
#include <string.h>

int st[20], n, nr;
char cuv[20];

int valid(int k) {
    int i;
    for (i = 1; i <= k - 1; i++)
        if (st[i] == st[k])
            return 0;
    return 1;
}
void afisare() {
    int i;
    for (i = 1; i <= n; i++)
        cout << cuv[st[i] - 1] << " ";
    cout << endl;
}
void back(int k) {
    int i;
    for (i = 1; i <= n; i++) {
        st[k] = i;
        if (valid(k))
            if (k == n) {
                nr++;
                afisare();
            } else
                back(k + 1);
    }
}
void main() {
    cout << "\n Introducem cuvantul ";
    cin >> cuv;
    n = strlen(cuv);
    back(1);
    cout << "\n Sunt " << nr << " solutii ";
}
