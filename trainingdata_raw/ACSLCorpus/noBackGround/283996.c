#include <stdbool.h>

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    ensures \result <= 10000;
*/
unsigned int func(unsigned int a, unsigned int b) {
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert a * b <= 10000;
    unsigned int ans;
    ans = a * b;
    return ans;
}

/*@ ensures \result == ((n % 2) == 0); */
bool is_even(unsigned int n) {
    bool ret;
    //@ assert n % 2 == 0 ==> (n % 2) == 0;
    ret = (n % 2 == 0);
    return ret;
}

/*@ requires n > 0;
    ensures \result == ((n % 2) != 0);
*/
bool is_odd(unsigned int n) {
    bool ret;
    //@ assert n % 2 != 0 ==> (n % 2) != 0;
    ret = (n % 2 != 0);
    return ret;
}
