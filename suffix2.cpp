#include <string.h>
#include <iostream>

using namespace std;
void sufix(char a[20], char b[20]) {
  i = strlen(a) - 1;
  j = strlen(b) - 1;
  p = 0;
  while (a[i] == b[j]) {
    i--;
    j--;
    p++;
  }
  if (p)
    ok = 1;
  else
    ok = 0;
  if (ok)
    cout << a + strlen(a) - p;
}

int main() {
  char c[20], y[20];
  cout << "\n Primul cuvant este";
  cin.get(x, 20);
  cin.get();
  cout << "\n Introdu al 2 numar";
  cin.get(y, 20);
  cin.get();
  sufix(x, y);
  return 0;
}
