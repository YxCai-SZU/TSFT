#include <stdbool.h>

/*@
    predicate bounds(integer x, integer y) = x <= 32 && y <= 32;
    predicate product_bound(integer x, integer y) = x * y <= 1024;
*/

/*@
    requires bounds(x, y);
    ensures \result == true ==> product_bound(x, y);
    assigns \nothing;
*/
bool check_nonlinear_arith_example1(unsigned int x, unsigned int y) {
    // Variable declarations at scope top
    bool result;

    //@ assert bounds(x, y);
    //@ assert product_bound(x, y);
    
    result = true;
    return result;
}
