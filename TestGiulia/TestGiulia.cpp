#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::vector;

class A {

public:

    virtual void print() { cout << "1"; }

};

class B : public A {

public:
     void print()  { cout << "2"; }
    
};

void ses(A& sos) {
    sos.print();
}

int main(void)
{
    B *c = new B();
    c->print();
    return 0;
}

