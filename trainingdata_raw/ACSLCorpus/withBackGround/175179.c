#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer func_result(integer a, integer b) =
        a - b > 0 ? a - b : 0;

    lemma result_nonnegative:
        \forall integer a, b; valid_range(a, b) ==> func_result(a, b) >= 0;

    lemma result_bound:
        \forall integer a, b; valid_range(a, b) ==> 
            func_result(a, b) <= a - 1 || func_result(a, b) == 0;

    lemma result_identity:
        \forall integer a, b; valid_range(a, b) ==> 
            func_result(a, b) == a - b || func_result(a, b) == 0;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result <= a - 1;
    ensures \result == a - b || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert valid_range(a, b);
    
    if (a - b > 0) {
        result = a - b;
    } else {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result <= a - 1 || result == 0;
    //@ assert result == a - b || result == 0;
    
    return result;
}
