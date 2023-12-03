#include <iostream>

using namespace std;

int x, y, z;
void p(int& a, int& b, int& c)

{
    int aux;
    aux = a;
    a = b - a;
    c = c - aux;
}
int main() {
    x = 10;
    y = 100;
    z = 200;
    p(x, y, z);
    cout << x << " " << y << " " << z << " ";
    p(x, y, z);
    cout << x << " " << y << " " << z << " ";
    return 0;
}
