#include "ComplexPolynom.h"

ComplexPolynom::ComplexPolynom()
{
	reArray = nullptr;
	imArray = nullptr;
	deg = 0;
}

ComplexPolynom::ComplexPolynom(int _deg, double* _reArray, double* _imArray)
{
	deg = _deg;

	reArray = new double[deg + 1];
	imArray = new double[deg + 1];
	for (int i = 0; i <= deg; i++)
    {
        reArray[i] = _reArray[i];
        imArray[i] = _imArray[i];
    }
}

ComplexPolynom::ComplexPolynom(const ComplexPolynom& copyPoly)
{
	deg = copyPoly.deg;

	reArray = new double[deg + 1];
	imArray = new double[deg + 1];

	for (int i = 0; i <= deg; i++)
	{
		reArray[i] = copyPoly.reArray[i];
		imArray[i] = copyPoly.imArray[i];
	}
}

void ComplexPolynom::deleteZero()
{
    int startPos = 0;
	while (reArray[startPos] == 0 && imArray[startPos] == 0)
	{
        startPos++;
	}
	if (startPos > 0)
	{
	    int degTemp = deg - startPos;

		double* reTemp = new double[degTemp + 1];
		double* imTemp = new double[degTemp + 1];
		for (int i = 0; i <= degTemp; i++)
		{
			reTemp[i] = reArray[i + startPos];
			imTemp[i] = imArray[i + startPos];
		}

		delete[] reArray;
		delete[] imArray;

        reArray = new double[degTemp + 1];
        imArray = new double[degTemp + 1];

		for (int i = 0; i <= degTemp; i++)
        {
            reArray[i] = reTemp[i];
            imArray[i] = imTemp[i];
        }
		deg = degTemp;

		delete[] reTemp;
		delete[] imTemp;
	}
}

ComplexPolynom& ComplexPolynom::operator+=(const ComplexPolynom& poly)
{
	if (deg <= poly.deg)
    {
        int diff = poly.deg - deg;

		double* reTemp = new double[deg + 1];
		double* imTemp = new double[deg + 1];

		for (int i = 0; i <= deg; i++)
		{
			reTemp[i] = reArray[i];
			imTemp[i] = imArray[i];
		}

		delete[] reArray;
		delete[] imArray;

		deg = poly.deg;

		reArray = new double[deg + 1];
		imArray = new double[deg + 1];

		for (int i = 0; i <= deg; i++)
		{
			reArray[i] = poly.reArray[i];
            imArray[i] = poly.imArray[i];
		}

		for (int i = 0; i <= deg; i++)
        {
            reArray[i + diff] += reTemp[i];
            imArray[i + diff] += imTemp[i];
        }

        delete[] reTemp;
        delete[] imTemp;
	}
	else
    {
        int diff = deg - poly.deg;

		for (int i = 0; i <= poly.deg; i++)
		{
			reArray[i + diff] += poly.reArray[i];
			imArray[i + diff] += poly.imArray[i];
		}
	}
	deleteZero();
	return *this;
}

ComplexPolynom& ComplexPolynom::operator-=(const ComplexPolynom& poly)
{
	if (deg <= poly.deg)
    {
        int diff = poly.deg - deg;

		double* reTemp = new double[deg + 1];
		double* imTemp = new double[deg + 1];

		for (int i = 0; i <= deg; i++)
		{
			reTemp[i] = reArray[i];
			imTemp[i] = imArray[i];
		}

		delete[] reArray;
		delete[] imArray;

		deg = poly.deg;

		reArray = new double[deg + 1];
		imArray = new double[deg + 1];

		for (int i = 0; i <= deg; i++)
		{
			reArray[i] = poly.reArray[i] * -1;
            imArray[i] = poly.imArray[i] * -1;
		}

		for (int i = 0; i <= deg; i++)
        {
            reArray[i + diff] += reTemp[i];
            imArray[i + diff] += imTemp[i];
        }

        delete[] reTemp;
        delete[] imTemp;
	}
	else
    {
        int diff = deg - poly.deg;

		for (int i = 0; i <= poly.deg; i++)
		{
			reArray[i + diff] -= poly.reArray[i];
			imArray[i + diff] -= poly.imArray[i];
		}
	}
	deleteZero();
	return *this;
}

