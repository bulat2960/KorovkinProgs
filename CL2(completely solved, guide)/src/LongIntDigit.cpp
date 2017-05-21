#include "LongIntDigit.h"

#include <cmath>

LongIntDigit::LongIntDigit()
{
    sign = true;
}

LongIntDigit::LongIntDigit(const Vector<char>& _vec)
{
    int start = 0;
    if (_vec[0] != '-')
    {
        sign = true;
    }
    else
    {
        start = 1;
        sign = false;
    }

    for (int i = start; i < _vec.size(); i++)
    {
        vec.push_back(static_cast<int>(_vec[i] - char(48)));
    }
}
LongIntDigit::LongIntDigit(const Vector<int>& _vec, bool _sign)
{
    vec = _vec;
    sign = _sign;
}

LongIntDigit::LongIntDigit(const LongIntDigit& rcdDigit)
{
    vec = rcdDigit.vec;
    sign = rcdDigit.sign;
}

void LongIntDigit::operator=(const LongIntDigit& rcdDigit)
{
    vec = rcdDigit.vec;
    sign = rcdDigit.sign;
}

LongIntDigit LongIntDigit::operator+(const LongIntDigit& rcdDigit)
{
    LongIntDigit result;

    int thisVecSize = vec.size();
    int rcdVecSize = rcdDigit.vec.size();
    int maxVecSize = std::max(thisVecSize, rcdVecSize);

    Vector<int> vecRes(maxVecSize);
    bool ResSign = true;

    int digitAdd = 0;

    // �������� �� �������� ������� � ������ ��������, i - ����� �������
    for (int i = 0; i < maxVecSize; i++)
    {
        int thisDigitNum, rcdDigitNum, resDigitNum;

        // ������� ��������������� ����� �� ��������
        thisDigitNum = (i < thisVecSize) ? vec[thisVecSize - i - 1] : 0;
        rcdDigitNum = (i < rcdVecSize) ? rcdDigit.vec[rcdVecSize - i - 1] : 0;
        // ����� ���� �����, digitAdd - ����� ������� ����������� � ������� ������
        resDigitNum = (sign == true ? 1 : -1) * thisDigitNum + (rcdDigit.sign == true ? 1 : -1) * rcdDigitNum + digitAdd;

        // ���� ������ �����( ����� ����� ���� � ������������� ) ������ 10, �� �������� ������� � �������
        if (std::abs(resDigitNum) >= 10)
        {
            digitAdd = resDigitNum > 0 ? 1 : -1;   // ���� ����� ����� �������������, �� � ������� ������ ������ -1, ����� 1
            resDigitNum -= digitAdd * 10;      // ��������� � resDigitNum ������ �������
        }
        else // ����� � ������� ������ ������ �� ����
        {
            digitAdd = 0;
        }
        // �������� ���� �����, ��������� ������, �� ��� ����� ������ ����� �������, ����� ������ ����� ���� � ����������
        // ���� ��� ��������� ������������� � � ������� ������ �� ���� �������������, �� ���� ����� ����� �������������, ����� ���
        ResSign = (resDigitNum >= 0 && digitAdd >= 0);

        // ���� ����� ����� � ������� �������, �� �������� ��������� �� ���������������
        // � ���� ��� � ����, �� � ������� ������ ���� -1, � ���� ����� ����������� �� 10
        if ((sign != rcdDigit.sign) && (resDigitNum < 0))
        {
            digitAdd = -1;
            resDigitNum += 10;
        }
        // ���������� ������ � ������
        vecRes[maxVecSize - i - 1] = std::abs(resDigitNum);
    }

    // ��� ��� ���� ��������, ���� ��� �������� ���� ������������� ����� ���������� ��� � ������� ������� ����� -1
    // ��� ��� ���������� �������� �� ��������, �� ���������� ��������� ��������...
    // ������: �� 12 ������� 98 ���������: �������� (-1)14 => -( 100-14 ) = -86
    if ((sign != rcdDigit.sign) && digitAdd == -1)
    {
        // ��������� ����� 1000...(maxVecSize �������)
        Vector<int> vecMil(maxVecSize);
        for (int i = 0; i < maxVecSize; i++)
        {
            vecMil[i] = 0;
        }
        vecMil.push_front(1);
        result = LongIntDigit(vecMil, true) + LongIntDigit(vecRes, false);
        result.sign = false;
    }
    else
    {
        // ���� � ������� ������� �������� �������� - ��������� �� � ������� ������
        if (std::abs(digitAdd) == 1)
        {
            vecRes.push_front(1);
        }
        result = LongIntDigit(vecRes, ResSign);
    }
    return result;
}

LongIntDigit LongIntDigit::operator-(const LongIntDigit& rcdDigit)
{
    LongIntDigit copyDigit = rcdDigit;
    copyDigit.sign == true ? copyDigit.sign = false : copyDigit.sign = true;
    return (*this + copyDigit);
}

