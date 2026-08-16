#include <limits.h>

/*@
    predicate valid_range(integer n, integer m) =
        2 <= n <= 100 && 2 <= m <= 100;

    lemma product_bounds:
        \forall integer n, m;
            valid_range(n, m) ==> 
            (n - 1) * (m - 1) >= INT_MIN && 
            (n - 1) * (m - 1) <= INT_MAX;
*/

/*@
    requires valid_range(n, m);
    ensures \result == (n - 1) * (m - 1);
    assigns \nothing;
*/
int func(int n, int m) {
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= n - 1;
    //@ assert 1 <= m - 1;
    //@ assert (long long)(n - 1) * (long long)(m - 1) <= INT_MAX;
    //@ assert (n - 1) * (m - 1) >= INT_MIN;
    //@ assert (n - 1) * (m - 1) <= INT_MAX;

    result = (n - 1) * (m - 1);
    return result;
}
