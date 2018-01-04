#include <iostream>
#include <cmath>

using namespace std;

//Integracao numerica simples ou quadratura

/*
double f(double x) {
	return sin(x) / pow(x, 2);
}

//Metodo da Regra dos Trapezios
double trapezios(double n, double h, double a, double b) {
	double st = 0;
	for (int i = 0; i <= n; i++) {
		if (i == 0)
			st = f(a);
		else if (i == n)
			st += f(b);
		else
			st += 2 * f(a + h*i);
	}
	st = st * (h / 2);
	return st;
}

//Metodo de Simpson
double simpson(double n, double h, double a, double b) {
	double ss = 0;
	for (int i = 0; i <= n; i++) {
		if (i == 0)
			ss = f(a);
		else if (i == n)
			ss += f(b);
		else if ((i % 2) == 0)
			ss += 2 * f(a + h*i);
		else
			ss += 4 * f(a + h*i);
	}
	ss = ss * (h / 3);
	return ss;
}

int main() {
	const double pi = 3.14159265358979323846;
	double a = pi / 2, b = pi, n = 4;
	double h = (b - a) / n;
	double st, ss, stl, ssl, stll, ssll;

	st = trapezios(n, h, a, b);
	ss = simpson(n, h, a, b);

	h = h / 2;
	n = (b - a) / h;

	stl = trapezios(n, h, a, b);
	ssl = simpson(n, h, a, b);

	h = h / 2;
	n = (b - a) / h;

	stll = trapezios(n, h, a, b);
	ssll = simpson(n, h, a, b);

	//quoficiente de convergencia
	double qct = (stl - st) / (stll - stl); //para h'' ser adequado tem de dar aproximadamente 4
	double qcs = (ssl - ss) / (ssll - ssl); //para h'' ser adequado tem de dar aproximadamente 16

	//erros
	double errot = (stll - stl) / 3;
	double erros = (ssll - ssl) / 15;

	cout << "st: " << st << endl;
	cout << "ss: " << ss << endl;
	cout << "st': " << stl << endl;
	cout << "ss': " << ssl << endl;
	cout << "st'': " << stll << endl;
	cout << "ss'': " << ssll << endl;
	cout << "QCt: " << qct << endl;
	cout << "QCs: " << qcs << endl;
	cout << "Et: " << errot << endl;
	cout << "Es: " << erros << endl;

	system("pause");
}*/



//Integrac‹o numerica dupla ou cubatura

double f(double x, double y) {
	return exp(y - x);
}

int main() {
	double nx = 2, ny = 2;
	double a = 0, b = 0.5;
	double hx = (b - a) / nx, hy = (b - a) / ny;

	double soma0 = f(0, 0) + f(0, 0.5) + f(0.5, 0) + f(0.5, 0.5);
	double soma1 = f(0, 0.25) + f(0.25, 0) + f(0.5, 0.25) + f(0.25, 0.5);
	double soma2 = f(0.25, 0.25);

	double st = hx*hy / 4 * (soma0 + 2 * soma1 + 4 * soma2);
	double ss = hx*hy / 9 * (soma0 + 4 * soma1 + 16 * soma2);

	cout << "st: " << st << endl;
	cout << "ss: " << ss << endl;

	system("pause");
}
