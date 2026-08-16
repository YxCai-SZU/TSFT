#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 100;

    logic integer compute_n(integer x) = 100 - x;
    logic integer compute_expr(integer x, integer n) = x * 2 + n;
    logic boolean compute_result(integer x, integer y) = 
        compute_expr(x, compute_n(x)) <= y;

    lemma n_correctness:
        \forall integer x; in_range(x) ==> compute_n(x) == 100 - x;
*/

/*@
    requires in_range(x);
    requires in_range(y);
    ensures \result == compute_result(x, y);
    assigns \nothing;
*/
bool func(int x, int y)
{
    int n;
    bool result;

    //@ assert in_range(x);
    //@ assert in_range(y);
    
    n = 100 - x;
    
    //@ assert n == compute_n(x);
    //@ assert x * 2 + n == compute_expr(x, n);
    
    result = (x * 2 + n) <= y;
    
    //@ assert result == compute_result(x, y);
    return result;
}
