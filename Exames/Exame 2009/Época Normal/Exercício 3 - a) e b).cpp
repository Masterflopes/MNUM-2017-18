#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void show_matrix(double a11,double a12,double a13, double a14,double a21,double a22,double a23, double a24,double a31,double a32,double a33, double a34, double a41, double a42, double a43, double a44, double b1, double b2, double b3, double b4){
    cout << setw(10) << a11 << setw(10) << a12 << setw(10) << a13 << setw(10) << a14 << setw(10) << b1 << endl;
    cout << setw(10) << a21 << setw(10) << a22 << setw(10) << a23 << setw(10) << a24 << setw(10) << b2 << endl;
    cout << setw(10) << a31 << setw(10) << a32 << setw(10) << a33 << setw(10) << a34 << setw(10) << b3 << endl;
    cout << setw(10) << a41 << setw(10) << a42 << setw(10) << a43 << setw(10) << a44 << setw(10) << b4 << endl;
}

int main () {
    double a11 =0.1,a12=0.5,a13=3.0,a14=0.25,a21=1.2,a22=0.2,a23=0.25,a24=0.2,a31=-1.0,a32=0.25,a33=0.3,a34=2.0,a41=2.0,a42=0.00001,a43=1.0,a44=0.4,b1=0,b2=1.0,b3=2.0,b4=3.0;

    show_matrix(a11,a12,a13,a14,a21,a22,a23,a24,a31,a32,a33,a34,a41,a42,a43,a44,b1,b2,b3,b4);

    a12 = a12 / a11;
    a13 = a13 / a11;
    a14 = a14 / a11;
    b1 = b1 / a11;
    a11 = a11 / a11;

    a22 = a22 - (a21 * a12);
    a23 = a23 - (a21 * a13);
    a24 = a24 - (a21 * a14);
    b2 = b2 - (a21 * b1);
    a21 = a21 - (a21 * a11);

    a32 = a32 - (a31 * a12);
    a33 = a33 - (a31 * a13);
    a34 = a34 - (a31 * a14);
    b3 = b3 - (a31 * b1);
    a31 = a31 - (a31 * a11);

    a42 = a42 - (a41 * a12);
    a43 = a43 - (a41 * a13);
    a44 = a44 - (a41 * a14);
    b4 = b4 - (a41 * b1);
    a41 = a41 - (a41 * a11);

    a23 = a23 / a22;
    a24 = a24 / a22;
    b2 = b2 / a22;
    a22 = a22 / a22;

    a33 = a33 - (a32 * a23);
    a34 = a34 - (a32 * a24);
    b3 = b3 - (a32 * b2);
    a32 = a32 - (a32 * a22);

    a43 = a43 - (a42 * a23);
    a44 = a44 - (a42 * a24);
    b4 = b4 - (a42 * b2);
    a42 = a42 - (a42 * a22);

    a34 = a34 / a33;
    b3 = b3 / a33;
    a33 = a33 / a33;

    a44 = a44 -(a43 * a34);
    b4 = b4 - (a43 * b3);
    a43 = a43 - (a43 * a33);

    b4 = b4 / a44;
    a44 = a44 / a44;

    cout << endl;
    show_matrix(a11,a12,a13,a14,a21,a22,a23,a24,a31,a32,a33,a34,a41,a42,a43,a44,b1,b2,b3,b4);
    cout << endl;

    double x, y, z, t;
    t = b4;
    z = b3 - a34*t;
    y = b2 - a24*t-a23*z;
    x = b1 - a14*t-a13*z-a12*y;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;
    cout << "t: " << t << endl;

    return 0;
}