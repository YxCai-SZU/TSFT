#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (p));
    ensures \result == ((a) * 3 + (p)) / 2;
*/
long func(long a, long p)
{
    long sum;
    long res = 0;
    long count;
    bool is_negative = false;

    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (p) && (p) <= 100);
    sum = a * 3 + p;
    count = sum;

    if (sum < 0)
    {
        is_negative = true;
        count = -count;
    }

    /*@
        loop invariant 0 <= count <= ((a) * 3 + (p));
        loop invariant res >= 0;
        loop invariant res <= ((a) * 3 + (p)) / 2;
        loop invariant res == (sum - count) / 2;
        loop invariant count == sum - 2 * res;
        loop invariant (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
        loop assigns count, res;
        loop variant count;
    */
    while (count >= 2)
    {
        count -= 2;
        res += 1;
    }

    if (is_negative)
    {
        res = -res;
    }

    //@ assert res == ((a) * 3 + (p)) / 2;
    return res;
}
