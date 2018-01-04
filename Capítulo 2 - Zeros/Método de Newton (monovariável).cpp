#include <iostream>
#include <cmath>

using namespace std;

// MÉTODO DE NEWTON

double f(double x) {
    return sin(10 * x) + cos(3 * x);
}

double fd(double x) {
    return 10 * cos(10 * x) - 3 * sin(3 * x);
}

int main() {
    double x0 = 5.6;
    double xn, xnt;
    xn = x0;
    do {
        xnt = xn;
        xn = xn - f(xn)/fd(xn);
    } while (abs((xn - xnt) / xn) * 100 > 0.5);

    cout << "xn: " << xn << endl;
    cout << "f(xn): " << f(xn) << endl;
}