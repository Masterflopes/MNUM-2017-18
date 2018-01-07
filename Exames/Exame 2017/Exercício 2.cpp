#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double x, double y){
    return pow(x,2)-y-1.2;
}

double g (double x, double y){
    return -x+pow(y,2)-1.0;
}

double fdx (double x, double y){
    return 2.0*x;
}

double fdy (double x, double y){
    return -1;
}

double gdy (double x, double y){
    return 2.0*y;
}

double gdx (double x, double y){
    return -1;
}

int main () {
    double x=1.0, y=1.0, xt;
    int iteracao = 0;
    cout << fixed << setprecision (5);
    do{
        cout << "Iteracao " << iteracao << endl;
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;

        xt = x;
        x = x - (f(x,y)*gdy(x,y)-g(x,y)*fdy(x,y))/(fdx(x,y)*gdy(x,y)-gdx(x,y)*fdy(x,y));
        y = y - (g(xt,y)*fdx(xt,y)-f(xt,y)*gdx(xt,y))/(fdx(xt,y)*gdy(xt,y)-gdx(xt,y)*fdy(xt,y));

        iteracao++;
    }while(iteracao<3);
    return 0;
}
