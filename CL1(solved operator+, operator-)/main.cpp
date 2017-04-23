#include <iostream>
#include <iomanip>
#include <cmath>
#include "ComplexPolynom.h"

using namespace std;

ComplexPolynom operator+(const ComplexPolynom& poly1, const ComplexPolynom& poly2)
{
    ComplexPolynom res = poly1;
    res += poly2;
    return res;
}

ComplexPolynom operator-(const ComplexPolynom& poly1, const ComplexPolynom& poly2)
{
    ComplexPolynom res = poly1;
    res -= poly2;
    return res;
}

ComplexPolynom operator*(const ComplexPolynom& poly1, const ComplexPolynom& poly2)
{
    ComplexPolynom res = poly1;
    res *= poly2;
    return res;
}

ComplexPolynom operator/(const ComplexPolynom& poly1, const ComplexPolynom& poly2)
{
    ComplexPolynom res = poly1;
    res /= poly2;
    return res;
}

void getPoly(double* reArr, double* imArr, int polyDeg)
{
    int deg = polyDeg;

    double finalRe[deg + 1];
    double finalIm[deg + 1];

    for (int i = 0; i <= deg; i++)
    {
        finalRe[i] = reArr[i];
        finalIm[i] = imArr[i];
    }

    if (finalRe[0] < 0)
    {
        finalRe[0] *= -1;
        finalIm[0] *= -1;
        cout << "-";
    }

    bool flag1 = false;
	for (int i = 0; i <= deg; i++)
    {
        if (finalRe[i] != 0 && finalIm[i] != 0)
        {
            cout << "(" << finalRe[i];
            (finalIm[i] < 0) ? cout << "-" << abs(finalIm[i]) : (abs(finalIm[i]) != 1) ? cout << "+" << finalIm[i] : cout << "+";
            cout << "i)";
        }
        if (finalRe[i] != 0 && finalIm[i] == 0)
        {
            cout << finalRe[i];
        }
        if (finalRe[i] == 0 && finalIm[i] != 0)
        {
            (finalIm[i] != 1) ? cout << "(" << finalIm[i] << "i)" : cout << "i";
        }
        if (finalRe[i] == 0 && finalIm[i] == 0)
        {
            continue;
        }
        flag1 = false;
        if (i < deg)
        {
            if (finalRe[i + 1] < 0)
            {
                finalRe[i + 1] *= -1;
                finalIm[i + 1] *= -1;
                flag1 = true;
            }
            (deg - i != 1) ? cout << "*x^" << deg - i : cout << "*x";
            (flag1 == true) ? cout << " - " : cout << " + ";
        }
    }
    cout << endl;
}

void getPointPoly(double* arr)
{
    cout << setprecision(10) << "Real = " << arr[0] << endl;
    cout << setprecision(10) << "Imaginary = " << arr[1] << endl;
}

int main()
{
    const int size1 = 4;
    const int size2 = 3;

	double Re1[size1] = {1, 2, 1, 6};
	double Im1[size1] = {1, -1, 2, 4};

	double Re2[size2] = {2, 7, 2};
	double Im2[size2] = {3, 5, 3};

	ComplexPolynom poly1(size1 - 1, Re1, Im1);
	ComplexPolynom poly2(size2 - 1, Re2, Im2);
	ComplexPolynom poly3 = poly1 * poly2;

    cout << "POLYNOME1" << endl;
    double* reArr1 = new double[size1];
	reArr1 = poly1.getReArray();
	double* imArr1 = new double[size1];
	imArr1 = poly1.getImArray();
	getPoly(reArr1, imArr1, poly1.getDeg());

    cout << "POLYNOME2" << endl;
	double* reArr2 = new double[size2];
	reArr2 = poly2.getReArray();
	double* imArr2 = new double[size2];
	imArr2 = poly2.getImArray();
	getPoly(reArr2, imArr2, poly2.getDeg());

    cout << "RESULT" << endl;
	double* reArr3 = new double[poly3.getDeg() + 1];
	reArr3 = poly3.getReArray();
	double* imArr3 = new double[poly3.getDeg() + 1];
	imArr3 = poly3.getImArray();
	getPoly(reArr3, imArr3, poly3.getDeg());

	double* pointArr = new double[2];
	pointArr[0] = 1;
	pointArr[1] = 3;
	pointArr = poly3.getPointValue(pointArr);
	getPointPoly(pointArr);

	delete[] reArr1;
	delete[] reArr2;
	delete[] reArr3;
	delete[] imArr1;
	delete[] imArr2;
	delete[] imArr3;
	delete[] pointArr;

    return 0;
}
