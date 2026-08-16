#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= a;
    ensures \result == (((k) >= (a) ? (a) : (k)) - 
        (((k) >= (a) ? (k) - (a) : 0) >= (b) ? ((k) >= (a) ? (k) - (a) : 0) - (b) : 0));
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans = 0;
    int64_t rst = k;

    // Use a
    //@ assert rst == k;
    if (rst >= a)
    {
        ans += a;
        rst -= a;
    }
    else
    {
        ans += rst;
        rst = 0;
    }

    // Use b
    //@ assert ans == (k >= a ? a : k);
    if (rst >= b)
    {
        rst -= b;
    }
    else
    {
        rst = 0;
    }

    // Use c
    //@ assert rst == ((k >= a ? k - a : 0) >= b ? (k >= a ? k - a : 0) - b : 0);
    ans -= rst;

    //@ assert ans == (((k) >= (a) ? (a) : (k)) -          (((k) >= (a) ? (k) - (a) : 0) >= (b) ? ((k) >= (a) ? (k) - (a) : 0) - (b) : 0));
    //@ assert ans <= a;
    return ans;
}
