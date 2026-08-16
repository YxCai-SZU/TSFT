#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3 && a != b;

    logic integer compute_result(integer a, integer b) =
        6 - a - b;

    lemma result_bounds:
        \forall integer a, b;
        valid_range(a, b) ==>
        1 <= compute_result(a, b) <= 3;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    ensures 1 <= \result <= 3;
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    unsigned int result;
    
    //@ assert valid_range(a, b);
    result = 6 - a - b;
    
    //@ assert result == compute_result(a, b);
    
    if (result == 1) {
        //@ assert result == 1;
        return 1;
    } else if (result == 2) {
        //@ assert result == 2;
        return 2;
    } else if (result == 3) {
        //@ assert result == 3;
        return 3;
    } else {
        // This branch should be unreachable due to preconditions
        //@ assert false;
        return 0;
    }
}
