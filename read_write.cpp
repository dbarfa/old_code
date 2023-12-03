#include <string.h>
#include <iostream>

using namespace std;
char a[100][20];
int n;
void citire(char a[100][20], int& n) {
  cout << "\ncate cuvinte citesti ";
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin.get();
    cout << "\nintrodu cuvantul ";
    cin.get(a[i], 20);
  }
}
void afisare(char a[100][20], int n) {
  for (int i = 1; i <= n; i++)
    cout << a[i] << endl;
}

int main() {
  citire(a, n);
  cout << "\n Cuvintele citite sunt :" << endl;

  afisare(a, n);

  return 0;
}
