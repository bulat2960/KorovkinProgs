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

    // Двигаюсь по разрядам начиная с самого младшего, i - номер разряда
    for (int i = 0; i < maxVecSize; i++)
    {
        int thisDigitNum, rcdDigitNum, resDigitNum;

        // Выбираю последовательно цифры из разрядов
        thisDigitNum = (i < thisVecSize) ? vec[thisVecSize - i - 1] : 0;
        rcdDigitNum = (i < rcdVecSize) ? rcdDigit.vec[rcdVecSize - i - 1] : 0;
        // Сумма двух чисел, digitAdd - число десяток переносимый в старший разряд
        resDigitNum = (sign == true ? 1 : -1) * thisDigitNum + (rcdDigit.sign == true ? 1 : -1) * rcdDigitNum + digitAdd;

        // Если модуль числа( число может быть и отрицательным ) больше 10, то выделяем единицы и десятки
        if (std::abs(resDigitNum) >= 10)
        {
            digitAdd = resDigitNum > 0 ? 1 : -1;   // Если число суммы отрицательное, то в старший разряд пойдет -1, иначе 1
            resDigitNum -= digitAdd * 10;      // Оставляем в resDigitNum только единицы
        }
        else // Иначе в старший разряд ничего не идет
        {
            digitAdd = 0;
        }
        // Запомним знак числа, вычисляем всегда, но нам нужен только самый старший, чтобы понять какой знак у результата
        // Если сам результат положительный и в страший разряд не идет отрицательный, то наше число будет положительный, иначе нет
        ResSign = (resDigitNum >= 0 && digitAdd >= 0);

        // Если сумма чисел с разными знаками, то проверим результат на отрицательность
        // И если так и есть, то в старший разряд идет -1, а само число увеличиваем на 10
        if ((sign != rcdDigit.sign) && (resDigitNum < 0))
        {
            digitAdd = -1;
            resDigitNum += 10;
        }
        // Записываем разряд в вектор
        vecRes[maxVecSize - i - 1] = std::abs(resDigitNum);
    }

    // Вот тут есть хитрость, если при сложении двух разнознаковых числе получается что в верхнем разряде будет -1
    // как при вычистании большего из меньшего, то полученный результат приводим...
    // Пример: из 12 вычесть 98 столбиком: Получаем (-1)14 => -( 100-14 ) = -86
    if ((sign != rcdDigit.sign) && digitAdd == -1)
    {
        // Получение числа 1000...(maxVecSize ноликов)
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
        // Если в верхнем разряде осталась единичка - добавляем ее в старший разряд
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

    // Цикл по разрядам второго числа
    for (int i = 0; i < rcdVecSize; i++)
    {
        Vector<int> vecRes(thisVecSize + 1);
        int thisDigitNum, rcdDigitNum, resDigitNum;
        int digitAdd = 0;

        // Цифры второго числа из разряда i
        rcdDigitNum = rcdDigit.vec[rcdVecSize - i - 1];
        for (int j = 0; j < thisVecSize; j++)
        {
            // Цифры первого числа из разряда i
            thisDigitNum = vec[thisVecSize - j - 1];
            // Перемножаю их
            resDigitNum = thisDigitNum * rcdDigitNum + digitAdd;
            // Десятки переносятся в старший разряд
            digitAdd = resDigitNum / 10;
            // Из самого числа берем только единицы
            resDigitNum -= digitAdd * 10;
            vecRes[thisVecSize - j] = resDigitNum; //Здесь thisVecSize-j т.к. vecRes на один разряд длинее
        }
        vecRes[0] = digitAdd;
        // Каждое следущее число из разряда увеличисваем на 10 - просто добавляем 0 к вектору в младший разряд
        for (int k = 0; k < i; k++)
        {
            vecRes.push_back(0);
        }
        // Суммируем все
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

    // Если делитель больше делимого - то просто выводим 0
    if (thisVecSize - rcdVecSize < 0)
    {
        result = LongIntDigit(vecRes, sign == rcdDigit.sign);
        return result;
    }

    for (int i = 0; i < thisVecSize - rcdVecSize + 1; i++)
    {
        // Делитель будем двигать до разряда делимого числа с помощью push_back(0)
        Vector<int> divider = rcdDigit.vec;
        for (int k = 0; k < thisVecSize - rcdVecSize - i; k++)
        {
            divider.push_back(0);
        }
        LongIntDigit lidDivider = LongIntDigit(divider, true);

        resDigitNum = 0;
        // По lidDelta - будем узнавать делится ли число и сколько раз - вычитанием
        lidDelta = lidDividend;
        while (lidDelta.sign == true)
        {
            lidDelta = lidDelta - lidDivider;
            // Если lidDelta стало отрицательным, то больше не делится
            if (lidDelta.sign == true)
            {
                resDigitNum++;
                lidDividend = lidDelta;
            }
        }
        // Запомнили на сколько разделилось при сдвиге на указанное количество разрядов
        vecRes.push_back(resDigitNum);
    }
    result = LongIntDigit(vecRes, sign == rcdDigit.sign);
    return result;
}

// Код почти аналогичный делению, только в той разницей, что выведется не количество делений в каждом разряде,
// а оставшееся число после всех вычитаний
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
