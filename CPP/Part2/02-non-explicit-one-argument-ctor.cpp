class Fraction
{
public:
    // // non-explicit-one-arg ctor，可以只传入分子 (two-parameter but one-argument)
    Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
    Fraction operator+(const Fraction &f)
    {
        return Fraction(m_numerator + f.m_numerator, m_denominator + f.m_denominator);
    }

private:
    int m_numerator;
    int m_denominator;
};

int main()
{
    Fraction f(3, 5);
    Fraction d2 = f + 4; // 调用non-explicit-one-arg ctor 将 4 转换为 Fraction，然后调用 operator+
    /* 如果构造函数是 explicit 的，就不能实现转换 
     * explicit Fraction(int, int) {}   
     */
}