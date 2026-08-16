#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_expr(integer a, integer b) =
        a * 2 + 2 * (100 - a) >= b && b >= 0 ? 1 : 0;

    lemma condition_true:
        \forall integer a, b;
        valid_range(a, b) && (a * 2 + 2 * (100 - a) >= b && b >= 0) ==>
        compute_expr(a, b) == 1;

    lemma condition_false:
        \forall integer a, b;
        valid_range(a, b) && !(a * 2 + 2 * (100 - a) >= b && b >= 0) ==>
        compute_expr(a, b) == 0;
*/

/*@
    requires valid_range(a, b);
    ensures \result == (a * 2 + 2 * (100 - a) >= b && b >= 0);
*/
bool func(long a, long b)
{
    long expr_val;
    bool result;

    expr_val = a * 2 + 2 * (100 - a);
    
    //@ assert expr_val == a * 2 + 2 * (100 - a);
    
    if (expr_val >= b && b >= 0)
    {
        //@ assert expr_val >= b && b >= 0;
        result = true;
    }
    else
    {
        //@ assert !(expr_val >= b && b >= 0);
        result = false;
    }
    
    return result;
}
