/* Class Diagram

**Abstract Factory**
    --createButton()
    --createCheckbox()

**ConcreteFactory1 (WindowFactory)**
    --createButton() -> WindowsButton
    --createCheckbox() -> WindowsCheckbox

**ConcreteFactory2 (MacFactory)**
    --createButton() -> MacButton
    --createCheckbox -> MacCheckbox


AbstractProductA (Button)
AbstractProductB (Checkbox)

ConcreteProductA1 (WindowsButton)
ConcreteProductB1 (WindowsCheckbox)

ConcreteProductA1 (MacButton)
ConcreteProductB2 (MacCheckbox)


*/

#include <bits/stdc++.h>
using namespace std;
// Abstract Products
class Button
{
public:
    virtual void paint() = 0;
};

class Checkbox
{
public:
    virtual void check() = 0;
};

// Concrete Products - Windows
class WindowsButton : public Button
{
public:
    void paint() override
    {
        std::cout << "Rendering Windows Button\n";
    }
};

class WindowsCheckbox : public Checkbox
{
public:
    void check() override
    {
        std::cout << "Windows Checkbox Checked\n";
    }
};

// Concrete Products - Mac
class MacButton : public Button
{
public:
    void paint() override
    {
        std::cout << "Rendering Mac Button\n";
    }
};

class MacCheckbox : public Checkbox
{
public:
    void check() override
    {
        std::cout << "Mac Checkbox Checked\n";
    }
};

// Abstract Factory
class GUIFactory
{
public:
    virtual Button *createButton() = 0;
    virtual Checkbox *createCheckbox() = 0;
};

// Concrete Factories
class WindowsFactory : public GUIFactory
{
public:
    Button *createButton() override
    {
        return new WindowsButton();
    }
    Checkbox *createCheckbox() override
    {
        return new WindowsCheckbox();
    }
};

class MacFactory : public GUIFactory
{
public:
    Button *createButton() override
    {
        return new MacButton();
    }
    Checkbox *createCheckbox() override
    {
        return new MacCheckbox();
    }
};

// Client
void renderUI(GUIFactory *factory)
{
    Button *button = factory->createButton();
    Checkbox *checkbox = factory->createCheckbox();

    button->paint();
    checkbox->check();

    delete button;
    delete checkbox;
}

int main()
{
    GUIFactory *factory;

    factory = new WindowsFactory();
    renderUI(factory);
    delete factory;

    factory = new MacFactory();
    renderUI(factory);
    delete factory;

    return 0;
}