#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a && a <= 100 && 1 <= b && b <= 100;

    predicate condition_holds(integer a, integer b) =
        a * 2 <= b && b * 8 <= a;
*/

/*@
    requires is_valid_range(a, b);
    assigns \nothing;
    ensures \result == (a * 2 <= b && b * 8 <= a);
*/
bool func(unsigned int a, unsigned int b)
{
    bool b_is_at_least_twice_a;
    bool a_is_at_least_one_eighth_b;
    bool result;

    //@ assert is_valid_range(a, b);
    
    b_is_at_least_twice_a = (a * 2 <= b);
    a_is_at_least_one_eighth_b = (b * 8 <= a);
    
    //@ assert b_is_at_least_twice_a == (a * 2 <= b);
    //@ assert a_is_at_least_one_eighth_b == (b * 8 <= a);
    
    result = b_is_at_least_twice_a && a_is_at_least_one_eighth_b;
    
    //@ assert result == (a * 2 <= b && b * 8 <= a);
    return result;
}
