#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x, double y){
    return -1.7*x*y +12*y+7*pow(x,2)-8*x;
}

double fdx (double x, double y){
    return -1.7*y+14*x-8;
}

double fdy (double x, double y){
    return 12-1.7*x;
}

int main () {
    double x =2.4, y=4.3, h=0.1, xt;

    xt =x;
    x = x - h*fdx(x,y);
    y= y- h*fdy(xt,y);

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "w(x,y): " << f(x,y) << endl;

    return 0;
}
