#include <limits.h>

/*@
    predicate is_safe_square(integer x) = -46340 <= x <= 46340;
*/

/*@
    logic integer square_spec(integer x) = x * x;
*/

/*@
    lemma square_bounds:
        \forall integer x; is_safe_square(x) ==> 
            INT_MIN <= square_spec(x) <= INT_MAX;
*/

/*@
    requires is_safe_square(x);
    ensures \result == square_spec(x);
    assigns \nothing;
*/
int square(int x) {
    int result;
    
    //@ assert -46340 <= x && x <= 46340;
    //@ assert INT_MIN <= x * x <= INT_MAX;
    
    result = x * x;
    
    //@ assert result == square_spec(x);
    return result;
}
