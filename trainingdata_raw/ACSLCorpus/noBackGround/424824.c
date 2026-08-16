#include <stdint.h>

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures ((x) < (a)) ==> \result == 0;
    ensures ((x) >= (a)) ==> \result == 10;
*/
int32_t func(int32_t x, int32_t a)
{
    int32_t res;

    if (x >= a)
    {
        //@ assert ((x) >= (a));
        res = 10;
    }
    else
    {
        //@ assert ((x) < (a));
        res = 0;
    }

    return res;
}
