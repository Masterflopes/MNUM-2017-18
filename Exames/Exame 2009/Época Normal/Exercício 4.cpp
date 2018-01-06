#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double x){
    return 5.0*cos(x)-sin(x);
}

int main () {
    double x1 = 2.0, x2 = 4.0, x3, x4;
    double B = (sqrt(5)-1)/2, A= pow(B,2);
    int iteracao = 0;

    do{
        x3 = x1 + A*(x2-x1);
        x4 = x1 + B*(x2-x1);

        cout << "Iteracao " << iteracao << endl;
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
        cout << "x3: " << x3 << endl;
        cout << "x4: " << x4 << endl;
        cout << "f(x1): " << f(x1) << endl;
        cout << "f(x2): " << f(x2) << endl;
        cout << "f(x3): " << f(x3) << endl;
        cout << "f(x4): " << f(x4) << endl;
        cout << endl;

        if(f(x3)<f(x4))
            x2 = x4;
        else
            x1 = x3;
        iteracao++;
    }while (iteracao < 3);

    return 0;
}

//Amplitude = 2 - 2.47214 = 0.47214