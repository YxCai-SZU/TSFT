#include <stdint.h>

/*@
    requires -100 <= x <= 100;
    ensures \result == 1 || \result == 0 || \result == -1;
    ensures \result == 1 ==> x > 0;
    ensures \result == 0 ==> x == 0;
    ensures \result == -1 ==> x < 0;
    ensures (((x) > 0 ==> (\result) == 1) &&
        ((x) == 0 ==> (\result) == 0) &&
        ((x) < 0 ==> (\result) == -1));
 */
int64_t func(int64_t x)
{
    int64_t ans;

    if (x > 0)
    {
        ans = 1;
        //@ assert ans == 1;
    }
    else if (x == 0)
    {
        ans = 0;
        //@ assert ans == 0;
    }
    else
    {
        ans = -1;
        //@ assert ans == -1;
    }

    //@ assert ans == 1 || ans == 0 || ans == -1;
    return ans;
}
