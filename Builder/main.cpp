/*
Builder (abstract)
│
├── setPartA()
├── setPartB()
└── getResult()

ConcreteBuilder
├── Implements all build steps
└── Returns the product

Director
└── Uses builder to build object step-by-step

Product
└── The complex object being built

*/
#include <bits/stdc++.h>
using namespace std;

class Car
{
public:
    string engine;
    string wheels;
    string color;

    void show()
    {
        cout << "Car with " << engine << ", " << wheels << ", " << color << "\n";
    }
};

// Abstract Builder
class CarBuilder
{
public:
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
    virtual void paintColor() = 0;
    virtual Car *getCar() = 0;
};

// Concrete Builder
class SportsCarBuilder : public CarBuilder
{
private:
    Car *car;

public:
    SportsCarBuilder() { car = new Car(); }

    void buildEngine() override { car->engine = "V8 Engine"; }
    void buildWheels() override { car->wheels = "Alloy Wheels"; }
    void paintColor() override { car->color = "Red";}

    Car* getCar() override { return car;}

};

// Director
class Director {
private:
    CarBuilder* builder;
public:
    Director(CarBuilder* b) : builder(b) {}

    Car* construct() {
        builder->buildEngine();
        builder->buildWheels();
        builder->paintColor();
        return builder->getCar();
    }
};


int main()
{   
    CarBuilder* builder = new SportsCarBuilder();
    Director director(builder);

    Car* car = director.construct();
    car->show();

    delete car;
    delete builder;

    return 0;
}