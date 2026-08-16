#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    logic integer compute_result(integer n, integer m) =
        n - m < 0 ? 0 : n - m;

    lemma result_properties:
        \forall integer n, m;
        valid_range(n, m) ==>
        compute_result(n, m) >= 0 &&
        compute_result(n, m) <= n &&
        (compute_result(n, m) == n - m || compute_result(n, m) == 0);
*/

/*@
    requires valid_range(n, m);
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == n - m || \result == 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    int res;
    
    //@ assert valid_range(n, m);
    
    res = n - m;
    
    if (res < 0)
    {
        //@ assert res == n - m;
        //@ assert res < 0;
        res = 0;
        //@ assert res == 0;
    }
    else
    {
        //@ assert res == n - m;
        //@ assert res >= 0;
        //@ assert res <= n;
    }
    
    //@ assert res >= 0;
    //@ assert res <= n;
    //@ assert res == n - m || res == 0;
    
    return res;
}
