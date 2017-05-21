#ifndef COMPLEXDIGIT_H
#define COMPLEXDIGIT_H

class ComplexDigit
{
    private:
        double a, b;
    public:
        ComplexDigit();
        ComplexDigit(double, double = 0.0);
        ComplexDigit(const ComplexDigit&);
        void operator=(const ComplexDigit&);
        double GetA() const;
        double GetB() const;

        double& GetA();
        double& GetB();

        ComplexDigit operator+(const ComplexDigit&);
        ComplexDigit operator-(const ComplexDigit&);
        ComplexDigit operator*(const ComplexDigit&);
        ComplexDigit operator/(const ComplexDigit&);
        ComplexDigit operator^(int);
        ComplexDigit operator-();
};

#endif // LONGINTDIGIT_H
