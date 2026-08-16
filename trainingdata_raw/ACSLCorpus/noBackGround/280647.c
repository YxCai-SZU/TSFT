#include <stdint.h>

/*@
    requires 1 <= n <= 1000000000000000000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (n % 100) * 21 <= n;
    ensures \result == 0 ==> (n % 100) * 21 > n;
*/
int32_t func(uint64_t n)
{
    uint64_t a;
    int32_t result;

    a = n % 100;

    if (a * 21 <= n)
    {
        //@ assert ((a) * 21 <= (n));
        result = 1;
    }
    else
    {
        //@ assert !((a) * 21 <= (n));
        result = 0;
    }

    return result;
}