#include <iostream>
using namespace std;

ComplexPolynom& ComplexPolynom::operator*=(const ComplexPolynom& poly)
{
	double* reTemp = new double[deg + poly.deg + 1];
	double* imTemp = new double[deg + poly.deg + 1];

	for (int i = 0; i <= deg; i++)
    {
        cout << reArray[i] << ' ' << imArray[i] << endl;
    }
    cout << endl;
    for (int i = 0; i <= poly.deg; i++)
    {
        cout << poly.reArray[i] << ' ' << poly.imArray[i] << endl;
    }

	for (int i = 0; i <= deg + poly.deg; i++)
	{
		int k = 0;
		int l = i - k;

		while (l >= 0)
		{
			if (k <= deg && l <= poly.deg)
			{
				reTemp[i] += (reArray[k] * poly.reArray[l] - imArray[k] * poly.imArray[l]);
				imTemp[i] += (reArray[k] * poly.imArray[l] + poly.reArray[l] * imArray[k]);
			}
			k++;
			l--;
		}
	}

	delete[] reArray;
	delete[] imArray;

    deg += poly.deg;
	reArray = new double[deg + 1];
	imArray = new double[deg + 1];

	for (int i = 0; i <= deg; i++)
    {
        reArray[i] = reTemp[i];
        imArray[i] = imTemp[i];
    }

	delete[] reTemp;
	delete[] imTemp;

    deleteZero();
	return *this;
}

