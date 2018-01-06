#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x){
    return x-2.6+pow(cos(x+1.1),3);
}

double fd(double x){
    return 1 - 3*pow(cos(x+1.1),2)*sin(x+1.1);
}

int main () {
    double x = 1.8;

    x = x - f(x)/fd(x);

    cout << "x: " << x << endl;
    
    return 0;
}