#include <iostream>
#include <cmath>

using namespace std;

//Metodo Newton - Sistema de equações

double f1(double x, double y) {
    return x + y - 3;
}

double f2(double x, double y) {
    return pow(x, 2) + pow(y, 2) - 9;
}

double f1dx(double x, double y) {
    return 1;
}

double f1dy(double x, double y) {
    return 1;
}

double f2dx(double x, double y) {
    return 2*x;
}

double f2dy(double x, double y) {
    return 2*y;
}


int main() {
    double x = 4, y = 1, xn, xa, ya;

    do {
        xa = x;
        ya = y;
        xn = x - (f1(x, y)*f2dy(x, y) - f2(x, y)*f1dy(x, y)) / (f1dx(x, y)*f2dy(x, y) - f2dx(x, y)*f1dy(x, y));
        y = y - (f2(x, y)*f1dx(x, y) - f1(x, y)*f2dx(x, y)) / (f1dx(x, y)*f2dy(x, y) - f2dx(x, y)*f1dy(x, y));
        x = xn;

        cout << "x= " << x << endl << "y= " << y << endl;
    } while (abs((x-xa)/x * 100) > 0.5 || abs((y - ya) / y * 100) > 0.5);

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    system("pause");
}