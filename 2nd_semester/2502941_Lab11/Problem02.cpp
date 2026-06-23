#include <iostream>
using namespace std;

class Animal {
public:
    // Virtual functions
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }

    virtual void eat() {
        cout << "Animal eats food" << endl;
    }

    // Virtual destructor (good practice)
    virtual ~Animal() {}
};

// Derived class Dog
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }

    void eat() override {
        cout << "Dog eats meat" << endl;
    }
};

// Derived class Horse
class Horse : public Animal {
public:
    void sound() override {
        cout << "Horse neighs" << endl;
    }

    void eat() override {
        cout << "Horse eats grass" << endl;
    }
};

// Derived class Lion
class Lion : public Animal {
public:
    void sound() override {
        cout << "Lion roars" << endl;
    }

    void eat() override {
        cout << "Lion eats flesh" << endl;
    }
};

int main() {
    // Base class pointer
    Animal* a;

    Dog d;
    Horse h;
    Lion l;

    // Runtime polymorphism
    a = &d;
    a->sound();
    a->eat();

    cout << endl;

    a = &h;
    a->sound();
    a->eat();

    cout << endl;

    a = &l;
    a->sound();
    a->eat();

    return 0;
}