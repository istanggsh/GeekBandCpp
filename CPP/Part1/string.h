#ifndef __STRING__
#define __STRING__

/* class with pointer member(s) 
 * 必须实现 copy ctor 和 copy assignment，而不是使用系统提供的默认版本
 * 默认版本多个指针指向同一个内存区域，可能导致内存泄漏和多次释放同一块内存区域的问题
 */
class String
{
public:
    String(const char *cstr = 0);         // ctor
    String(const String &str);            // copy ctor
    String &operator=(const String &str); // copy assignment
    ~String();                            // dtor
    char *get_c_str() const { return m_data; }

private:
    char *m_data;
};

#include <cstring>
#include <iostream>

/* 这里注意，该构造函数在声明时参数已有默认值，
 * 在定义时，默认值不能写出来。否则，编译将不通过
 * 也就是说参数默认值只能在函数的声明或定义中出现一次
 */
inline String::String(const char *cstr)
{
    if (cstr)
    {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline String::String(const String &str)
{
    /* 注意，同一个 class 的各个 objects 互为友元 */
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline String &String::operator=(const String &str)
{
    if (this == &str) // 重要，检测自我赋值
        return *this;
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

inline String::~String() { delete[] m_data; }

std::ostream &operator<<(std::ostream &os, const String &str) { return os << str.get_c_str(); }

#endif