#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double x){
    return pow(x,7)+0.5*x-0.5;
}

int main () {
    double xe=0.0, xd=0.8, xn;
    int iteracao = 0;
    cout << fixed << setprecision (6);
    do{
        xn = (xe*f(xd)-xd*f(xe))/(f(xd)-f(xe));
        cout << "Iteracao " << iteracao << endl;
        cout << "Xe: " << xe << endl;
        cout << "Xd: " << xd << endl;
        cout << "Xn: " << xn << endl;
        cout << "f(Xe): " << f(xe) << endl;
        cout << "f(Xd): " << f(xd) << endl;
        cout << "f(Xn): " << f(xn) << endl;
        cout << endl;

        if(f(xe)*f(xn)<0)
            xd=xn;
        else
            xe=xn;

        iteracao++;
    }while(iteracao<4);
    return 0;
}
