#include <stdint.h>

/*@
    predicate is_square(integer n, integer result) = result == n * n;
    logic integer square(integer n) = n * n;

    lemma square_bound:
        \forall integer n; 0 <= n <= 10000 ==> n * n <= 10000 * 10000;
*/

/*@
    requires n <= 10000;
    ensures \result == n * n;
    ensures is_square(n, \result);
*/
uint32_t find_square_num(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert n <= 10000;
    //@ assert n * n <= 10000 * 10000;

    result = n * n;

    //@ assert result == n * n;
    //@ assert is_square(n, result);

    return result;
}
