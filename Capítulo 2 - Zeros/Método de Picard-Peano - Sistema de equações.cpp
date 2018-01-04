#include <iostream>
#include <cmath>

using namespace std;

long double funcaog1(long double x, long double y) {
    return sqrt((x*y+5*x-1)/2);
}

long double funcaog2(long double x, long double y) {
    return sqrt(x + 3 * log(x));
}


int main() {
    long double xn = 4, yn = 4;
    unsigned n = 0;

    do {
        //long double xn1 = xn;
        xn = funcaog1(xn, yn);
        yn = funcaog2(xn, yn);
        n++;

    } while (abs(funcaog1(xn,yn)-xn) > pow(10,-4) || abs(funcaog2(xn,yn)-yn) > pow(10,-4));

    cout << "xn : " << xn << endl;
    cout << "yn : " << yn << endl;
    cout << "iteracoes: " << n << endl;
}