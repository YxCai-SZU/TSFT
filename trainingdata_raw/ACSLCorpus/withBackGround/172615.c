#include <stdint.h>

/*@
    predicate bounds(integer n, integer m) =
        2 <= n <= 100 && 2 <= m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma subtraction_bounds:
        \forall integer n, m; bounds(n, m) ==> 1 <= n - 1 <= 99 && 1 <= m - 1 <= 99;

    lemma multiplication_bounds:
        \forall integer n, m; bounds(n, m) ==> (n - 1) * (m - 1) <= 99 * 99;
*/

/*@
    requires bounds(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int32_t read(int32_t n, int32_t m)
{
    int32_t result;
    //@ assert bounds(n, m);
    //@ assert 1 <= n - 1 <= 99;
    //@ assert 1 <= m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    result = (n - 1) * (m - 1);
    //@ assert result == compute_result(n, m);
    return result;
}
