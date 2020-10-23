class Account
{
public:
    static double m_rate; // 声明而已
    /* static member function 没有 this 指针，只能处理静态数据 */
    static void set_rate(const double &x) { m_rate = x; }
};
/* static data member 需要在 class body 外定义，可以不初始化 */
double Account::m_rate = 8.0;

class Singleton
{
public:
    static Singleton &getInstance() { return s; }
    void setup() {}

private:
    Singleton();
    Singleton(const Singleton &r);
    static Singleton s;
};

/* MeyersSingleton 比 Singleton 好的地方在于：单例只在 getInstance 被调用之后才创建 */
class MeyersSingleton
{
public:
    static MeyersSingleton &getInstance()
    {
        static MeyersSingleton m;
        /* 因为是静态的，所以一次调用创建的对象是永远存在的 
         * 后面在调用也不创建新的对象，所以是单例模式
         */
        return m;
    }
    void setup() {}

private:
    MeyersSingleton();
    MeyersSingleton(const MeyersSingleton &r);
};

int main()
{
    /* 调用 static 函数的方法：
     * 1. 通过类名::直接调用
     */
    Account::set_rate(5.0);
    Account a;
    /* 2. 通过对象.调用 */
    a.set_rate(7.0);

    /* Singloeton */
    Singleton::getInstance().setup();

    /* MeyersSingleton */
    MeyersSingleton::getInstance().setup();

    return 0;
}