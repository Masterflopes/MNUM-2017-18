#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double t, double y){
    return y/(t-1);
}

int main () {
    double t=2,y=2, h=0.25;
    int iteracao = 0;

    cout << "Metodo de Euler" << endl;

    do{
        cout << "Iteracao " << iteracao << endl;
        cout << "t: " << t << endl;
        cout << "y: " << y << endl;

        y = y + h*f(t,y);
        t = t + h;

        iteracao++;
    } while(iteracao<3);

    cout << endl;

    cout << "Metodo RK4" << endl;
    t=2,y=2, h=0.25;
    iteracao = 0;
    double d1, d2, d3, d4;

    do{
        d1 = h*f(t,y);
        d2=h*f(t+h/2,y+d1/2);
        d3=h*f(t+h/2,y+d2/2);
        d4=h*f(t+h,y+d3);

        cout << "Iteracao " << iteracao << endl;
        cout << "t: " << t << endl;
        cout << "y: " << y << endl;
        cout << "d1: " << d1 << endl;
        cout << "d2: " << d2 << endl;
        cout << "d3: " << d3 << endl;
        cout << "d4: " << d4 << endl;
        y = y + (1.0/6)*d1 + (1.0/3)*d2 + (1.0/3)*d3 + (1.0/6)*d4;
        t = t + h;

        iteracao++;
    }while(iteracao<3);
    return 0;
}
