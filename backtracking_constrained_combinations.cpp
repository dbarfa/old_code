#include <conio.h>
#include <iostream.h>

int st[20], n, nr, m, k;

int valid(int k) {
    int i;
    for (i = 1; i <= k - 1; i++)
        if (st[i] == st[k])
            return 0;
    if (k == 1)
        if (st[k] != 2)
            return 0;
    if (k == 4)
        if (st[k] != 7)
            return 0;
    return 1;
}

int amsuccesor(int k) {
    int as;
    if (st[k] < n - m + k) {
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
            if (k == 4) {
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
    n = 8;
    m = 4;
    back(n);
    cout << "\nSunt " << nr << " Solutii";
}
