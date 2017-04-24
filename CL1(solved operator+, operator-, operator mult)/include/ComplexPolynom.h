#ifndef COMPLEXPOLYNOM_H_INCLUDED
#define COMPLEXPOLYNOM_H_INCLUDED

class ComplexPolynom
{
	double* reArray;
	double* imArray;
	int deg;
public:
	ComplexPolynom();
	ComplexPolynom(int, double*, double*);
	ComplexPolynom(const ComplexPolynom&);
	ComplexPolynom& operator+=(const ComplexPolynom&);
	ComplexPolynom& operator-=(const ComplexPolynom&);
	ComplexPolynom& operator*=(const ComplexPolynom&);
	ComplexPolynom& operator/=(const ComplexPolynom&);
	void deleteZero();
	double* getPointValue(const double*);
	double* getReArray() const;
	double* getImArray() const;
	int getDeg() const;
	~ComplexPolynom();
};

#endif // COMPLEXPOLYNOM_H_INCLUDED
