#include <iostream.h>

int st[20], n;
int valid(int k) {
    int i;
    for (i = 1; i <= k - 1; i++)
        if (st[i] == st[k])
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
int solutie(int k) {
    return (k == n);
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
            if (solutie(k))
                afisare(k);
            else {
                k++;
                st[k] = 0;
            }
        else
            k--;
    }
}

void main() {
    cin >> n;
    back(n);
}
