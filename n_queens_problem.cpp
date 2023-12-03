#include <conio.h>
#include <iostream.h>
#include <math.h>

int st[20], n, nr;
int valid(int k) {
    int i;
    for (i = 1; i <= k - 1; i++)
        if (st[k] == st[i] || abs(k - i) == abs(st[k] - st[i]))
            return 0;
    return 1;
}
int amsuccesor(int k) {
    int as;
    if (st[k] < n) {
        st[k] = st[k] + 1;
        return 1;
    }
    return 0;
}
void afisare(int k) {
    int i, j;
    cout << "\nSolutia " << nr << ":" << endl;
    for (i = 1; i <= k; i++) {
        for (j = 1; j <= k; j++)
            if (st[i] == j)
                cout << 'D';
            else
                cout << '*';
        cout << endl;
    }
}
void back(int k) {
    int as, ev;
    k = 1;
    st[k] = 0;
    while (k > 0) {
        do {
            as = amsuccesor(k);
            if (as)
                ev = valid(k);
        } while (as && !ev);
        if (as)
            if (k == n) {
                nr++;
                afisare(k);
                if (nr % 20 == 0)
                    getch();
            } else {
                k++;
                st[k] = 0;
            }
        else
            k--;
    }
}
void main() {
    cout << "\n n= ";
    cin >> n;
    back(n);
    cout << "\n Sunt " << nr << " solutii ";
}
