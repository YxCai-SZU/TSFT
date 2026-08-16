/*@
    predicate valid_params(integer n, integer m, integer k) =
        1 <= n && 1 <= m && 0 <= k &&
        n <= 1000000000 && m <= 1000000000 && k <= n;

    predicate condition_holds(integer n, integer m, integer k) =
        n - k <= m && n - k >= 0;

    lemma subtraction_bounds:
        \forall integer n, m, k;
        valid_params(n, m, k) ==> n - k >= 0;
*/

#include <stdbool.h>

/*@
    requires valid_params(n, m, k);
    ensures \result == true <==> condition_holds(n, m, k);
    assigns \nothing;
*/
bool func(int n, int m, int k)
{
    int diff;
    bool result;

    //@ assert valid_params(n, m, k);
    diff = n - k;

    if (diff < 0 || diff > m)
    {
        result = false;
        //@ assert !condition_holds(n, m, k);
    }
    else
    {
        //@ assert condition_holds(n, m, k);
        result = true;
    }

    return result;
}
