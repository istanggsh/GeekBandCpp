#ifndef __COMPLEX__
#define __COMPLEX__

class complex;
complex &__doapl(complex *ths, const complex &r);

/* class without pointer member(s) */
class complex
{
public:
    /* ctor */
    complex(double r = 0, double i = 0) : re(r), im(i) {} /* 初值列而不是赋值 */
    /* complex() : re(0), im(0) {} */                     // 此处不可重载，与第一个构造函数冲突

    /* pass/return by reference (to const) */
    /* return by reference 时注意，返回的对象不能是局部变量 */
    /* C++ 操作符也是函数，操作符重载就是函数重载 */
    complex &operator+=(const complex &);

    /* 函数在 class body 内定义完成，便自动成为 inline 函数 */
    /* const member functions（常量成员函数）：不会修改数据成员的函数，都要加 const
     * 因为普通成员函数是不能访问 const 对象的，而 const 成员函数可以访问 const 对象或普通对象。
     */
    double real() const { return re; }
    double imag() const { return im; }

    /* 相同 class 的各个 objects 互为 friend（友元）
     * 这只是个测试函数，仅为说明上述结论，与 complex 实现无关
     */
    int func(const complex &param)
    {
        // return param.real() + param.imag();
        return param.re + param.im;
    }

private:
    double re, im;

    /* 友元可以直接访问私有成员 */
    friend complex &__doapl(complex *, const complex &);
};

inline complex &__doapl(complex *ths, const complex &r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
    /* 传递者无需知道接收者以 reference 还是 value 的形式来接收，
     * 一律 return by value，这是 return by reference 比 return by pointer
     * 简洁的地方，return by pointer 需要确保接收者以 pointer 形式接收。
     */

    /* 为什么不是 return by void; return by reference/value 支持链式运算
     * 即：c1 += c2 += c3;
     */
}

/* 非静态的成员函数有一个隐藏的 this 指针参数，指向调用者对象 */
inline complex &complex::operator+=(const complex &r) { return __doapl(this, r); }

inline double real(const complex &c) { return c.real(); }
inline double imag(const complex &c) { return c.imag(); }

/* 操作符重载2：全局函数，没有 this 指针 */
inline complex operator+(const complex &x, const complex &y)
{
    // 不能 return by reference，因为返回的是 local/temp object
    // 创建临时对象的方法：typename();
    return complex(real(x) + real(y), imag(x) + imag(y));
}
inline complex operator+(const complex &x, double y) { return complex(real(x) + y, imag(x)); }
inline complex operator+(double x, const complex &y) { return complex(x + real(y), imag(y)); }

#include <iostream>
/* 这个操作符的重载只能是全局函数的形式，而不是成员函数，
 * 因为这个操作符只能作用于左边的 ostream 对象
 */
std::ostream &operator<<(std::ostream &os, const complex &x)
{
    return os << '(' << real(x) << ',' << imag(x) << ')';
}

#endif