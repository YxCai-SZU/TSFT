#include <limits.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    lemma multiplication_bounds:
        \forall integer n, m;
        valid_range(n, m) ==> n * m <= 100 * 100;

    lemma subtraction_nonnegative:
        \forall integer n, m;
        valid_range(n, m) ==> n * m - m >= 0;

    lemma arithmetic_identity:
        \forall integer n, m;
        valid_range(n, m) ==> n * m - m == (n - 1) * m;
*/

/*@
    requires valid_range(n, m);
    ensures \result == n * m - m;
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int ans;

    // Precondition verification
    //@ assert valid_range(n, m);
    
    // Overflow safety verification
    //@ assert n * m <= 100 * 100;
    
    // Result non-negativity verification
    //@ assert n * m - m >= 0;
    
    // Arithmetic identity verification
    //@ assert n * m - m == (n - 1) * m;

    ans = n * m - m;
    
    // Postcondition verification
    //@ assert ans == n * m - m;
    
    return ans;
}
