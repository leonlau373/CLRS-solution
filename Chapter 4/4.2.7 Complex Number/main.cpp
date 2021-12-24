#include <iostream>
#include <vector>

using namespace std;

class ComplexNum
{
private:
    int m_real{};
    int m_imaginary{};

public:
    ComplexNum(int real = 0, int imaginary = 0)
    : m_real{ real }, m_imaginary{ imaginary }
    {

    }

    friend ComplexNum operator+(const ComplexNum& a, const ComplexNum& b);
    friend ComplexNum operator-(const ComplexNum& a, const ComplexNum& b);
    friend ComplexNum operator*(const ComplexNum& a, const ComplexNum& b);
    friend ostream& operator<<(ostream& out, const ComplexNum& a);
};

ComplexNum operator+(const ComplexNum& a, const ComplexNum& b)
{
    int real;
    int imaginary;

    real = a.m_real + b.m_real;
    imaginary = a.m_imaginary + b.m_imaginary;

    return {real, imaginary};
}

ComplexNum operator-(const ComplexNum& a, const ComplexNum& b)
{
    int real;
    int imaginary;

    real = a.m_real - b.m_real;
    imaginary = a.m_imaginary - b.m_imaginary;

    return {real, imaginary};
}

ComplexNum operator*(const ComplexNum& a, const ComplexNum& b)
{
    int s1 = a.m_real + a.m_imaginary;
    int s2 = b.m_real + b.m_imaginary;
    int s3 = a.m_real - a.m_imaginary;

    int p1 = b.m_real*s1;
    int p2 = a.m_imaginary*s2;
    int p3 = b.m_imaginary*s3;

    return {p1 - p2, p2 + p3};
}

ostream& operator<<(ostream& out, const ComplexNum& a)
{
    out << a.m_real << " + " << a.m_imaginary << 'i';

    return out;
}

int main()
{
    ComplexNum c1 {2,3};
    ComplexNum c2 {4,5};
    ComplexNum c3;
    c3 = c1*c2;

    cout << c3;

    return 0;
}
