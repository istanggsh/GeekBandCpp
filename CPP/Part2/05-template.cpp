/* argument deduction
 * 类模板不能自动推导
 * 函数模板可以自动推导，但如果有多个参数，类型一致才可以推导
 */

/* 成员模板 */
template <typename T1, typename T2>
struct Pair
{
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    Pair() : first(T1()), second(T2()) {}
    Pair(const T1 &a, const T2 &b) : first(a), second(b) {}

    /* Member template */
    template <typename U1, typename U2>
    Pair(const Pair<U1, U2> &p) : first(p.first), second(p.second) {}
};

/* 应用场景：把一个由鲫鱼和麻雀组成的 Pair 拷贝到一个由鱼类和鸟类组成的 Pair 中 */
class Fish
{
};
class Carp : public Fish
{
};

class Bird
{
};
class Sparrow : public Bird
{
};

#include <iostream>

/* variadic template 数量不定的模板参数， C++11 */
void print()
{
    std::cout << "#args: 0" << std::endl;
}
template <typename T, typename... Types>
void print(const T &firstArg, const Types &... args)
{
    std::cout << "#args: " << sizeof...(args) << std::endl;     // sizeof...
    std::cout << firstArg << std::endl;
    print(args...); // 注意参数的写法，需要实现重载 void print() 当 #args=0 时才不会错误
}

int main()
{
    Pair<Fish, Bird> p(Pair<Carp, Sparrow>());
    print(7.5, "hello", true, 42);
    return 0;
}