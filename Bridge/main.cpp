/*
Abstraction
│
├── refinedAbstraction

Implementation (interface)
│
├── concreteImplementationA
└── concreteImplementationB

*/

#include <bits/stdc++.h>
using namespace std;

// Implementation (Drawing API)
class DrawingAPI
{
public:
    virtual void drawCircle(double x, double y, double radius) = 0;
};

// Concrete Implementations
class DrawingAPI1 : public DrawingAPI
{
public:
    void drawCircle(double x, double y, double radius) override
    {
        cout << "API1.circle at (" << x << ", " << y << ") radius " << radius << "\n";
    }
};

class DrawingAPI2 : public DrawingAPI
{
public:
    void drawCircle(double x, double y, double radius) override
    {
        cout << "API2.circle at (" << x << ", " << y << ") radius " << radius << "\n";
    }
};

// Abstraction
class Shape
{
protected:
    DrawingAPI *drawingAPI;

public:
    Shape(DrawingAPI *api) : drawingAPI(api) {}
    virtual void draw() = 0;
};

// Refined Abstraction
class Circle : public Shape
{
private:
    double x, y, radius;

public:
    Circle(double x, double y, double radius, DrawingAPI *api)
        : Shape(api), x(x), y(y), radius(radius) {}

    void draw() override
    {
        drawingAPI->drawCircle(x, y, radius);
    }
};

int main()
{
    Shape *shape1 = new Circle(1, 2, 3, new DrawingAPI1());
    Shape *shape2 = new Circle(5, 7, 11, new DrawingAPI2());

    shape1->draw(); // Uses API1
    shape2->draw(); // Uses API2

    delete shape1;
    delete shape2;

    return 0;
}