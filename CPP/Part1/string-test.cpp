#include "string.h"

int main() {
    String s1("Hello");
    String s2("World");

    String s3(s2);
    String s4 = s2; // copy ctor 而不是 copy assignment，因为这里是初始化而不是赋值

    s3 = s1; // copy assignment

    std::cout << s1 << s2 << std::endl;
    std::cout << s3 << s4 << std::endl;
    
    return 0;
}