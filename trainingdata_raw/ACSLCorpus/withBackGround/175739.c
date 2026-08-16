#include <stdint.h>

/*@
    predicate is_triangular(integer n, integer ret) =
        n >= 0 && n <= 2 && ret == n * (n + 1) / 2;

    lemma triangular_non_negative:
        \forall integer n, ret;
            is_triangular(n, ret) ==> ret >= 0;

    lemma triangular_bound:
        \forall integer n;
            0 <= n <= 2 ==> n * (n + 1) / 2 <= 2 * (2 + 1) / 2;
*/

/*@
    requires n <= 2;
    ensures \result == n * (n + 1) / 2;
    ensures \result >= 0;
*/
uint32_t is_triangular(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t ret;

    //@ assert n >= 0;
    //@ assert n * (n + 1) / 2 <= 2 * (2 + 1) / 2;

    ret = n * (n + 1) / 2;
    return ret;
}
