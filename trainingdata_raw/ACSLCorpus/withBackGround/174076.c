#include <stdbool.h>

/*@
    predicate x_in_range(integer x) = 1 <= x <= 20;
    predicate y_in_range(integer y) = 1 <= y <= 20;
    logic integer square(integer x) = x * x;
    predicate square_le_400(integer x) = square(x) <= 400;
*/

/*@
    lemma square_bound: \forall integer x; x_in_range(x) ==> square_le_400(x);
*/

/*@
    requires x_in_range(x);
    requires y_in_range(y);
    ensures \result == (square(x) > y);
    assigns \nothing;
*/
bool check_nonlinear_arith(int x, int y) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert square_le_400(x);
    
    result = (x * x) > y;
    return result;
}
