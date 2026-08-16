#include <stdbool.h>

/*@
    predicate is_positive(integer x) = x > 0;
    predicate is_bounded(integer x) = x <= 100;
    predicate valid_input(integer a, integer b, integer c) =
        is_positive(a) && is_positive(b) && is_positive(c) &&
        is_bounded(a) && is_bounded(b) && is_bounded(c);
    predicate result_condition(integer a, integer b, integer c, bool r) =
        r == (a < c && c < b);
*/

/*@
    requires valid_input(a, b, c);
    ensures \result == (a < c && c < b);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    bool result;

    //@ assert is_positive(a);
    //@ assert is_positive(b);
    //@ assert is_positive(c);
    //@ assert is_bounded(a);
    //@ assert is_bounded(b);
    //@ assert is_bounded(c);
    
    result = (a < c) && (c < b);
    
    //@ assert result_condition(a, b, c, result);
    
    return result;
}
