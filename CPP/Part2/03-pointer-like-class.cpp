template <typename T>
class shared_ptr
{
public:
    /* pointer-like class 必须实现这两个操作符的重载 */
    T &operator*() const { return *px; }
    T *operator->() const { return px; }
    shared_ptr(T *p) : px(p) {}

private:
    T *px;
};

struct Foo
{
    void method() {}
};

/* 迭代器也是智能指针，不止处理 * 和 ->，还处理 ++ -- == != */
template <typename T>
struct __list_node
{
    void *prev;
    void *next;
    T data;
};

template <typename T, typename Ref, typename Ptr>
struct __list_iterator
{
    typedef __list_iterator<T, Ref, Ptr> self;
    typedef Ptr pointer;
    typedef Ref reference;
    typedef __list_node<T> *link_type;
    link_type node;
    bool operator==(const self &x) const { return node == x.node; }
    bool operator!=(const self &x) const { return node != x.node; }
    reference operator*() const { return (&node).data; }
    pointer operator->() const { return &(operator*()); }
    self &operator++()
    {
        node = (link_type)((*node).prev);
        return *this;
    }
    self operator++(int)
    {
        self tmp = *this;
        ++*this;
        return tmp;
    }
    self &operator--()
    {
        node = (link_type)((node *).prev);
        return *this;
    }
    self operator--(int) 
    {
        self tmp = *this;
        --*this;
        return tmp;
    }
};

int main()
{
    shared_ptr<Foo> sp(new Foo);
    Foo f(*sp);
    sp->method(); // 不需要写成 sp->->method()
}
