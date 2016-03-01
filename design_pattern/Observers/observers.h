#ifndef OBSERVERS_H
#define OBSERVERS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Observer {
public:
    virtual ~Observer() = default;
//    virtual ~Observer() {}
    virtual void update() = 0;
};

class Observable {
public:
    virtual ~Observable() = default;
    virtual void registerObserver(Observer *o) = 0;
    virtual void unregisterObserver(Observer *o) = 0;
    virtual void notifyObserver() = 0;
};

class Subject : public Observable {
public:
    void registerObserver(Observer *o) {
        if(std::find(observers.begin(), observers.end(), o) == observers.end())
            observers.push_back(o);
    }
    void unregisterObserver(Observer *o) {
        vector<Observer *>::iterator it = std::find(observers.begin(), observers.end(), o);
        if(it != observers.end()) {
            observers.erase(it);
        }
    }
    void notifyObserver() {
        for(Observer *ob : observers) {
            ob->update();
        }
    }
    int getNum() {
        return num;
    }
    void setNum(int n) {
        num = n;
        notifyObserver();
    }

private:
    vector<Observer *> observers;
    int num;
};

class Foo : public Observer {
public:
    Foo(Subject *s, string name) : subject(s), name(name) {
        subject->registerObserver(this);
        num = 0;
    }
    ~Foo() {
        subject->unregisterObserver(this);
    }
    void update() {
        num = subject->getNum();
        std::cout << name << " update num = " << num << std::endl;
    }

private:
    Subject *subject;
    string name;
    int num;
};



#endif // OBSERVERS_H

