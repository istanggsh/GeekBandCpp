#include <iostream>

class Shape
{
public:
    Shape() {}
    virtual void draw() const = 0;
    void print() { std::cout << "Shape" << std::endl; }
};

class Rectangle : public Shape
{
public:
    Rectangle() {}
    virtual void draw() const
    {
        std::cout << "* * * * * *" << std::endl;
        std::cout << "*         *" << std::endl;
        std::cout << "*         *" << std::endl;
        std::cout << "*         *" << std::endl;
        std::cout << "* * * * * *" << std::endl;
    }
    void print() { std::cout << "Rectangle" << std::endl; }
};

class Square : public Rectangle
{
public:
    Square() {}
    virtual void draw() const
    {
        std::cout << "* * * * *" << std::endl;
        std::cout << "*       *" << std::endl;
        std::cout << "*       *" << std::endl;
        std::cout << "*       *" << std::endl;
        std::cout << "* * * * *" << std::endl;
    }
    void print() { std::cout << "Square" << std::endl; }
};

int main()
{
    /* 通过基类指针或引用调用虚函数，可以实现动态绑定 */
    Shape *s = new Rectangle();
    s->draw();  // Rectangle
    s->print(); // Shape
    s = new Square();  
    s->draw();  // Square
    s->print(); // Shape
    Rectangle r;
    Square sq;
    Shape &shape = r;
    shape.draw();   // Rectangle
    shape.print();  // Shape
    Shape &shape2 = sq;
    shape2.draw();
    shape2.print();

    return 0;    
}