#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double x){
    return x+pow(x-2,2)/(sin(x)+4);
}

int main () {
    double x1 = -1.0,x2=1.5,x3,x4;
    double B = (sqrt(5)-1)/2, A = pow(B, 2);
    int iteracoes = 0;
    do{
        x3 = x1 + A*(x2-x1);
        x4 = x1 + B*(x2-x1);

        cout << "Iteracao " << iteracoes << endl;
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
        cout << "x3: " << x3 << endl;
        cout << "x4: " << x4 << endl;
        cout << "f(x1): " << f(x1) << endl;
        cout << "f(x2): " << f(x2) << endl;
        cout << "f(x3): " << f(x3) << endl;
        cout << "f(x4): " << f(x4) << endl;
        cout << endl;

        if(f(x3) < f(x4)){
            x2 = x4;
        }
        else{
            x1 = x3;
        }

        iteracoes++;
    } while(iteracoes < 3);

    return 0;
}

//amplitude = abs(-1)-abs(-0.40983) = 0.59017