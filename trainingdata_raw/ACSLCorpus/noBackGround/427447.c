#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (c) <= 100 &&
        1 <= (k) <= (a) + (b) + (c) + 1);
    ensures \result <= k;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t sum = 0;
    int64_t rest = k;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (c) <= 100 &&         1 <= (k) <= (a) + (b) + (c) + 1);

    if (a <= rest)
    {
        //@ assert a <= rest;
        sum += a;
        rest -= a;
        //@ assert sum == a;
        //@ assert rest == k - a;
    }
    else
    {
        //@ assert rest < a;
        return k;
    }

    //@ assert sum <= k;

    if (b <= rest)
    {
        //@ assert b <= rest;
        rest -= b;
        //@ assert rest == k - a - b;
    }
    else
    {
        //@ assert rest < b;
        rest -= rest;
        //@ assert rest == 0;
    }

    //@ assert rest >= 0;
    //@ assert sum <= k;

    sum -= rest;

    //@ assert sum <= k;
    return sum;
}
