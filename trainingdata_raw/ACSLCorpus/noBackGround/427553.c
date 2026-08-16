#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    ensures \result > 0;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert a > 1 && b > 1;
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert a >= 2;
    //@ assert b >= 2;
    //@ assert a * b <= 10000;
    //@ assert a * b >= a;
    //@ assert a * b >= a + b;
    //@ assert a * b - a - b + 1 <= 10000 - 2 - 2 + 1;
    //@ assert a * b - a - b + 1 > 0;

    result = a * b - a - b + 1;
    return result;
}
