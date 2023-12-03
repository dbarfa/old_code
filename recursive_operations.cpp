#include <iostream.h>

unsigned f1(unsigned n) {
    if (n == 0)
        return 0;
    else
        return n + f1(n - 1);
}
unsigned f2(unsigned n) {
    if (n == 1)
        return 2;
    else
        return 2 * n + f2(n - 1);
}

unsigned f3(unsigned n) {
    if (n == 0)
        return 1;
    else
        return n * f3(n - 1);
}

unsigned f4(int a, int b) {
    if (a == b)
        return a;
    else if (a > b)
        return f4(a - b, b);
    else
        return f4(a, b - a);
}

unsigned f5(unsigned a, unsigned b) {
    if (b == 0)
        return a;
    else
        return f5(b, a % b);
}

unsigned f6(unsigned n) {
    if (n == 0)
        return 0;
    else
        return n % 10 + f6(n / 10);
}

unsigned f7(unsigned n) {
    if (n == 0)
        return 1;
    else
        return n % 10 * f7(n / 10);
}

unsigned f8(unsigned n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return f8(n - 1) + f8(n - 2);
}
unsigned suma(unsigned n) {
    if (n == 0)
        return 0;
    else
        return n % 10 + suma(n / 10);
}

unsigned produs(unsigned n) {
    if (n == 0)
        return 0;
    else
        return n % 10 * produs(n / 10);
}
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return max(b, a);
}

unsigned cmmdc(unsigned a, unsigned b) {
    if (a == b)
        return a;
    else if (a > b)
        return cmmdc(a - b, b);
    else
        return cmmdc(a, b - a);
}

unsigned comba(unsigned a, unsigned b) {
    if ((b == 0) || (b == a))
        return 1;
    else
        comba(a - 1, b) + comba(a - 1, b - 1);
}

unsigned fibonaci(unsigned n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonaci(n - 1) + fibonaci(n - 2);
}

void afisare(unsigned n) {
    if (n == 0)
        cout << endl;
    else {
        cout << n << " ";
        afisare(n - 1);
    }
    unsigned suma(unsigned n) {
        if (n == 0)
            return 0;
        else
            return n % 10 + suma(n / 10);
    }
}

unsigned produs(unsigned n) {
    if (n == 0)
        return 0;
    else
        return n % 10 * produs(n / 10);
}
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return max(b, a);
}

unsigned cmmdc(unsigned a, unsigned b) {
    if (a == b)
        return a;
    else if (a > b)
        return cmmdc(a - b, b);
    else
        return cmmdc(a, b - a);
}

unsigned comba(unsigned a, unsigned b) {
    if ((b == 0) || (b == a))
        return 1;
    else
        comba(a - 1, b) + comba(a - 1, b - 1);
}

unsigned fibonaci(unsigned n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonaci(n - 1) + fibonaci(n - 2);
}

void afisare(unsigned n) {
    if (n == 0)
        cout << endl;
    else {
        cout << n << " ";
        afisare(n - 1);
}
