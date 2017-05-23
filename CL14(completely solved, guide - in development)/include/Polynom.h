#ifndef POLYNOM_H
#define POLYNOM_H

#include "Vector.h"

template<typename T>
class Polynom
{
    private:
        Vector<T> _stor;
    public:
        Polynom() {};

        Polynom(int elCount)
        {
            _stor = Vector<T>(elCount);
            for (int i = 0; i < _stor.size(); i++)
            {
                _stor[i] = 0;
            }
        }

        Polynom(const Vector<T>& stor)
        {
            _stor = stor;
        }

        void operator=(const Polynom& poly)
        {
            _stor = poly._stor;
        }

        Polynom upPower(int num)
        {
            Polynom result = *this;
            for (int i = 0; i < num; i++)
            {
                result._stor.push_back(0);
            }
            return result;
        }

        Polynom operator+(const Polynom& poly)
        {
            Polynom thisPoly = *this;
            Polynom rcdPoly = poly;

            int size1 = thisPoly._stor.size();
            int size2 = rcdPoly._stor.size();
            int flag;
            size1 > size2 ? flag = 1 : flag = 2;

            int maxSize = max(size1 - size2, size2 - size1);

            for (int i = 0; i < maxSize; i++)
            {
                flag == 1 ? rcdPoly._stor.push_front(0) : thisPoly._stor.push_front(0);
            }

            Polynom result;

            for (int i = 0; i < thisPoly._stor.size(); i++)
            {
                result._stor.push_back(thisPoly._stor[i] + rcdPoly._stor[i]);
            }
            return result;
        }

        Polynom operator-(const Polynom& poly)
        {
            Polynom thisPoly = *this;
            Polynom rcdPoly = poly;

            for (int i = 0; i < rcdPoly._stor.size(); i++)
            {
                rcdPoly._stor[i] *= -1;
            }

            Polynom result = thisPoly + rcdPoly;
            return result;
        }

        Polynom operator*(const Polynom& poly)
        {
            Polynom thisPoly = *this;
            Polynom rcdPoly = poly;

            Polynom result(thisPoly._stor.size() + rcdPoly._stor.size() - 1);

            for (int i = 0; i < thisPoly._stor.size(); i++)
            {
                for (int j = 0; j < rcdPoly._stor.size(); j++)
                {
                    result._stor[i + j] += thisPoly._stor[i] * rcdPoly._stor[j];
                }
            }
            return result;
        }

        Polynom operator/(const Polynom& poly)
        {
            Polynom thisPoly = *this;
            Polynom rcdPoly = poly;

            int maxSize = thisPoly._stor.size() - rcdPoly._stor.size() + 1;
            Polynom result(maxSize);

            T mult;
            for (int i = 0; i < maxSize; i++)
            {
                mult = thisPoly._stor[i] / rcdPoly._stor[0];
                result._stor[i] = mult;
                Polynom tempRcdPoly = rcdPoly.upPower(maxSize - i - 1);
                for (int i = 0; i < tempRcdPoly._stor.size(); i++)
                {
                    tempRcdPoly._stor[i] *= mult;
                }
                thisPoly = thisPoly - tempRcdPoly;
            }
            return result;
        }

        Polynom operator%(const Polynom& poly)
        {
            Polynom thisPoly = *this;
            Polynom rcdPoly = poly;

            int maxSize = thisPoly._stor.size() - rcdPoly._stor.size() + 1;
            Polynom result(maxSize);

            T mult;
            for (int i = 0; i < maxSize; i++)
            {
                mult = thisPoly._stor[i] / rcdPoly._stor[0];
                Polynom tempRcdPoly = rcdPoly.upPower(maxSize - i - 1);
                for (int i = 0; i < tempRcdPoly._stor.size(); i++)
                {
                    tempRcdPoly._stor[i] *= mult;
                }
                thisPoly = thisPoly - tempRcdPoly;
            }
            result = thisPoly;
            return result;
        }

        T pointValue(T point1)
        {
            T sum = 0;
            for (int i = 0; i < _stor.size(); i++)
            {
                T element = _stor[i];
                for (int j = i + 1; j < _stor.size(); j++)
                {
                    element *= point1;
                }
                sum += element;
            }
            return sum;
        }

        friend ostream& operator<<(ostream& ost, const Polynom& poly)
        {
            int k = 0;
            for (int i = 0; i < poly._stor.size(); i++)
            {
                if (poly._stor[i] == 0)
                {
                    k++;
                }
                else
                {
                    break;
                }
            }
            Polynom tempRes(poly._stor.size() - k);
            for (int i = 0; i < poly._stor.size() - k; i++)
            {
                tempRes._stor[i] = poly._stor[i + k];
            }

            for (int i = 0; i < tempRes._stor.size() - 1; i++)
            {
                ost << tempRes._stor[i] << "*x^" << tempRes._stor.size() - i - 1 << " + ";
            }
            ost << tempRes._stor[tempRes._stor.size() - 1];
            return ost;
        }
};

#endif // POLYNOM_H
