#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double x, double y){
    return 6.0*pow(x,2)- x*y+12.0*y+pow(y,2)-8.0*x;
}

double fdx (double x, double y){
    return -y + 12.0*x - 8;
}

double fdy (double x, double y){
    return 2.0*y - x + 12;
}

int main () {
    double x = 0, y = 0, h = 0.25, xt;

    cout << "Iteracao 0" << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z(x,y): " << f(x,y) << endl;
    cout << "Gradiente 1: " << fdx(x,y) << endl;
    cout << "Gradiente 2: " << fdy(x,y) << endl;

    xt = x;
    x = x - h*fdx(x,y);
    y = y - h*fdy(xt,y);
    cout << endl;
    cout << "Iteracao 1" << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z(x,y): " << f(x,y) << endl;

    return 0;
}
