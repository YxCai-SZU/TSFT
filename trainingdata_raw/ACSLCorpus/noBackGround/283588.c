#include <stdint.h>
#include <limits.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> ((n) % 1000 == 0);
*/
int func(int n)
{
    uint32_t n_unsigned;
    uint32_t remainder;
    int result;

    n_unsigned = (n < 0) ? (uint32_t)(-n) : (uint32_t)n;
    remainder = n_unsigned % 1000;

    if (remainder == 0)
    {
        //@ assert ((n) % 1000 == 0);
        result = 1;
    }
    else
    {
        result = 0;
    }

    return result;
}
