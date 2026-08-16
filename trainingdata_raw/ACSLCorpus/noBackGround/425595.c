#include <stdint.h>

/*@
    requires (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + (z) <= (x));
    ensures \result >= 0 && \result <= x;
    ensures \result == (((x) - (z)) / ((y) + (z)));
*/
int64_t func(int64_t x, int64_t y, int64_t z)
{
    int64_t cnt = 0;
    int64_t numerator = x - z;
    int64_t denominator = y + z;

    //@ assert numerator >= 0 && numerator <= x;
    //@ assert denominator >= 2 && denominator <= 200000;

    /*@
        loop invariant 0 <= numerator <= x;
        loop invariant 0 <= cnt <= x;
        loop invariant cnt <= x - numerator;
        loop invariant (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + (z) <= (x));
        loop invariant numerator == x - z - cnt * denominator;
        loop assigns numerator, cnt;
    */
    while (numerator >= denominator)
    {
        numerator -= denominator;
        cnt += 1;

        //@ assert cnt <= x - numerator;
    }

    //@ assert cnt >= 0 && cnt <= x;
    return cnt;
}
