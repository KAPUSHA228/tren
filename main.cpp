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
	cout << "Исходный полином: " << polinom.ToString() << endl;
	TPolinom p = polinom;
	cout << "Его двойник: " << polinom.ToString() << endl;
	//p=p.MultMonom(a);
	//cout <<"Полином p после умножения на моном а: " << p.ToString() << endl;
	cout << (p == polinom);
	//p.AddMonom(b);
	//p.AddMonom(a);
	cout <<"Сложение П: "<<(polinom + p).ToString();
	cout<<"Умножение П: "<<(polinom * p).ToString();
	polinom.AddMonom(c);
	cout << "Добавив 3x1^2х2^3х3^4 : " << polinom.ToString() << endl;
    polinom.AddMonom(t);
	cout << "Добавив 5x1^1х2^2х3^1 : " << polinom.ToString() << endl;
	cout << " " << (polinom*3).ToString() << endl;
	cout << " " <<polinom.ToString() << endl;
 ;
	
}
