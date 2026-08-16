#include <stdbool.h>

/*@
    requires a <= 0xffffffff;
    ensures \result == (a % 2 != 0);
    assigns \nothing;
*/
bool is_odd(unsigned int a) {
    //@ assert a <= 0xffffffff;
    bool ret = (a % 2) != 0;
    //@ assert ret == (a % 2 != 0);
    return ret;
}

/*@
    requires a <= 0xffffffff;
    ensures \result == (a % 2 == 0);
    assigns \nothing;
*/
bool is_even(unsigned int a) {
    //@ assert a <= 0xffffffff;
    bool ret = (a % 2) == 0;
    //@ assert ret == (a % 2 == 0);
    return ret;
}

/*@
    ensures (\result == a && a >= b) || (\result == b && b > a);
    assigns \nothing;
*/
int max(int a, int b) {
    int ret;
    if (a > b) {
        //@ assert a >= b;
        ret = a;
    } else {
        //@ assert b >= a;
        ret = b;
    }
    //@ assert (ret == a && a >= b) || (ret == b && b > a);
    return ret;
}

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
int func(int a, int b) {
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    int ret = a - b * 2;
    if (ret > 0) {
        //@ assert ret == a - b * 2;
    } else {
        ret = 0;
    }
    //@ assert ret >= 0;
    //@ assert ret == a - b * 2 || ret == 0;
    return ret;
}
