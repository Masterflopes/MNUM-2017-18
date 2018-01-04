#include <iostream>
#include <cmath>

using namespace std;

//Método do Gradiente

double f(double x, double y){
    return pow(y,2)-2*x*y-6*y+2*pow(x,2)+12;
}

double fdx(double x, double y){
    return -2*y+4*x;
}

double fdy(double x, double y){
    return 2*y-2*x-6;
}

int main () {
    double x=1, y=1, h=1, xt, yt;

    do{
        xt = x;
        yt = y;
        x = x - h*fdx(x,y);
        y = y - h*fdy(xt,y);

        if(f(x,y)<f(xt,yt))
            h = 2*h;
        else
            h = h/2;

    } while ((abs(x-xt)>0.001) || (abs(y-yt)>0.001));

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    return 0;
}