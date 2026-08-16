#include <stdint.h>

/*@
    predicate valid_input(integer n, integer m) =
        2 <= n && n <= 100 &&
        2 <= m && m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma bounds_lemma:
        \forall integer n, m;
        valid_input(n, m) ==>
        1 <= n - 1 && n - 1 <= 99 &&
        1 <= m - 1 && m - 1 <= 99;

    lemma no_overflow_lemma:
        \forall integer n, m;
        valid_input(n, m) ==>
        1 <= compute_result(n, m) && compute_result(n, m) <= 9801;
*/


int64_t func(int64_t n, int64_t m)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert n > 1 && m > 1;
    //@ assert n - 1 >= 1 && m - 1 >= 1;
    //@ assert n - 1 >= 1;
    //@ assert 1 <= n - 1;
    //@ assert m - 1 >= 1;
    //@ assert 1 <= m - 1;
    //@ assert n - 1 <= 99;
    //@ assert m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    //@ assert (n - 1) * (m - 1) >= 1 * 1;

    result = (n - 1) * (m - 1);
    return result;
}
