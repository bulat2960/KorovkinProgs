#ifndef CPOLINOM_H
#define CPOLINOM_H

#include <cmath>
#include "Vector.h"
#include "ComplexDigit.h"
#define max(a,b) ((a) > (b) ? (a) : (b))

class CPolinom : public Vector<ComplexDigit>
{
    typedef Vector<ComplexDigit> CVector;
    public:
        CPolinom() : CVector(1) {};

        CPolinom(int _storSize) : CVector(_storSize) {};

        CPolinom(const ComplexDigit& _digit) : CVector(1)
        {
            (*this)[0] = _digit;
        }

        CPolinom(const CPolinom& cPoly) : CVector(cPoly.size())
        {
            for (int i = 0; i < size(); i++)
            {
                (*this)[i] = cPoly[i];
            }
        }

        CPolinom UpPower(int _num)
        {
            CPolinom result = (*this);
            for (int i = 0; i < _num; i++)
            {
                result.push_front(ComplexDigit(0));
            }
            return result;
        }

        ComplexDigit pointValue(ComplexDigit _digit)
        {
            ComplexDigit Result;
            for (int i = 0; i < size(); i++)
            {
                Result = Result + (*this)[i] * (_digit^i);
            }
            return Result;
        }

        void operator=(const CPolinom& cPoly)
        {
            ComplexDigit cdNull(0, 0);
            for(int i = 0; i < size(); i++)
            {
                i < cPoly.size() ? (*this)[i] = cPoly[i] : (*this)[i] = cdNull;
            }
        }

        CPolinom operator+(const CPolinom& cPoly)
        {
            int size1 = this->size();
            int size2 = cPoly.size();
            int maxSize = max(size1, size2);

            CPolinom result(maxSize);
            ComplexDigit cdA, cdB, cdNull(0, 0);

            for (int i = 0; i < maxSize; i++)
            {
                i < size1 ? cdA = (*this)[i] : cdA = cdNull;
                cout << cdA << endl;
                i < size2 ? cdB = cPoly[i] : cdB = cdNull;
                result[i] = cdA + cdB;
                cout << "RESULT = " << result << endl;
            }
            return result;
        }

        CPolinom operator-(const CPolinom& cPoly)
        {
            int size1 = this->size();
            int size2 = cPoly.size();
            int maxSize = max(size1, size2);

            CPolinom result(maxSize);
            ComplexDigit cdA, cdB, cdNull(0, 0);

            for (int i = 0; i < maxSize; i++)
            {
                i < size1 ? cdA = (*this)[i] : cdA = cdNull;
                i < size2 ? cdB = cPoly[i] : cdB = cdNull;
                result[i] = cdA - cdB;
            }
            return result;
        }

        CPolinom operator*(const CPolinom& cPoly)
        {
            int size1 = this->size();
            int size2 = cPoly.size();
            int maxSize = size1 + size2 - 1;

            CPolinom result(maxSize);
            ComplexDigit cdA, cdB;

            for (int i = 0; i < size1; i++)
            {
                for (int j = 0; j < size2; j++)
                {
                    cdA = (*this)[i];
                    cdB = cPoly[j];
                    result[i + j] = result[i + j] + cdA * cdB;
                }
            }
            return result;
        }

        CPolinom operator/(const CPolinom& cPoly)
        {
            int size1 = this->size();
            int size2 = cPoly.size();

            if (size1 < size2)
            {
                return CPolinom(1);
            }

            int maxSize = size1 - size2 + 1;
            const ComplexDigit& HighPower = cPoly[size2 - 1];
            ComplexDigit mult;

            CPolinom result(maxSize);
            CPolinom remain = (*this);
            CPolinom divider = cPoly;

            for (int i = 0; i < maxSize; i++)
            {
                mult = remain[size1 - i - 1] / HighPower;
                result[maxSize - i - 1] = mult;
                remain = remain - divider.UpPower(maxSize-i-1) * mult;
            }
            return result;
        }

        CPolinom operator%(const CPolinom& cPoly)
        {
            int size1 = this->size();
            int size2 = cPoly.size();

            if (size1 < size2)
            {
                return *this;
            }

            int maxSize = size1 - size2 + 1;
            const ComplexDigit& HighPower = cPoly[size2 - 1];
            ComplexDigit mult;

            CPolinom result(size2 - 1);
            CPolinom remain = (*this);
            CPolinom divider = cPoly;

            for (int i = 0; i < maxSize; i++)
            {
                mult = remain[size1 - i - 1] / HighPower;
                remain = remain - divider.UpPower(maxSize - i - 1) * mult;
            }
            result = remain;
            return result;
        }
};

#endif // CPOLINOM_H
