#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    // Declare all variables at scope top
    int64_t result;

    //@ assert b * 2 <= 200;
    //@ assert a >= b * 2 || a < b * 2;

    if (a > b * 2) {
        //@ assert a >= b * 2;
        //@ assert a - b * 2 >= 0;
        result = a - b * 2;
    } else {
        result = 0;
    }

    return result;
}

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
int64_t func_list(int64_t a, int64_t b) {
    // Declare all variables at scope top
    int64_t result;

    //@ assert b * 2 <= 200;
    //@ assert a >= b * 2 || a < b * 2;

    if (a > b * 2) {
        //@ assert a >= b * 2;
        //@ assert a - b * 2 >= 0;
        result = a - b * 2;
    } else {
        result = 0;
    }

    return result;
}
