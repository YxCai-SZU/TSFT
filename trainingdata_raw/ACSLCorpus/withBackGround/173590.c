#include <limits.h>

/*@
    predicate non_negative(integer x) = x >= 0;
    predicate within_safe_range(integer x) = 0 <= x <= 46340;
    predicate no_overflow(integer x) = x * x <= INT_MAX;
*/

/*@
    logic integer square(integer x) = x * x;
*/

/*@
    lemma safe_square_lemma:
        \forall integer x; within_safe_range(x) ==> no_overflow(x);
*/

/*@
    requires within_safe_range(side_length);
    ensures non_negative(\result);
    ensures \result == square(side_length);
    assigns \nothing;
*/
int square_area(int side_length) {
    // Variable declarations at top of scope
    int result;

    //@ assert within_safe_range(side_length);
    //@ assert no_overflow(side_length);
    
    result = side_length * side_length;
    
    //@ assert non_negative(result);
    //@ assert result == square(side_length);
    
    return result;
}