ComplexPolynom& ComplexPolynom::operator/=(const ComplexPolynom &poly)
{
	if (deg < poly.deg)
	{
		delete[] reArray;
		delete[] imArray;

		reArray = new double[1];
		imArray = new double[1];

		deg = 0;
		reArray[0] = 0;
		imArray[0] = 0;
	}
	else if (deg > poly.deg)
	{
		/*f(x) = An * x^n + An-1 * x^n-1+ ... + A1 * x + A0
		g(x) = Bs * x^s + Bs-1 * x^s-1+ ... + B1 * x + B0
		f(x) - An/Bs * x^(n-s) * g(x) = f1(x), n1 - степень f1(x)
		f1(x) - An1/Bs * x^(n1-s) * g(x) = f2(x), n2 - степень f2(x)
		и т.д.
		Целая часть f(x)/g(x) = q(x), остаток = r(x)
		q(x) = An/Bs * x^(n-s) + An1/Bs * x^(n1 - s) + An2/Bs * x^(n1 - s) + ....
		за k шагов дойдём до полинома fk(x), степень которого меньше g(x);
		fk(x) - остаток*/
		ComplexPolynom *coef = new ComplexPolynom;
		coef->deg = 0;
		coef->reArray = new double[1];
		coef->imArray = new double[1];
		//coef будет содержать в себе сначала An / Bs, потом An1 / Bs, An2 / Bs и т.д.

		ComplexPolynom *div  = new ComplexPolynom(*this); // now будет содержать :f(x), f1(x), f2(x) ..... - делимое

		ComplexPolynom *powx = new ComplexPolynom;
		powx->deg = div->deg - poly.deg;	//powx - это x в степени n-s,n1-s,n2-s ....

		powx->reArray = new double[powx->deg + 1];
		powx->imArray = new double[powx->deg + 1];

		deg = powx->deg;

		delete[] reArray;
		delete[] imArray;

		reArray = new double[deg + 1];
		imArray = new double[deg + 1];

		for (int i = 0; i <= deg; i++)
		{
			powx->reArray[i] = 0;
			powx->imArray[i] = 0;	//задаем начальные значения для степени х и выходного полинома
			reArray[i] = 0;
			imArray[i] = 0;
		}

		powx->reArray[0] = 1;
        powx->imArray[0] = 0;	//коэффициент 1 стоит перед степенью х

        double reNumerator = div->reArray[0] * poly.reArray[0] + div->imArray[0] * poly.imArray[0];
        double imNumerator = poly.reArray[0] * div->imArray[0] - div->reArray[0] * poly.imArray[0];
        double Denominator = poly.reArray[0] * poly.reArray[0] + poly.imArray[0] * poly.imArray[0];
		coef->reArray[0] = reNumerator / Denominator;
		coef->imArray[0] = imNumerator / Denominator;

		int counter = 0;
		while (powx->deg >= 0)	//пока степень х больше либо равна 0
		{
			reArray[counter] = coef->reArray[0];	//записываем коэффициенты в выходной полином в нужное место
			imArray[counter] = coef->imArray[0];

            ComplexPolynom digit1 = *div;
            ComplexPolynom digit2 = *powx;

            //digit2 *= (*coef);
            //digit2 *= (*powx);

            digit1 -= digit2;

            //mod - это остаток от деления, т.е. сначала f1(x), потом f2(x) и т.д.
			ComplexPolynom* mod = new ComplexPolynom(digit1);	//считаем остаток(который впоследствии будет делимым)

			delete div;  //освобождение памяти

			div = new ComplexPolynom(*mod); //копируем в now mod, т.к. при следующем проходе текущий mod будет делимым

			delete mod;	 //освобождение памяти
			delete powx;

			powx = new ComplexPolynom;	//задание новой степени х
			powx->deg = div->deg - poly.deg; //показатель степени равен разности показателей делимого и делителя
			if (powx->deg >= 0)	//если степень х неотрицательна
			{
				powx->reArray = new double[powx->deg + 1];	//выделение памяти для действительной и мнимой части powx
				powx->imArray = new double[powx->deg + 1];

				for (int i = 0; i < powx->deg; i++)
				{
					powx->reArray[i] = 0;
					powx->imArray[i] = 0;
				}

				powx->reArray[0] = 1;
                powx->imArray[0] = 0;	//заполнение полей для степени х

                reNumerator = div->reArray[0] * poly.reArray[0] + div->imArray[0] * poly.imArray[0];
                imNumerator = poly.reArray[0] * div->imArray[0] - div->reArray[0] * poly.imArray[0];
                Denominator = poly.reArray[0] * poly.reArray[0] + poly.imArray[0] * poly.imArray[0];
                coef->reArray[0] = reNumerator / Denominator;
                coef->imArray[0] = imNumerator / Denominator;
			}

			counter++;
		}

		delete coef;
		delete powx;
		delete div;
	}
	else //если полиномы одной степени, то целая часть равна единице
	{
	    delete[] reArray;
	    delete[] imArray;

		reArray = new double[1];
		imArray = new double[1];

		deg = 0;
		reArray[0] = 1;
		imArray[0] = 0;
	}
	return *this;
}

