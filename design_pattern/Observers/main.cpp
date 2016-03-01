#include <iostream>
#include "observers.h"
using namespace std;

int main()
{
    Subject s;
//    Observer *ob = new Foo(&s, "ob");
    Foo f1(&s, "f1");
    Foo f2(&s, "f2");
    Observer *f3 = new Foo(&s, "f3");

    s.setNum(100);
    s.unregisterObserver(&f1);
    s.setNum(200);
    s.unregisterObserver(&f2);
    s.setNum(300);
    s.notifyObserver();
    delete f3;
    s.setNum(400);

    cout << "Hello World!" << endl;
    return 0;
}

