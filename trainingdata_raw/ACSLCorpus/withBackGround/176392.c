#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 0 <= a <= 100;
    predicate b_in_range(integer b) = 0 <= b <= 100;
    predicate x_in_range(integer x) = 0 <= x <= 100;
    logic integer sum(integer a, integer b) = a + b;
    predicate result_condition(integer a, integer b, integer x) = 
        x <= sum(a, b) && a <= x;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && x_in_range(x);
    ensures \result == (x <= a + b && a <= x);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long x)
{
    bool result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert x_in_range(x);
    
    result = (x <= a + b) && (a <= x);
    
    //@ assert result == (x <= sum(a, b) && a <= x);
    
    return result;
}
