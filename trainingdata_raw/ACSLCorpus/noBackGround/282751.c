#include <stdbool.h>

/*@
    requires n >= 0;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
*/
bool is_odd(unsigned int n) {
    bool ret;
    //@ assert n % 2 == 0 || n % 2 == 1;
    ret = n % 2 != 0;
    //@ assert ret == (n % 2 != 0);
    return ret;
}

/*@
    requires a <= 100 && b <= 100;
    ensures \result == a * b;
    assigns \nothing;
*/
unsigned int nonlinear_multiplication(unsigned int a, unsigned int b) {
    unsigned int ret;
    //@ assert a * b <= 10000;
    ret = a * b;
    //@ assert ret == a * b;
    return ret;
}
