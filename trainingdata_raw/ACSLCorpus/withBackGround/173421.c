#include <limits.h>

/*@
    predicate valid_params(integer n, integer x, integer y) =
        3 <= n && n <= 2000 &&
        1 <= x && x <= n &&
        1 <= y && y <= n &&
        x + 1 < y;

    lemma bounds_lemma:
        \forall integer n, x, y;
        valid_params(n, x, y) ==>
        (y - x - 1) >= 1 &&
        (n - 1) >= 0 &&
        (y - x - 1) >= 0;

    lemma result_nonnegative:
        \forall integer n, x, y;
        valid_params(n, x, y) ==>
        (n - 1) * (y - x - 1) >= 0;

    lemma result_upper_bound:
        \forall integer n, x, y;
        valid_params(n, x, y) ==>
        (n - 1) * (y - x - 1) <= (2000 - 1) * (2000 - 1 - 1);
*/

/*@
    requires valid_params(n, x, y);
    ensures \result == (n - 1) * (y - x - 1);
    assigns \nothing;
*/
long func(long n, long x, long y)
{
    // Variable declarations at top of scope
    long res;

    // Precondition assertions
    //@ assert 3 <= n && n <= 2000;
    //@ assert 1 <= x && x <= n;
    //@ assert 1 <= y && y <= n;
    //@ assert x + 1 < y;
    
    // Derived properties
    //@ assert y - x - 1 >= 1;
    
    // Bounds verification
    //@ assert (n - 1) * (y - x - 1) <= (2000 - 1) * (2000 - 1 - 1);
    //@ assert (n - 1) * (y - x - 1) >= 0;

    res = (n - 1) * (y - x - 1);
    
    // Postcondition verification
    //@ assert res == (n - 1) * (y - x - 1);
    
    return res;
}
