#include <stdint.h>

/*@
    predicate is_multiple_of_1000(integer n) = n % 1000 == 0;
    logic integer complement_to_1000(integer n) = 1000 - (n % 1000);
*/

/*@
    requires 1 <= n <= 10000;
    ensures is_multiple_of_1000(n) ==> \result == 0;
    ensures !is_multiple_of_1000(n) ==> \result == complement_to_1000(n);
*/
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t n_mod_1000;
    int32_t result;

    n_unsigned = (n < 0) ? (uint32_t)(-n) : (uint32_t)n;
    n_mod_1000 = n_unsigned % 1000;

    if (n_mod_1000 == 0)
    {
        //@ assert n % 1000 == 0;
        result = 0;
    }
    else
    {
        //@ assert n % 1000 != 0;
        result = 1000 - (int32_t)n_mod_1000;
    }

    return result;
}
