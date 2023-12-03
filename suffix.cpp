#include <iostream.h>
#include <string.h>

void main(){
  char a[100], b[100];
  int i, n1, n2, j, ok, poz;
  cout << "introdu primul sir: ";
  cin.get(a, 100);
  cin.get();
  cout << "\nintrodu al 2-lea sir: ";
  cin.get(b, 100);
  n1 = strlen(a) - 1;
  n2 = strlen(b) - 1;
  ok = 1;
  poz = n1;
  for (i = n1; i >= 0 && ok; i--)
    for (j = n2; j >= 0; j--)
      if (a[i] != b[j])
        ok = 0;
  poz = i - 1;
  cout << poz << endl;
  cout << "\nsufixele comune sunt: " << a + poz - 1;
}
