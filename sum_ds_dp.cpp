#include <iostream>

using namespace std;

int n, a[10][10];
void citire(int a[10][10], int& n) {
  int i, j;
  cout << "n=";
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      cin >> a[i][j];
    cout << endl;
  }
}
int suma_dp(int a[10][10], int n) {
  int i, j, s = 0;
  for (i = 0; i < n; i++)
    s += a[i][j];
  return s;
}

int suma_ds(int a[10][10], int n) {
  int i, s = 0;
  for (i = 0; i < n; i++)
    s += a[i][n - i - 1];
  return s;
}

int main() {
  citire(a, n);
  cout << "suma dp" << suma_dp(a, n);
  cout << "suma ds" << suma_ds(a, n);

  return 0;
}
