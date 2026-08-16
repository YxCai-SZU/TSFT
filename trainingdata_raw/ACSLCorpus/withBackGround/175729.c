#include <limits.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= 100;

    logic integer compute_result(integer n, integer m) =
        n * m - (n - 1) * m - n * (m - 1) + (n - 1) * (m - 1);

    lemma multiplication_bounds:
        \forall integer n, m;
        valid_range(n, m) ==>
        n * m <= 10000 &&
        (n - 1) * m <= 9900 &&
        n * (m - 1) <= 9900 &&
        (n - 1) * (m - 1) <= 9801;

    lemma result_simplification:
        \forall integer n, m;
        valid_range(n, m) ==>
        compute_result(n, m) == 1;
*/

/*@
    requires valid_range(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
long func(long n, long m)
{
    // Variable declarations at scope top
    long x;
    long y;
    long z;
    long w;
    long result;

    // Precondition verification
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 100;
    //@ assert 0 <= (n - 1) && (n - 1) <= 99;
    //@ assert 0 <= (m - 1) && (m - 1) <= 99;

    // Multiplication bounds verification
    //@ assert n * m <= 10000;
    //@ assert (n - 1) * m <= 9900;
    //@ assert n * (m - 1) <= 9900;
    //@ assert (n - 1) * (m - 1) <= 9801;

    // Core computation
    x = n * m;
    y = (n - 1) * m;
    z = n * (m - 1);
    w = (n - 1) * (m - 1);

    // Final calculation
    result = x - y - z + w;

    // Postcondition verification
    //@ assert result == compute_result(n, m);
    return result;
}
