#include <iostream>

using namespace std;


long double f(long double x, long double y) {
	return pow(x, 2) + pow(y, 2);
}

//Metodo de Euler
long double euler(long double xn, long double yn, long double h) {
	long double xnt;
	do {
		xnt = xn;
		xn = xn + h;
		yn = yn + h*f(xnt, yn);
	} while (xn < 1.3999);
	return yn;
}

//Metodo de Runge-Kutta 2a Ordem
double rk2(double xn, double yn, double h) {
	double xnt;
	do {
		xnt = xn;
		xn = xn + h;
		yn = yn + h*f((xnt + h / 2), (yn + (h / 2)*f(xnt, yn)));
	} while (xn < 1.39999);
	return yn;
}

//Metodo de Runge-Kutta 4a Ordem
double rk4(double xn, double yn, double h){
	double d1, d2, d3, d4, xnt;
	do {
		xnt = xn;
		xn = xn + h;
		d1 = h*f(xnt, yn);
		d2 = h*f((xnt + h / 2), (yn + d1 / 2));
		d3 = h*f((xnt + h / 2), (yn + d2 / 2));
		d4 = h*f((xnt + h), (yn + d3));
		yn = yn + (d1 / 6) + (d2 / 3) + (d3 / 3) + (d4 / 6);
	} while (xn < 1.39999);
	return yn;
}

int main() {
	long double xn = 0, yn = 0, h = 0.1;

	//Metodo de Euler
	cout << "Metodo de Euler" << endl;
	cout << "S: " << euler(xn,yn,h) << endl;
	cout << "S': " << euler(xn, yn, h/2) << endl;
	cout << "S'': " << euler(xn, yn, h/4) << endl;
	cout << "QC: " << (euler(xn, yn, h / 2.0) - euler(xn, yn, h)) / (euler(xn, yn, h / 4.0) - euler(xn, yn, h / 2.0)) << endl;
	cout << "E: " << euler(xn, yn, h / 4.0) - euler(xn, yn, h / 2.0) << endl;

	//Metodo de RK2
	cout << endl;
	cout << "Metodo de RK2" << endl;
	cout << "S: " << rk2(xn, yn, h) << endl;
	cout << "S': " << rk2(xn, yn, h / 2.0) << endl;
	cout << "S'': " << rk2(xn, yn, h / 4.0) << endl;
	cout << "QC: " << (rk2(xn, yn, h / 2.0) - rk2(xn, yn, h)) / (rk2(xn, yn, h / 4.0) - rk2(xn, yn, h / 2.0)) << endl;
	cout << "E: " << (rk2(xn, yn, h / 4.0) - rk2(xn, yn, h / 2.0))/3 << endl;

	//Metodo de RK4
	cout << endl;
	cout << "Metodo de RK4" << endl;
	cout << "S: " << rk4(xn, yn, h) << endl;
	cout << "S': " << rk4(xn, yn, h / 2.0) << endl;
	cout << "S'': " << rk4(xn, yn, h / 4.0) << endl;
	cout << "QC: " << (rk4(xn, yn, h / 2.0) - rk4(xn, yn, h)) / (rk4(xn, yn, h / 4.0) - rk4(xn, yn, h / 2.0)) << endl;
	cout << "E: " << (rk4(xn, yn, h / 4.0) - rk4(xn, yn, h / 2.0)) / 15 << endl;

}
