#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 2000000000);
    ensures \result <= k;
    ensures \result == ((a) < (k) ?
            ((b) < (k) - (a) ?
                ((c) < (k) - (a) - (b) ? (a) - (c) : (a) - ((k) - (a) - (b)))
                : (a))
            : (k));
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t sum;
    int64_t rst;
    
    sum = 0;
    rst = k;

    if (a < rst)
    {
        sum += a;
        rst -= a;
    }
    else
    {
        //@ assert k == ((a) < (k) ?             ((b) < (k) - (a) ?                 ((c) < (k) - (a) - (b) ? (a) - (c) : (a) - ((k) - (a) - (b)))                 : (a))             : (k));
        return k;
    }

    if (b < rst)
    {
        rst -= b;
    }
    else
    {
        //@ assert sum == ((a) < (k) ?             ((b) < (k) - (a) ?                 ((c) < (k) - (a) - (b) ? (a) - (c) : (a) - ((k) - (a) - (b)))                 : (a))             : (k));
        return sum;
    }

    int64_t min_val;
    if (c < rst)
    {
        min_val = c;
    }
    else
    {
        min_val = rst;
    }
    sum -= min_val;

    //@ assert sum == ((a) < (k) ?             ((b) < (k) - (a) ?                 ((c) < (k) - (a) - (b) ? (a) - (c) : (a) - ((k) - (a) - (b)))                 : (a))             : (k));
    return sum;
}
