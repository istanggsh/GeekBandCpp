#include <iostream>

class Fraction
{
public:
    Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
    // 转换函数，无参无返回值类型
    operator double() const { return (double)m_numerator / m_denominator; }

private:
    int m_numerator;
    int m_denominator;
};

int main()
{
    Fraction f(3, 5);
    std::cout << 4 + f << std::endl;    // 调用 operator double() 将 f 转换为 double 0.6
    // 如果实现了对 operator+(int, Fraction) 的重载，会冲突
    // 或者实现了 non-explicit-one-argu-ctor 将4 转换为 Fraction 也会冲突
    return 0;
}
