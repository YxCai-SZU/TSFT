#include <stdint.h>

/*@
    requires 1 <= X <= 1000000000;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> ((X) / 100 <= 5 * ((X) / 100));
    ensures \result == 1 ==> ((X) / 100 > 5 * ((X) / 100));
*/
uint64_t func(uint64_t X)
{
    uint64_t n;
    uint64_t m;
    uint64_t result;

    n = X / 100;
    m = 5 * n;

    //@ assert n == X / 100;
    //@ assert m == 5 * n;

    if (X / 100 <= 5 * (X / 100))
    {
        //@ assert ((X) / 100 <= 5 * ((X) / 100));
        result = 0;
    }
    else
    {
        //@ assert ((X) / 100 > 5 * ((X) / 100));
        result = 1;
    }

    //@ assert result == 0 || result == 1;
    return result;
}
