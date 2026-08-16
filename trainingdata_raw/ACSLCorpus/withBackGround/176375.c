#include <stdbool.h>

/*@ predicate in_range(integer a, integer b, integer x) =
    a <= x && x <= a + b;
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= x <= 100;
    ensures \result == (a <= x && x <= a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;
    
    //@ assert a <= 100 && b <= 100 && x <= 100;
    
    result = (x >= a && x <= a + b);
    
    //@ assert result == (a <= x && x <= a + b);
    
    return result;
}
