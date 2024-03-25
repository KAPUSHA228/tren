#include "TList.h"
#include "TPolynomial.h"
#include "TMatrix.h"
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	TDynamicVector<TMonom> vec(2);
	TMonom a(8, 2, 3, 4), b(-2, 6, 7, 8), c(3, 2, 3, 4), t(5, 1, 2, 1);
	vec[0] = a;
	vec[1] = b;
	TPolinom polinom(vec);
	cout << "Исходный полином polinom: " << polinom.ToString() << endl;
	cout << "polinom после дифференцирования: " << polinom.Div(1,1).ToString() << endl;
	cout << "polinom после интегрирования: " << polinom.Integral(1, 1).ToString() << endl;
	TPolinom p = polinom;
	cout << "Его двойник р: " << polinom.ToString() << endl;
	//p=p.MultMonom(a);
	//cout <<"Полином p после умножения на моном а: " << p.ToString() << endl;
	//cout << (p == polinom);
	//p.AddMonom(b);
	//p.AddMonom(a);
	cout <<"Сложение polinom + p: "<<(polinom + p).ToString() << endl;
	cout<<"Умножение polinom * p: "<<(polinom * p).ToString() << endl;
	polinom.AddMonom(c);
	cout << "Добавив к polinom 3x1^2х2^3х3^4 : " << polinom.ToString() << endl;
    	polinom.AddMonom(t);
	cout << "Добавив к polinom 5x1^1х2^2х3^1 : " << polinom.ToString() << endl;
	cout << "Умножение polinom на константу k=3: " << (polinom*3).ToString() << endl;
	cout << "Исходный полином polinom для самопроверки: " <<polinom.ToString() << endl;
}