/*
polyC polyC::operator %(const polyC &pol1)	//операция взятия остатка аналогична операции деления, только на последнем шаге нужно в выходную переменную записать остаток
{
	polyC res;
	if (deg < pol1.deg)
	{
		res.deg = deg;
		res.real = new double[deg + 1];
		res.imaginary = new double[deg + 1];
		for (int i = 0; i <= deg; i++)
		{
			res.real[i] = real[i];
			res.imaginary[i] = imaginary[i];
		}
	}
	else
	{
		polyC *coef = new polyC; coef->deg = 0; coef->real = new double[1]; coef->imaginary = new double[1];
		polyC *now  = new polyC(*this);
		polyC *powx = new polyC; powx->deg = now->deg - pol1.deg;
		powx->real = new double[powx->deg + 1]; powx->imaginary = new double[powx->deg + 1];
		for (int i = 0; i < powx->deg; i++)
		{
			powx->real[i] = 0;
			powx->imaginary[i] = 0;
		}
		powx->real[powx->deg] = 1; powx->imaginary[powx->deg] = 0;
		coef->real[0] = (now->real[now->deg] * pol1.real[pol1.deg] + now->imaginary[now->deg] * pol1.imaginary[pol1.deg]) / (pol1.real[pol1.deg] * pol1.real[pol1.deg] + pol1.imaginary[pol1.deg] * pol1.imaginary[pol1.deg]);
		coef->imaginary[0] = (pol1.real[pol1.deg] * now->imaginary[now->deg] - now->real[now->deg] * pol1.imaginary[pol1.deg]) / (pol1.real[pol1.deg] * pol1.real[pol1.deg] + pol1.imaginary[pol1.deg] * pol1.imaginary[pol1.deg]);
		polyC *mod;
		while (powx->deg >= 0)
		{
			mod = new polyC((*now) - (*coef)*(*powx)*pol1);
			delete now;
			now = new polyC(*mod);
			delete mod;
			delete powx; powx = new polyC;
			powx->deg = now->deg - pol1.deg;
			if (powx->deg >= 0)
			{
				powx->real = new double[powx->deg + 1]; powx->imaginary = new double[powx->deg + 1];
				for (int i = 0; i < powx->deg; i++)
				{
					powx->real[i] = 0; powx->imaginary[i] = 0;
				}
				powx->real[powx->deg] = 1; powx->imaginary[powx->deg] = 0;
				coef->real[0] = (now->real[now->deg] * pol1.real[pol1.deg] + now->imaginary[now->deg] * pol1.imaginary[pol1.deg]) / (pol1.real[pol1.deg] * pol1.real[pol1.deg] + pol1.imaginary[pol1.deg] * pol1.imaginary[pol1.deg]);
				coef->imaginary[0] = (pol1.real[pol1.deg] * now->imaginary[now->deg] - now->real[now->deg] * pol1.imaginary[pol1.deg]) / (pol1.real[pol1.deg] * pol1.real[pol1.deg] + pol1.imaginary[pol1.deg] * pol1.imaginary[pol1.deg]);
			}
		}
		delete coef,powx;
		res.deg = now->deg; //в переменной now сохранится остаток от деления, копируем данные из now в res
		res.real = new double[res.deg + 1];
		res.imaginary = new double[res.deg + 1];
		for (int i = 0; i <= res.deg; i++)
		{
			res.real[i] = now->real[i];
			res.imaginary[i] = now->imaginary[i];
		}
		delete now;	//освобождаем память
	}
	return res;
}*/

double* ComplexPolynom::getPointValue(const double* inArr)
{
    double inRePoint = inArr[0];
    double inImPoint = inArr[1];
    double outRePoint = 0;
    double outImPoint = 0;

    for (int i = 0; i < deg; i++)
    {
        double reTemp1 = inRePoint;
        double imTemp1 = inImPoint;
        for (int j = i; j < deg - 1; j++)
        {
            double reTemp2 = (inRePoint * reTemp1 - inImPoint * imTemp1);
            double imTemp2 = (inRePoint * imTemp1 + inImPoint * reTemp1);
            reTemp1 = reTemp2;
            imTemp1 = imTemp2;
        }
        outRePoint += reArray[i] * reTemp1 - imArray[i] * imTemp1;
        outImPoint += reArray[i] * imTemp1 + imArray[i] * reTemp1;
    }
    outRePoint += reArray[deg];
    outImPoint += imArray[deg];

    double* pointArr = new double[2];
    pointArr[0] = outRePoint;
    pointArr[1] = outImPoint;
    return pointArr;
}

double* ComplexPolynom::getReArray() const
{
	return reArray;
}

double* ComplexPolynom::getImArray() const
{
	return imArray;
}

int ComplexPolynom::getDeg() const
{
	return deg;
}

ComplexPolynom::~ComplexPolynom()
{
    std::cout << "DESTRUCTOR" << std::endl;
	delete[] reArray;
	delete[] imArray;
}
