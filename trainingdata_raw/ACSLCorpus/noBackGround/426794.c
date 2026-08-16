#include <stdint.h>

/*@
    requires (1 <= (n) <= 10000 &&
        1 <= (k) <= 10000 &&
        1 <= (y) < (x) <= 10000);
    ensures \result == ((n) < (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k, int64_t x, int64_t y)
{
    int64_t result;

    //@ assert (1 <= (n) <= 10000 &&         1 <= (k) <= 10000 &&         1 <= (y) < (x) <= 10000);

    if (n < k)
    {
        //@ assert 1 <= n && n <= 10000;
        //@ assert 1 <= x && x <= 10000;
        //@ assert n * x <= 100000000;
        result = n * x;
    }
    else
    {
        //@ assert 1 <= k && k <= 10000;
        //@ assert 1 <= x && x <= 10000;
        //@ assert 1 <= y && y < x && x <= 10000;
        //@ assert 1 <= n && n <= 10000;
        //@ assert k * x <= 100000000;
        //@ assert (n - k) * y <= 100000000;
        result = k * x + (n - k) * y;
    }

    return result;
}
