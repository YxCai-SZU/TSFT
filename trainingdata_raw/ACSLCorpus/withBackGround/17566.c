#include <limits.h>

/*@
    predicate non_negative(integer l, integer b) = l >= 0 && b >= 0;
    predicate sum_within_bounds(integer l, integer b) = l * l + b * b <= INT_MAX;
    predicate l_square_safe(integer l, integer b) = l * l <= INT_MAX;
    predicate b_square_safe(integer l, integer b) = b * b <= INT_MAX;
*/

/*@
    lemma square_safety: \forall integer l, b;
        non_negative(l, b) && sum_within_bounds(l, b) ==> l_square_safe(l, b) && b_square_safe(l, b);
*/

/*@
    requires l >= 0 && b >= 0;
    requires l * l + b * b <= INT_MAX;
    ensures \result == l * l + b * b;
    assigns \nothing;
*/
int rectangle_diagonal_squared(int l, int b) {
    //@ assert non_negative(l, b);
    //@ assert sum_within_bounds(l, b);
    //@ assert l_square_safe(l, b);
    //@ assert b_square_safe(l, b);
    
    int l_square;
    int b_square;
    int result;
    
    l_square = l * l;
    b_square = b * b;
    result = l_square + b_square;
    
    //@ assert result == l * l + b * b;
    return result;
}
