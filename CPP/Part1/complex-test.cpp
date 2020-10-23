#include "complex.h"

int main()
{
    complex c1(2, 1);
    complex c2(4, 0);

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;

    std::cout << c1 + c2 << std::endl;
    std::cout << (c1 += c2) << std::endl;
    std::cout << c1 + 5 << std::endl;
    std::cout << 5 + c1 << std::endl;

    return 0;
}