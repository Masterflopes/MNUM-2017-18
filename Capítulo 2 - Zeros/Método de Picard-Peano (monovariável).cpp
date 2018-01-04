#include <iostream>
#include <cmath>

using namespace std;

//Metodo de Picard-Peano

double f2(double x) {
    return exp(-x) - x;
}

double f2d(double x) {
    return exp(-x);
}

int main() {
    double x = 1.1, xn;

    do {
        xn = x;
        x = f2d(x);
    } while ((abs(x-f2d(x))/x) > pow(10,-4));

    cout << "x: " << x << endl;
    cout << "f(x): " << f2(x) << endl;
}