//
// Created by maxim on 23/04/2021.
//
#include <iostream>
using namespace std;

class Job {
public:
    int exp;
    Job() : exp(0) {}
};

class Nurse : public virtual Job {
};

class Firefighter: public virtual Job {
};

class FirefighterNurse: public Nurse, public Firefighter {
};

/*
 * Not the best example as Job is a very abstract notion compared to Nurse or Firefighter
 * which are very specific but it's still working to demonstrate the below case behavior.
 */
int main() {
    FirefighterNurse* worker1 = new FirefighterNurse;
    worker1->exp = 2;

    /*
     * "reinterpret_cast" is purely a compile-time directive which instructs the compiler to treat expression as if it had new type.
     * If the object class has more than one base class, and the base class is not the first base class,
     * "reinterpret_cast" will do the wrong thing and fail to perform necessary adjustment to the pointer.
     */
    Job* worker2 = reinterpret_cast<Job*>(worker1);

    /*
     * "static_cast" has the advantage that the compiler will check weather FirefighterNurse
     * is actually derived from Job and perform any needed adjustment.
     */
    Job* worker3 = static_cast<Job*>(worker1);

    cout << worker1 << endl;
    cout << worker2 << endl;
    cout << worker3 << endl;

    cout << worker1->exp << endl;
    // No fail but we can see that the cast had make something wrong as the return value isn't the good one
    cout << worker2->exp << endl;
    cout << worker3->exp << endl;

    return 0;
}