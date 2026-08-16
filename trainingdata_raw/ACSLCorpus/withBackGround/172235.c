#include <stdbool.h>

/*@
    predicate bounds(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;

    logic integer remaining_val(integer n, integer i) = n - i;

    lemma remaining_bounds:
        \forall integer n, m, i;
            bounds(n, m) && 0 <= i <= m ==> 0 <= remaining_val(n, i) <= n;
*/

/*@
    requires bounds(n, m);
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at scope top
    unsigned int remaining = n;
    unsigned int i = 0;

    /*@
        loop invariant bounds(n, m);
        loop invariant 0 <= i <= m;
        loop invariant remaining == remaining_val(n, i);
        loop invariant remaining <= n;
        loop assigns remaining, i;
        loop variant m - i;
    */
    while (i < m)
    {
        //@ assert remaining == n - i;
        remaining -= 1;
        i += 1;
    }

    //@ assert remaining == n - m;
    return remaining == 0;
}
