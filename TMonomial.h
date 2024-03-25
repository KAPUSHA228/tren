#pragma once
class TMonom
{
private:
	double coef;
	int degX, degY, degZ;
public:
	TMonom() {
		coef = 1;
		degX = degY = degZ = 1;
	}
	TMonom(double _coef, int _degX, int _degY, int _degZ) {
		coef = _coef;
		degX = _degX;
		degY = _degY;
		degZ = _degZ;

	}
	void SetCoef(int cval) { coef = cval; }
	int GetCoef(void) { return coef; }
	int GetDegreeX(void) { return degX; }
	int GetDegreeY(void) { return degY; }
	int GetDegreeZ(void) { return degZ; }
	bool compare(const TMonom& other) {
		if ((degX != other.degX) ||
			(degY != other.degY) ||
			(degZ != other.degZ))
			return false;
		return true;
	}
	int* GetDegree(void) {
		int* d = new int[3];
		d[0] = degX;
		d[1] = degY;
		d[2] = degZ;
		return d;
	}
	void SetDegree(int xval, int yval, int zval) {
		degX = xval;
		degY = yval;
		degZ = zval;
	}
	bool operator==(const TMonom& other) {
		if ((coef == other.coef) &&
			(degX == other.degX) &&
			(degY == other.degY) &&
			(degZ == other.degZ))
			return false;
		return true;
	}
	void operator=(const TMonom& other) {
		coef = other.coef;
		degX = other.degX;
		degY = other.degY;
		degZ = other.degZ;
	}
	TMonom operator+(const TMonom& other) {
		TMonom t(*this);
		t.coef += other.coef;
		return t;
	}
	TMonom operator*(const TMonom& other) {
		TMonom t(*this);
		t.coef *= other.coef;
		t.degX += other.degX;
		t.degY += other.degY;
		t.degZ += other.degZ;
		return t;
	}
	bool operator!=(const TMonom& other) {
		if ((coef != other.coef) ||
			(degX != other.degX) ||
			(degY != other.degY) ||
			(degZ != other.degZ))
			return true;
		return false;
	}
	int operator [] (const TMonom& t) {}
	bool operator>(const TMonom& other) {
		if ((coef > other.coef) &&
			(degX > other.degX) &&
			(degY > other.degY) &&
			(degZ > other.degZ))
			return true;
		return false;
	}
	bool operator<(const TMonom& other) {
		if ((coef > other.coef) &&
			(degX > other.degX) &&
			(degY > other.degY) &&
			(degZ > other.degZ))
			return false;
		return true;
	}
};
