struct _List_node_base
{
    _List_node_base *_M_next;
    _List_node_base *_M_prev;
};

/* Inheritance: is-a 
 * _List_node 继承 _List_node_base 的所有数据
 * base class 的 dtor 必须是 virtual
 */

template <typename _Tp>
struct _List_node : public _lIst_node_base
{
    _Tp _M_data;
};

/* Inheritance with virtual functions and polymorphism（多态）
 * non-virtual functions: 不希望 derived class 覆写 (override)
 * virtual functions: 希望 derived class 覆写 (override)
 * pure-virtual functions: base class 对其没有定义，一定要 derived class 覆写 (override)
 * 函数的继承应该理解为继承了调用权
 */

#include <string>

class Shape
{
public:
    virtual void draw() const = 0;              /* pure virtual */
    virtual void error(const std::string &msg); /* virtual */
    int objectID() const;                       /* non-virtual */
};

class Rectangle : public Shape
{
};

class Ellipse : public Shape
{
};