LongIntDigit LongIntDigit::operator*(const LongIntDigit& rcdDigit)
{
    LongIntDigit result;

    int thisVecSize = vec.size();
    int rcdVecSize = rcdDigit.vec.size();

    // ���� �� �������� ������� �����
    for (int i = 0; i < rcdVecSize; i++)
    {
        Vector<int> vecRes(thisVecSize + 1);
        int thisDigitNum, rcdDigitNum, resDigitNum;
        int digitAdd = 0;

        // ����� ������� ����� �� ������� i
        rcdDigitNum = rcdDigit.vec[rcdVecSize - i - 1];
        for (int j = 0; j < thisVecSize; j++)
        {
            // ����� ������� ����� �� ������� i
            thisDigitNum = vec[thisVecSize - j - 1];
            // ���������� ��
            resDigitNum = thisDigitNum * rcdDigitNum + digitAdd;
            // ������� ����������� � ������� ������
            digitAdd = resDigitNum / 10;
            // �� ������ ����� ����� ������ �������
            resDigitNum -= digitAdd * 10;
            vecRes[thisVecSize - j] = resDigitNum; //����� thisVecSize-j �.�. vecRes �� ���� ������ ������
        }
        vecRes[0] = digitAdd;
        // ������ �������� ����� �� ������� ������������ �� 10 - ������ ��������� 0 � ������� � ������� ������
        for (int k = 0; k < i; k++)
        {
            vecRes.push_back(0);
        }
        // ��������� ���
        result = result + LongIntDigit(vecRes, sign == rcdDigit.sign);
    }
    return result;
}

LongIntDigit LongIntDigit::operator/(const LongIntDigit& rcdDigit)
{
    LongIntDigit result;

    int thisVecSize = vec.size();
    int rcdVecSize = rcdDigit.vec.size();
    int resDigitNum;

    Vector<int> vecRes;
    vecRes.push_back(0);

    LongIntDigit lidDelta;
    LongIntDigit lidDividend = LongIntDigit(vec, true);

    // ���� �������� ������ �������� - �� ������ ������� 0
    if (thisVecSize - rcdVecSize < 0)
    {
        result = LongIntDigit(vecRes, sign == rcdDigit.sign);
        return result;
    }

    for (int i = 0; i < thisVecSize - rcdVecSize + 1; i++)
    {
        // �������� ����� ������� �� ������� �������� ����� � ������� push_back(0)
        Vector<int> divider = rcdDigit.vec;
        for (int k = 0; k < thisVecSize - rcdVecSize - i; k++)
        {
            divider.push_back(0);
        }
        LongIntDigit lidDivider = LongIntDigit(divider, true);

        resDigitNum = 0;
        // �� lidDelta - ����� �������� ������� �� ����� � ������� ��� - ����������
        lidDelta = lidDividend;
        while (lidDelta.sign == true)
        {
            lidDelta = lidDelta - lidDivider;
            // ���� lidDelta ����� �������������, �� ������ �� �������
            if (lidDelta.sign == true)
            {
                resDigitNum++;
                lidDividend = lidDelta;
            }
        }
        // ��������� �� ������� ����������� ��� ������ �� ��������� ���������� ��������
        vecRes.push_back(resDigitNum);
    }
    result = LongIntDigit(vecRes, sign == rcdDigit.sign);
    return result;
}

// ��� ����� ����������� �������, ������ � ��� ��������, ��� ��������� �� ���������� ������� � ������ �������,
// � ���������� ����� ����� ���� ���������
LongIntDigit LongIntDigit::operator%(const LongIntDigit& rcdDigit)
{
    LongIntDigit result;

    int thisVecSize = vec.size();
    int rcdVecSize = rcdDigit.vec.size();
    int resDigitNum;

    LongIntDigit lidDelta;
    LongIntDigit lidDividend = LongIntDigit(vec, true);

    for (int i = 0; i < thisVecSize - rcdVecSize + 1; i++)
    {
        Vector<int> divider = rcdDigit.vec;
        for (int k = 0; k < thisVecSize - rcdVecSize - i; k++)
        {
            divider.push_back(0);
        }
        LongIntDigit lidDivider = LongIntDigit(divider, true);

        resDigitNum = 0;

        lidDelta = lidDividend;
        while (lidDelta.sign == true)
        {
            lidDelta = lidDelta - lidDivider;

            if (lidDelta.sign == true)
            {
                resDigitNum++;
                lidDividend = lidDelta;
            }
        }
    }
    if (sign == false)
    {
        lidDividend.sign = false;
    }
    return lidDividend;
}

LongIntDigit LongIntDigit::operator^(int deg)
{
    LongIntDigit result = *this;
    for (int i = 0; i < deg - 1; i++)
    {
        result = result * *this;
    }
    return result;
}

Vector<int> LongIntDigit::getDigit() const
{
    return vec;
}

bool LongIntDigit::getSign() const
{
    return sign;
}
