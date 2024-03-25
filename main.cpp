#include "TList.h"
#include "TPolynomial.h"
#include "TMatrix.h"
#include <iostream>
#include <vector>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	vector <TMonom> vector;
	TDynamicVector<TMonom> vec(2);
	TMonom a(8, 2, 3, 4), b(-2, 6, 7, 8), c(3, 2, 3, 4), t(5, 1, 2, 1);
	vec[0] = a;
	vec[1] = b;
	
	//TPolinom p2("3x1^2х2^3х3^4");
	TPolinom polinom(vec);
	TPolinom p = polinom;
	p=p.MultMonom(a);
	cout << p.ToString();
	//p.AddMonom(b);
	//p.AddMonom(a);
	//cout << "Исходный полином: " << polinom.ToString() << endl;
	polinom.AddMonom(c);

	//cout << "Добавив 3x1^2х2^3х3^4 : " << polinom.ToString() << endl;
    polinom.AddMonom(t);
	//cout << "Добавив 5x1^1х2^2х3^1 : " << polinom.ToString() << endl;
	//cout << " " << (polinom*3).ToString() << endl;
	//TPolinom ab = polinom + p;
	//cout << ab.ToString();
}
