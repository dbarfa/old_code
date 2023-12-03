#include <conio.h>
#include <iostream.h>
#include <math.h>

int st[20], n, nr, a[20];
void citire(int& n) {
    int i;
    cout << " n= ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        cout << " cate elemente are multimea " << i << "=";
        cin >> a[i];
    }
}
int valid(int k) {
    int i;
    for (i = 1; i <= k - 1; i++)
        if (st[i] == st[k] && abs(k - 1) == abs(st[k] - st[i]))
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
    int i;
    for (i = 1; i <= k; i++)
        cout << st[i] << " ";
    cout << endl;
}

void back(int k) {
    int ev, as;
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
    citire(n);
    back(n);
    cout << "\nSunt " << nr << " solutii";
}
