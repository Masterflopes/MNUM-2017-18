#include <iostream>
#include <cmath>

using namespace std;

// Método de Levenberg-Marquardt

double f(double x, double y){
    return pow(x+1,2)+pow(y-4,2);
}

double fdx(double x, double y){
    return 2*(x+1);
}

double fdy(double x, double y){
    return 2*(y-4);
}

double HI_G_x(double x, double y){
    return x+1;
}

double HI_G_y(double x, double y){
    return y-4;
}

int main(){
    double x=0, y=0, xt, yt, lambda = 0.1, hx, hy;

    do{
        xt = x;
        yt = y;

        hx = HI_G_x(x,y)+lambda*fdx(x,y);
        hy = HI_G_y(xt,y)+lambda*fdy(xt,y);

        x = x - hx;
        y = y - hy;

        if(f(x,y) < f(xt,yt)){
            lambda = lambda / 2;
        }
        else
            lambda = lambda*2;

    } while ((abs(x-xt)>0.001) || (abs(y-yt)>0.001));

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "f(x,y): " << f(x,y) << endl;

    return 0;
}