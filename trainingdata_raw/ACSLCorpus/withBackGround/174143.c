#include <limits.h>

/*@
    predicate is_valid_input(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;

    logic integer compute_result1(integer n, integer m) =
        (n - 1) * (m - 1) + (n - 1) + 1;

    logic integer compute_result2(integer n, integer m) =
        (n - 1) * (m - 1) + (m - 1) + 1;

    lemma no_underflow_n:
        \forall integer n, m; is_valid_input(n, m) ==> n - 1 >= 0;

    lemma no_underflow_m:
        \forall integer n, m; is_valid_input(n, m) ==> m - 1 >= 0;

    lemma multiplication_non_negative:
        \forall integer n, m; is_valid_input(n, m) ==> (n - 1) * (m - 1) >= 0;

    lemma multiplication_bounded:
        \forall integer n, m; is_valid_input(n, m) ==> (n - 1) * (m - 1) <= 361;
*/

/*@
    requires is_valid_input(n, m);
    ensures \result >= 0;
    ensures \result == compute_result1(n, m) || \result == compute_result2(n, m);
    assigns \nothing;
*/
int func(int n, int m)
{
    // Declare all variables at the top
    int result;

    //@ assert n - 1 >= 0;
    //@ assert m - 1 >= 0;
    //@ assert (n - 1) * (m - 1) >= 0;
    //@ assert (n - 1) * (m - 1) <= 361;

    result = (n - 1) * (m - 1) + (n - 1) + 1;

    if (m > n)
    {
        result = (n - 1) * (m - 1) + (m - 1) + 1;
    }

    return result;
}
