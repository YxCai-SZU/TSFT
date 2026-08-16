#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1;
    ensures \result <= 3;
*/
uint32_t func(uint64_t a, uint64_t b, uint64_t c)
{
    uint64_t max;
    uint32_t ans;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);

    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }

    //@ assert max == (((a) >= (b) && (a) >= (c)) ? (a) :         ((b) >= (a) && (b) >= (c)) ? (b) : (c));
    //@ assert max > 0;

    if (a == b && b == c) {
        ans = 1;
    } else if (a == b || b == c || c == a) {
        ans = 2;
    } else {
        ans = 3;
    }

    //@ assert ans == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) || (b) == (c) || (c) == (a)) ? 2 : 3);
    //@ assert ans >= 1 && ans <= 3;

    return ans;
}
