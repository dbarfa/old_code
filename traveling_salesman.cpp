#include <conio.h>
#include <fstream.h>

int st[20], a[10][10], n, nr, start;

void citire() {
    int i, j;
    ifstream f("d:\\elev\\orase.txt");
    f >> n;
    while (f >> i >> j)
        a[i][j] = a[j][i] = 1;

    f.close();
}
int valid(int k) {
    int i;
    for (i = 1; i <= k - 1; i++)
        if (st[k] == st[i])
            return 0;
    if (a[st[k - 1]][st[k]] == 0)
        return 0;
    if (k == n && a[start][st[k]] == 0)
        return 0;
    if (k == n)
        if (a[start][st[k]] == 0)
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
int solutie(int k) {
    return (k == n);
}
void afisare(int k) {
    int i;
    for (i = 1; i <= k; i++)
        cout << st[i] << " ";
    cout << endl;
}
void back(int k) {
    int as, ev;
    k = 2;
    st[k] = 0;
    while (k > 1) {
        do {
            as = amsuccesor(k);
            if (as)
                ev = valid(k);
        } while (as && !ev);
        if (as)
            if (solutie(k)) {
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
    cout << "\n Orasul de plecare este ";
    cin >> start;
    citire();
    st[1] = start;
    back(2);
    cout << "\nSunt " << nr << " solutii";
