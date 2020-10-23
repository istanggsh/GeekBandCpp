#include <deque>

template <typename T>
/* queue has-a (composition) deque, queue is a adapter */
class queue // Adapter
{
protected:
    std::deque<T> c; // 底层容器 (container)
public:
    // 以下完全利用 c 的操作函数完成
    bool empty() const { return c.empty(); }
    size_type size() const { return c.size(); }
    reference front() { return c.front(); }
    reference back() { return c.back(); }
    void push(const value_type &x) { c.push_back(x); }
    void pop() { c.pop_front(); }
};

/* Delegation（委托）：composition by reference (pointer)
 * Handler/Body: pimpl (pointer to implementation)
 */
class StringRep
{
    friend class String;

public:
    StringRep(const char *s);
    ~StringRep();
    int count;  // 可以有多个 String 使用同一个 StringRep，引用计数

private:
    char *rep;
};

class String
{
public:
    String();
    String(const char *s);
    String(const String &s);
    String &operator=(const String &s);
    ~String();

private:
    StringRep *rep;
};

/* 第一个 composition， container 和 adapter 生命周期一致
 * 第一个 delegation，可以先有 String， 而 StringRep 具体的实现可以有多样
 * 当引用计数不为 1 时，说明有多个 String 对象共享同一份 StringRep 对象，
 * 如果有一个 String 对象要修改 StringRep 对象，那么需要自己单独生成一个 StringRep 对象
 * （copy-on-write）
 */