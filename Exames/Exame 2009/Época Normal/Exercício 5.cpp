#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double t, double x){
    return sin(x) + sin(2.0*t);
}

int main () {
    double x = 1.0, t = 1.0, h = 0.5, d1, d2, d3, d4;
    double s, sl, sll;

    cout << "1ª Itegracao" << endl;
    do{
        cout << "t: " << setw(10) << t << setw(10) << "x: " << x << endl;
        s = x;

        d1 = h*f(t,x);
        d2 = h*f(t+h/2,x+d1/2);
        d3 = h*f(t+h/2,x+d2/2);
        d4 = h*f(t+h,x+d3);
        x = x + (1.0/6.0)*d1 + (1.0/3.0)*d2 + (1.0/3.0)*d3 + (1.0/6.0)*d4;
        t = t + h;

    }while (t <= 1.5);

    x = 1.0, t = 1.0;
    h = h/2;
    cout << endl;
    cout << "2ª Itegracao" << endl;
    do{
        cout << "t: " << setw(10) << t << setw(10) << "x: " << x << endl;
        sl = x;

        d1 = h*f(t,x);
        d2 = h*f(t+h/2,x+d1/2);
        d3 = h*f(t+h/2,x+d2/2);
        d4 = h*f(t+h,x+d3);
        x = x + (1.0/6.0)*d1 + (1.0/3.0)*d2 + (1.0/3.0)*d3 + (1.0/6.0)*d4;
        t = t + h;

    }while (t <= 1.5);

    x = 1.0, t = 1.0;
    h = h/2;
    cout << endl;
    cout << "3ª Itegracao" << endl;
    do{
        cout << "t: " << setw(10) << t << setw(10) << "x: " << x << endl;
        sll = x;

        d1 = h*f(t,x);
        d2 = h*f(t+h/2,x+d1/2);
        d3 = h*f(t+h/2,x+d2/2);
        d4 = h*f(t+h,x+d3);
        x = x + (1.0/6.0)*d1 + (1.0/3.0)*d2 + (1.0/3.0)*d3 + (1.0/6.0)*d4;
        t = t + h;

    }while (t <= 1.5);

    cout << endl << "Quoficiente de convergencia: " << (sl - s)/(sll - sl) << endl;

    return 0;
}
