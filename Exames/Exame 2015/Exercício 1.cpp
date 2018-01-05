#include <iostream>
#include <cmath>

using namespace std;

double f(double t, double T){
    return -0.25*(T-37);
}

int main () {
    double t = 5, T = 3, h = 0.4, ttemp;
    int repeticoes = 2;
    do{
        ttemp = t;
        t = t + h;
        T = T + h*f(ttemp,T);

        cout << "t: " << t << endl;
        cout << "T: " << T << endl;
        cout << endl;

        repeticoes--;
    } while(repeticoes > 0);
    return 0;
}