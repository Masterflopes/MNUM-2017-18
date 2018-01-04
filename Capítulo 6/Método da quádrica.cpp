#include <iostream>
#include <cmath>

using namespace std;

//Método da Quadratica

double f(double x, double y){
    return pow(y,2)-2*x*y-6*y+2*pow(x,2)+12+cos(4*x);
}


 //No Máxima:

 // H: matrix([4-16*cos(4*x),-2],[-2,2])
 // HI: invert(H)
 // G: matrix([-2*y+4*x-4*sin(4*x)],[2*y-2*x-6])
 // HI.G

double HI_G_x(double x, double y){
    return 2*(2*y-2*x-6)/(2*(4-16*cos(4*x))-4) + 2*(-2*y-4*sin(4*x)+4*x)/(2*(4-16*cos(4*x))-4);
}

double HI_G_y(double x, double y){
    return (4-16*cos(4*x))*(2*y-2*x-6)/(2*(4-16*cos(4*x))-4) + 2*(-2*y-4*sin(4*x)+4*x)/(2*(4-16*cos(4*x))-4);
}

int main(){
    double x=1, y=1, xt, yt;

    do{
        xt = x;
        yt = y;

        x = x - HI_G_x(x,y);
        y = y - HI_G_y(xt,y);

    } while ((abs(x-xt)>0.001) || (abs(y-yt)>0.001));

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    return 0;
}