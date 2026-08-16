#include <stdint.h>

/*@
    requires (1 <= (n) <= 10000 &&
        1 <= (k) <= 10000 &&
        1 <= (y) < (x) <= 10000);
    ensures \result == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k, int64_t x, int64_t y)
{
    //@ assert (1 <= (n) <= 10000 &&         1 <= (k) <= 10000 &&         1 <= (y) < (x) <= 10000);
    
    if (n <= k)
    {
        //@ assert n * x == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
        return n * x;
    }
    else
    {
        //@ assert k * x + (n - k) * y == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
        return k * x + (n - k) * y;
    }
}
