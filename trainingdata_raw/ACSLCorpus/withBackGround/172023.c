#include <stddef.h>

/*@
    predicate valid_n(integer n) = 1 <= n <= 10000;

    logic integer remainder(integer n, integer m) = n - 1000 * ((n - m) / 1000);

    lemma loop_invariant_maintained:
        \forall integer n, m;
            valid_n(n) && m <= n && m >= 0 && remainder(n, m) == m && m >= 1000 ==>
            remainder(n, m - 1000) == m - 1000;
*/

/*@
    requires valid_n(n);
    ensures \result <= 1000;
    ensures \result == (1000 * (n / 1000) == n ? 0 : 1000 - (n % 1000));
*/
size_t func(size_t n)
{
    size_t m = n;

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant m <= n;
        loop invariant m >= 0;
        loop invariant remainder(n, m) == m;
        loop assigns m;
        loop variant m;
    */
    while (m >= 1000)
    {
        //@ assert remainder(n, m) == m;
        m -= 1000;
        //@ assert remainder(n, m) == m;
    }

    if (m == 0)
    {
        //@ assert 1000 * (n / 1000) == n;
        return 0;
    }
    else
    {
        //@ assert 1000 * (n / 1000) != n;
        //@ assert m == n % 1000;
        return 1000 - m;
    }
}
