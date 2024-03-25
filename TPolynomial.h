#pragma once
#include "THeadList.h"
#include "TMonomial.h"
#include "TMatrix.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
using namespace std;

const int precision = 4;

class TPolinom 
{
	list<TMonom> list;
public:
	TPolinom(); 
	TPolinom(TPolinom& other); 
	TPolinom(TDynamicVector<TMonom> vec);//
	TPolinom(string str); 
	TPolinom& operator=(TPolinom& other); 
	TPolinom operator+(TPolinom& q); 


	TPolinom AddMonom(TMonom newMonom); //
	TPolinom MultMonom(TMonom monom); 
	TPolinom AddPolinom(TPolinom& other); 
	TPolinom operator*(double coef); 
	TPolinom operator* (TPolinom& other);
	bool operator==(TPolinom& other); 
	bool operator!=(TPolinom& other); 
	string ToString(); //
};

TPolinom::TPolinom() //не проверял
{
}

TPolinom::TPolinom(TPolinom& other)//работает
{
	list = other.list;
}

TPolinom::TPolinom(TDynamicVector<TMonom> vec)//работает
{
	for (int i = 0; i <= vec.size()-1; i++)
	{
		TMonom d(vec[i].GetCoef(), vec[i].GetDegreeX(), vec[i].GetDegreeY(), vec[i].GetDegreeZ());
		list.push_back(d);
	}	
	//for (TMonom t : list) { cout<<t.GetCoef()<<endl;}
	/*this->InsertFirst(vec[0]);
	SetCurrentAt(0);
	TMonom currm = GetCurrentItem();
	int prevPow, nextPow, counter = 1, poliSize = 1;
	if (vector_size > 1) {
		for (int i = 1; i < vector_size; i++) {
			nextPow = vec[i].GetIndex();
			prevPow = GetCurrentItem().GetIndex();
			if (nextPow > prevPow) {
				TMonom newM;
				newM.SetCoef(vec[i].GetCoef());
				newM.SetIndex(vec[i].GetIndex());
				InsertFirst(newM);
				poliSize++;
			}
			else
			{
				while (nextPow < prevPow) {
					if (counter < poliSize) {
						GoNext();
						counter++;
						currm = GetCurrentItem();
						prevPow = currm.GetIndex();
					}
					else {
						TMonom newM;
						newM.SetCoef(vec[i].GetCoef());
						newM.SetIndex(vec[i].GetIndex());
						InsertLast(newM);
						poliSize++;
						return;
					}
				}

				if (nextPow == prevPow) {
					if (counter == 1) {
						currm.SetCoef(currm.GetCoef() + vec[i].GetCoef());
						InsertFirst(currm);
						Reset();
						for (size_t i = 0; i < counter + 1; i++) GoNext();
						DeleteCurrent();
					}
					else
					{
						currm.SetCoef(currm.GetCoef() + vec[i].GetCoef());
						DeleteCurrent();
						InsertCurrent(currm);
					}
				}
				else
				{
					TMonom newM;
					newM.SetCoef(vec[i].GetCoef());
					newM.SetIndex(vec[i].GetIndex());
					InsertCurrent(newM);
					poliSize++;
				}
			}
			counter = 1;
		}
	}
	Reset();
	pStop = nullptr;*/
}

TPolinom::TPolinom(string str)//не трогал
{
	/*size_t pos = 0;
	while (pos < str.length()) {
		double coef = 0.0;
		int degX = 0, degY = 0, degZ = 0;
		char var;
		if (isdigit(str[pos]) || str[pos] == '-' || str[pos] == '+') {
			size_t nextPos;
			coef = stod(str.substr(pos), &nextPos);
			pos += nextPos;
		}
		while (pos < str.length() && (str[pos] == 'x' || str[pos] == 'X' ||
			str[pos] == 'y' || str[pos] == 'Y' ||
			str[pos] == 'z' || str[pos] == 'Z')) {
			var = tolower(str[pos]);
			pos++;
			if (pos < str.length() && str[pos] == '^') {
				pos++;
				size_t nextPos;
				int deg = stoi(str.substr(pos), &nextPos);
				pos += nextPos;
				switch (var) {
				case 'x': degX = deg; break;
				case 'y': degY = deg; break;
				case 'z': degZ = deg; break;
				}
			}
			else {
				switch (var) {
				case 'x': degX = 1; break;
				case 'y': degY = 1; break;
				case 'z': degZ = 1; break;
				}
			}
		}
		this->AddMonom(TMonom(coef, degX, degY, degZ));
	}*/
}

TPolinom& TPolinom::operator=(TPolinom& other)//работает
{
	this->list = other.list;
	return *this;
}

TPolinom TPolinom::AddMonom(TMonom otherMon)//работает
{
	bool i = false;
	for (TMonom& var : this->list) {
		if (var.compare(otherMon)==true) { 
			var=var + otherMon; 
			i = true; 
			break; }
	}
	if(i == false) list.push_back(otherMon);
	return *this;
}
TPolinom TPolinom::AddPolinom(TPolinom& other)//работает
{
	for (TMonom var : other.list) { this->AddMonom(var); }

	return *this;
}

TPolinom TPolinom::MultMonom(TMonom monom)// работает
{
	for (TMonom& var : list) { var*monom; }
	return *this;
}

TPolinom TPolinom::operator+(TPolinom& other)//работает
{
	/*for (TMonom var : other.list) { this->AddMonom(var); }
	return *this;*/
	TPolinom res(*this);
	for (TMonom& var : other.list) { res.AddMonom(var); }
	
	return res;
}



TPolinom TPolinom::operator*(double _coef)//работает
{
	TPolinom res(*this);
	for (TMonom& var : res.list) {
		var.SetCoef(var.GetCoef() * _coef);
	
	}
	return res;
}

TPolinom TPolinom::operator*(TPolinom& other)//пока не работает
{
	TPolinom res(*this);
	res.list.clear();
	for (TMonom var : list) {
		for (TMonom var2 : other.list) {
			TMonom var3 = var * var2;
			res.AddMonom(var3);
		}
	}

	return res;
}

bool TPolinom::operator==(TPolinom& other)//не работает
{
	TPolinom res(*this);
	bool k = false;
	if (list.size() != other.list.size()) return false;
	for (TMonom& var : res.list) {
		for (TMonom var2 : other.list) {
			if (var == var2) { res.list.pop_front(); k = true; break; }
		}
		if (k == false) { return false; }
	}
	if (res.list.size() == 0) return true;
	else return false;
}

bool TPolinom::operator!=(TPolinom& other)//обратно ==
{
	
	return !(*this==other);
}

string TPolinom::ToString()//работает
{
	string res;
	for (TMonom var : list)
	{
		var.GetCoef() < 0 ? res += "-" : res += "+";
		res += to_string(abs(var.GetCoef())) +
			"x^" + to_string(var.GetDegree()[0]) +
			"y^" + to_string(var.GetDegree()[1]) +
			"z^" + to_string(var.GetDegree()[2])+" ";
		
	}
	cout << endl;
	
	return res;
}
