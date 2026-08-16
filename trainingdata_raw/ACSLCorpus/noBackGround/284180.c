#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int32_t preference_f(int32_t a, int32_t b, int32_t c) {
    int32_t sum;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    //@ assert ((a) + (b) + (c)) >= 3;
    //@ assert ((a) + (b) + (c)) <= 300;

    sum = a + b + c;

    //@ assert sum >= 0;
    //@ assert sum <= 300;

    return sum;
}
