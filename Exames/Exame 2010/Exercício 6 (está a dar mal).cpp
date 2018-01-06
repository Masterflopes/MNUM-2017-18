#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void show_matrix(double a11,double a12,double a13,double a21,double a22,double a23,double a31,double a32,double a33,double b1,double b2,double b3){
    cout << setw(12) << a11 << setw(12) << a12 << setw(12) << a13 << setw(12) << b1 << endl;
    cout << setw(12) << a21 << setw(12) << a22 << setw(12) << a23 << setw(12) << b2 << endl;
    cout << setw(12) << a31 << setw(12) << a32 << setw(12) << a33 << setw(12) << b3 << endl;
}

int main () {
    double estabilidade_externa = (0.1-(0.1*3.0));
    double a11 =18.0,a12=-1.0,a13=1.0,a21=3.0,a22=-5.0,a23=4.0,a31=6.0,a32=8.0,a33=29.0,b1=estabilidade_externa,b2=estabilidade_externa,b3=estabilidade_externa;

    show_matrix(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);

    a12 = a12 / a11;
    a13 = a13 / a11;
    b1 = b1 / a11;
    a11 = a11 / a11;

    a22 = a22 - (a21 * a12);
    a23 = a23 - (a21 * a13);
    b2 = b2 - (a21 * b1);
    a21 = a21 - (a21 * a11);

    a32 = a32 - (a31 * a12);
    a33 = a33 - (a31 * a13);
    b3 = b3 - (a31 * b1);
    a31 = a31 - (a31 * a11);

    a23 = a23 / a22;
    b2 = b2 / a22;
    a22 = a22 / a22;

    a33 = a33 - (a32 * a23);
    b3 = b3 - (a32 * b2);
    a32 = a32 - (a32 * a22);

    b3 = b3 / a33;
    a33 = a33 / a33;

    cout << endl;
    show_matrix(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);
    cout << endl;

    double x, y, z;
    z = b3;
    y = b2 - a23*z;
    x = b1 - a13*z - a12*y;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;


    return 0;
}