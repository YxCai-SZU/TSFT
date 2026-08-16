#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (x / 100 >= (x % 100) / 5 + (x % 100) % 5);
    assigns \nothing;
*/
bool func(unsigned int x) {
    unsigned int a0;
    unsigned int a1;
    unsigned int a2;
    unsigned int a3;
    bool result;

    //@ assert 1 <= x <= 100000;
    a0 = x / 100;
    //@ assert a0 == x / 100;
    a1 = x % 100;
    //@ assert a1 == x % 100;
    a2 = a1 / 5;
    //@ assert a2 == a1 / 5;
    a3 = a1 % 5;
    //@ assert a3 == a1 % 5;

    //@ assert a0 <= 1000;
    //@ assert a1 <= 100;
    //@ assert a2 <= 20;
    //@ assert a3 <= 4;
    //@ assert a2 + a3 <= 24;

    result = (a0 >= a2 + a3);
    return result;
}
