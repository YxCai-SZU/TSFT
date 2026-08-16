#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        a - 2 * b;

    lemma result_nonnegative:
        \forall integer a, b;
        valid_range(a, b) && compute_result(a, b) >= 0 ==>
        compute_result(a, b) >= 0;

    lemma result_zero_or_diff:
        \forall integer a, b;
        valid_range(a, b) ==>
        (compute_result(a, b) >= 0 || compute_result(a, b) < 0);
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == 0 || \result == a - 2 * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert valid_range(a, b);
    
    result = a - 2 * b;
    
    //@ assert result == compute_result(a, b);
    
    if (result < 0) {
        result = 0;
    }
    
    //@ assert result >= 0;
    
    //@ assert result == 0 || result == compute_result(a, b);
    
    return result;
}
