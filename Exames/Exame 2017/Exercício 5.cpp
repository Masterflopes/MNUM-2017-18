#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double t, double y, double z){
    return 0.5+pow(t,2)+t*z;
}

double g(double t, double y, double z){
    return z;
}

int main () {
    double t=0.0, y=0.0, z=1.0, h=0.25;
    int iteracao = 0;
    cout << fixed << setprecision (5);

    cout << "Metodo de Euler" << endl;
    do{
        cout << "Iteracao " << iteracao << endl;
        cout << "t: " << t << endl;
        cout << "y: " << y << endl;

        y = y + h* g(t,y,z);
        z = z + h* f(t,y,z);
        t = t + h;

        iteracao++;
    }while(iteracao<3);


    t=0.0, y=0.0, z=1.0, h=0.25;
    iteracao = 0;
    double d1, d2, d3, d4, e1,e2,e3,e4;
    cout << endl;
    cout << "Metodo de RK4" << endl;
    do{
        cout << "Iteracao " << iteracao << endl;
        cout << "t: " << t << endl;
        cout << "y: " << y << endl;

        d1 = h * g(t,y,z);
        e1 = h * f(t,y,z);
        d2 = h * g(t+h/2,y+d1/2,z+e1/2);
        e2 = h * f(t+h/2,y+d1/2,z+e1/2);
        d3 = h * g(t+h/2,y+d2/2,z+e2/2);
        e3 = h * f(t+h/2,y+d2/2,z+e2/2);
        d4 = h * g(t+h,y+d3,z+e3);
        e4 = h * f(t+h,y+d3,z+e3);

        y = y + (1.0/6.0)*d1 + (1.0/3.0)*d2 + (1.0/3.0)*d3 + (1.0/6.0)*d4;
        z = z + (1.0/6.0)*e1 + (1.0/3.0)*e2 + (1.0/3.0)*e3 + (1.0/6.0)*e4;
        t = t + h;

        iteracao++;
    }while(iteracao<3);

    return 0;
}
