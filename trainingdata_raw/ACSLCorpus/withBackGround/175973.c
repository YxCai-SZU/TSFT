#include <stdint.h>

/*@
    predicate valid_input(integer n, integer m) =
        0 <= n && n <= 1000000000000 &&
        0 <= m && m <= 1000000000000;

    logic integer func_spec(integer n, integer m) =
        (2 * n > m) ? (m / 2) : (n + (m - 2 * n) / 4);

    lemma func_lemma:
        \forall integer n, m;
        valid_input(n, m) ==>
        func_spec(n, m) <= n + m / 2 &&
        func_spec(n, m) >= 0;
*/

/*@
    requires valid_input(n, m);
    ensures \result == func_spec(n, m);
    ensures \result <= n + m / 2;
    ensures \result >= 0;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at scope top
    uint64_t ans;

    //@ assert 0 <= n && n <= 1000000000000;
    //@ assert 0 <= m && m <= 1000000000000;

    //@ assert n * 2 <= 18446744073709551615;
    //@ assert m / 2 <= 18446744073709551615;

    if (n * 2 > m)
    {
        ans = m / 2;
    }
    else
    {
        ans = n + (m - n * 2) / 4;
    }

    //@ assert ans == func_spec(n, m);
    //@ assert ans <= n + m / 2;
    //@ assert ans >= 0;

    return ans;
}
