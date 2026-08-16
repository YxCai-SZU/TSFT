#include <stdint.h>

/*@
    predicate is_small(uint32_t n, uint32_t m) =
        n < 10 && m < 10;

    predicate is_large(uint32_t n, uint32_t m) =
        n >= 10 || m >= 10;

    logic integer product(integer n, integer m) = n * m;

    lemma product_bound:
        \forall integer n, m;
            1 <= n <= 20 && 1 <= m <= 20 ==> n * m <= 400;
*/

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures is_small(n, m) ==> \result == (int)(n * m);
    ensures is_large(n, m) ==> \result == -1;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at top
    uint32_t x;
    int32_t result;

    //@ assert n * m <= 400;
    x = n * m;

    if (n < 10 && m < 10)
    {
        //@ assert is_small(n, m);
        result = (int32_t)x;
    }
    else
    {
        //@ assert is_large(n, m);
        result = -1;
    }

    return result;
}
