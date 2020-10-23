template <typename T>
struct identity
{
    const T &operator()(const T &x) { return x; }
};

template <typename T1, typename T2>
struct pair
{
    T1 first;
    T2 second;
    pair() : first(T1()), second(T2()) {}
    pair(const T1 &a, const T2 &b) : first(a), second(b) {}
};

template <typename Pair>
struct select1st
{
    const typename Pair::first_type &operator()(const Pair &x) const { return x.first(); }
};

template <typename Pair>
struct select2nd
{
    const typename Pair::second_type &operator()(const Pair &x) const { return x.second(); }
};

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    cout << identity<int>()(3) << endl;
    return 0;
}