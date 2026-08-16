#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= 100;

    logic integer compute_raw(integer n, integer m) = n - m * 2;

    lemma m_times_two_bounded:
        \forall integer m; 1 <= m <= 100 ==> m * 2 <= 200;
*/

/*@
    requires valid_params(n, m);
    ensures \result >= 0;
    ensures \result == compute_raw(n, m) || \result == 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int result;

    // Precondition assertions
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 100;
    //@ assert m * 2 <= 200;

    result = n - m * 2;

    if (result < 0)
    {
        result = 0;
    }

    // Postcondition verification
    //@ assert result >= 0 && (result == n - m * 2 || result == 0);
    return result;
}
