#include <limits.h>

/*@
    predicate valid_range(integer v) =
        1 <= v && v <= 20;

    logic integer min_sum(integer n, integer m) =
        n + m < 20 ? n + m : 20;

    lemma result_bounds:
        \forall integer n, m;
        valid_range(n) && valid_range(m) ==>
            n + m - min_sum(n, m) >= 0 &&
            n + m - min_sum(n, m) <= n + m;
*/

/*@
    requires valid_range(n);
    requires valid_range(m);
    ensures \result >= 0;
    ensures \result <= n + m;
    assigns \nothing;
*/
int func(int n, int m)
{
    int l;
    int result;

    //@ assert valid_range(n);
    //@ assert valid_range(m);
    
    if (n + m < 20) {
        l = n + m;
    } else {
        l = 20;
    }
    
    //@ assert l == min_sum(n, m);
    
    if (n + m - l < 0) {
        result = 0;
    } else {
        //@ assert n + m - l >= 0;
        //@ assert n + m - l <= n + m;
        result = n + m - l;
    }
    
    //@ assert result >= 0;
    //@ assert result <= n + m;
    return result;
}
