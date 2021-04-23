//
// Created by maxim on 23/04/2021.
//

#include <iostream>
using namespace std;

class Parent_A {
public:
    void speak() {
        cout << "parent!" << endl;
    }
};

class Parent_B {
public:
    void speak_loud() {
        cout << "PARENT!" << endl;
    }
};

class Brother: public Parent_A, public Parent_B {

};

class Sister: public Parent_A {

};

int main() {

    Parent_A parent;
    Brother brother;

    // C has an unique cast "function"
    float value = 3.23;
    // C cast example
    cout << (int) value << endl;

    // C++ has multiple cast "functions" because it add inheritance and templates that C had not
    // C++ static cast example to compare with C
    cout << static_cast<int>(value) << endl;

    // Works without any explicit casting because polymorphism
    // We're allowed to use the address or pointer to any subclass
    Parent_A *pp = &brother;

    // This won't work
    // Brother *pb = &parent;

    // Only way for this to work is using a static_cast
    // Still very unsafe because some methods in Brother which don't exist in Parent
    Brother *pb = static_cast<Brother *>(&parent);

    // Here parent is pointing a brother object
    Parent_A *ppb = &brother;
    // But as it's still instanciate as a Parent, we can't declare pbb as &ppb without a static cast
    Brother *pbb = static_cast<Brother *>(ppb);

    Parent_A &&p = static_cast<Parent_A &&>(parent);
    p.speak();

    Parent_A &&p2 = reinterpret_cast<Parent_A &&>(parent);
    p.speak();

    Parent_A parentA;
    //Brother bro = static_cast<Brother *>(parentA);

    if (bro == nullptr) {
        cout << "Invalid cast" << endl;
    } else {
        cout << bro << endl;
    }

    return 0;
}