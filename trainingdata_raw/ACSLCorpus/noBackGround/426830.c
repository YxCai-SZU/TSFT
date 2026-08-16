#include <stdint.h>

/*@
    requires (0 <= (n) && (n) <= 1);
    assigns \nothing;
    ensures (n == 0 ==> \result == 1);
    ensures (n == 1 ==> \result == 0);
*/
int32_t func(uint32_t n)
{
    int32_t res;

    //@ assert (0 <= (n) && (n) <= 1);
    //@ assert n == 0 || n == 1;

    if (n == 0)
    {
        //@ assert 1 - (int32_t)n == 1;
        res = 1 - (int32_t)n;
    }
    else
    {
        //@ assert 1 - (int32_t)n == 0;
        res = 1 - (int32_t)n;
    }

    //@ assert (n == 0 ==> res == 1) && (n == 1 ==> res == 0);
    return res;
}
