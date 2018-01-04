#include <iostream>

using namespace std;


long double f(long double x, long double y, long double z) {
	return z*y + x;
}

long double g(long double x, long double y, long double z) {
	return z*x + y;
}

//Metodo RK4
int main() {
	cout << "Metodo RK4" << endl << endl;
	long double xn = 0, yn = 1, zn = 1, h = 0.1, xnt, ynt, znt, d1, d2, d3, d4, k1, k2, k3, k4;
	long double sy, sz, spy, spz, sppy, sppz;

	//Para aproximar o valor de QCy e QCz do esperado basta descomentar o que se segue
	//h = h / 2;
	//h = h / 2;
	//h = h / 2;
	//h = h / 2;

	do {
		xnt = xn;
		ynt = yn;
		znt = zn;
		xn = xn + h;
		d1 = h*f(xnt, ynt, znt);
		k1 = h*g(xnt, ynt, znt);
		d2 = h*f(xnt + h / 2, ynt + d1 / 2, znt + k1 / 2);
		k2 = h*g(xnt + h / 2, ynt + d1 / 2, znt + k1 / 2);
		d3 = h*f(xnt + h / 2, ynt + d2 / 2, znt + k2 / 2);
		k3 = h*g(xnt + h / 2, ynt + d2 / 2, znt + k2 / 2);
		d4 = h*f(xnt + h, ynt + d3, znt + k3);
		k4 = h*g(xnt + h, ynt + d3, znt + k3);
		yn = yn + d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		zn = zn + k1 / 6 + k2 / 3 + k3 / 3 + k4 / 6;
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
		d1 = h*f(xnt, ynt, znt);
		k1 = h*g(xnt, ynt, znt);
		d2 = h*f(xnt + h / 2, ynt + d1 / 2, znt + k1 / 2);
		k2 = h*g(xnt + h / 2, ynt + d1 / 2, znt + k1 / 2);
		d3 = h*f(xnt + h / 2, ynt + d2 / 2, znt + k2 / 2);
		k3 = h*g(xnt + h / 2, ynt + d2 / 2, znt + k2 / 2);
		d4 = h*f(xnt + h, ynt + d3, znt + k3);
		k4 = h*g(xnt + h, ynt + d3, znt + k3);
		yn = yn + d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		zn = zn + k1 / 6 + k2 / 3 + k3 / 3 + k4 / 6;
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
		d1 = h*f(xnt, ynt, znt);
		k1 = h*g(xnt, ynt, znt);
		d2 = h*f(xnt + h / 2, ynt + d1 / 2, znt + k1 / 2);
		k2 = h*g(xnt + h / 2, ynt + d1 / 2, znt + k1 / 2);
		d3 = h*f(xnt + h / 2, ynt + d2 / 2, znt + k2 / 2);
		k3 = h*g(xnt + h / 2, ynt + d2 / 2, znt + k2 / 2);
		d4 = h*f(xnt + h, ynt + d3, znt + k3);
		k4 = h*g(xnt + h, ynt + d3, znt + k3);
		yn = yn + d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		zn = zn + k1 / 6 + k2 / 3 + k3 / 3 + k4 / 6;
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
