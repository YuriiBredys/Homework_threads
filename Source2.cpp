#include <iostream>
#include <memory>
using namespace std;

int counter = 0;

class my_class
{
public:

    my_class(string name)
    {
        this->name_ = name;
        this->index = counter++;
        cout << "Created" << name_ << index <<endl;
    }

    my_class(const my_class& other):my_class(other.name_)
    {
        
    }

    ~my_class()
    {
        cout << "Destruct" << name_ << index <<endl;
    }

    void print()
    {
        cout << "Print" << name_ << index << endl;
    }

private:
    int index;
    string name_;
};

void Print(my_class a)
{
    a.print();
}

int main()
{
    my_class a("stackObject");
    auto_ptr<my_class> autoptr (new my_class("autoptr"));
    shared_ptr<my_class> sharedptr(new my_class("sharedptr"));
    unique_ptr<my_class> uniqueptr(new my_class("unique"));

    Print(a);
}
