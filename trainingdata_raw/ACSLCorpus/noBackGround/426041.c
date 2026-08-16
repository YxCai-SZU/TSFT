#include <stdint.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures \result >= -c;
    ensures \result <= a;
    ensures \result <= k;
    ensures \result == ((a) >= (k) ? (k) :
        (a) + (b) >= (k) ? (a) :
        (a) - ((k) - (a) - (b)));
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans;

    //@ assert (0 <= (a) && 0 <= (b) && 0 <= (c) &&         1 <= (k) && (k) <= (a) + (b) + (c) &&         (a) + (b) + (c) <= 2000000000);

    if (a >= k)
    {
        ans = k;
        //@ assert ans == ((a) >= (k) ? (k) :         (a) + (b) >= (k) ? (a) :         (a) - ((k) - (a) - (b)));
    }
    else if (a + b >= k)
    {
        ans = a;
        //@ assert ans == ((a) >= (k) ? (k) :         (a) + (b) >= (k) ? (a) :         (a) - ((k) - (a) - (b)));
    }
    else
    {
        //@ assert a >= 0;
        //@ assert b >= 0;
        //@ assert c >= 0;
        //@ assert k >= 1;
        //@ assert a + b + c <= 2000000000;
        //@ assert k <= a + b + c;
        //@ assert k >= a + b;

        ans = a - (k - a - b);
        //@ assert ans == ((a) >= (k) ? (k) :         (a) + (b) >= (k) ? (a) :         (a) - ((k) - (a) - (b)));
    }

    //@ assert ans >= -c;
    //@ assert ans <= a;
    //@ assert ans <= k;
    return ans;
}
