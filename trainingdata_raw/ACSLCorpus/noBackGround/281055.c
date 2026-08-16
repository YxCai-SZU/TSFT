#include <stdint.h>

/*@
    requires 2 <= a && a <= 100;
    requires 2 <= b && b <= 100;
    ensures \result == a * b - a - b + 1;
    ensures \result > 0;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t ans;

    //@ assert a * b <= 10000;
    //@ assert a * b >= a + b;
    //@ assert a * b - a >= b;
    //@ assert a * b - a - b + 1 > 0;

    ans = a * b - a - b + 1;

    //@ assert ans == a * b - a - b + 1;
    //@ assert ans > 0;

    return ans;
}
