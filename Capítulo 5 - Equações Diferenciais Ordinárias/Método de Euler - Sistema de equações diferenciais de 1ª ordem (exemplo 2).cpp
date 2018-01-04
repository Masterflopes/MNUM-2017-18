#include <iostream>

using namespace std;


long double f(long double x, long double y, long double z) {
	return z*y + x;
}

long double g(long double x, long double y, long double z) {
	return z*x + y;
}

//Metodo Euler
int main() {
	cout << "Metodo Euler" << endl << endl;
	long double xn = 0, yn = 1, zn = 1, h = 0.1, xnt, ynt, znt, d1, d2, d3, d4, k1, k2, k3, k4;
	long double sy, sz, spy, spz, sppy, sppz;

	do {
		xnt = xn;
		ynt = yn;
		znt = zn;
		xn = xn + h;
		yn = yn + h*f(xnt, ynt, znt);
		zn = zn + h*g(xnt, ynt, znt);
	} while (xn < 0.49999);

	sy = yn;
	sz = zn;
	cout << "Sy: " << yn << endl;
	cout << "Sz: " << zn << endl;

	xn = 0, yn = 1, zn = 1, h = h / 2;
	do {
		xnt = xn;
		ynt = yn;
		znt = zn;
		xn = xn + h;
		yn = yn + h*f(xnt, ynt, znt);
		zn = zn + h*g(xnt, ynt, znt);
	} while (xn < 0.4999);

	spy = yn;
	spz = zn;
	cout << endl;
	cout << "S'y: " << yn << endl;
	cout << "S'z: " << zn << endl;


	xn = 0, yn = 1, zn = 1, h = h / 2;
	do {
		xnt = xn;
		ynt = yn;
		znt = zn;
		xn = xn + h;
		yn = yn + h*f(xnt, ynt, znt);
		zn = zn + h*g(xnt, ynt, znt);
	} while (xn < 0.4999);

	sppy = yn;
	sppz = zn;
	cout << endl;
	cout << "S''y: " << yn << endl;
	cout << "S''z: " << zn << endl;

	cout << endl;
	cout << "QCy: " << (spy - sy) / (sppy - spy) << endl;
	cout << "Ey: " << (sppy - spy) / 15 << endl;

	cout << endl;
	cout << "QCz: " << (spz - sz) / (sppz - spz) << endl;
	cout << "Ez: " << (sppz - spz) / 15 << endl;


	system("pause");
}
