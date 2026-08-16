#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer mod3(integer x) = x % 3;
    
    predicate result_condition(integer a, integer b, bool r) =
        r == (mod3(a) == 0 || mod3(b) == 0 || mod3(a + b) == 0);
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures result_condition(a, b, \result);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    //@ assert a + b <= 200;
    
    result = (a % 3 == 0) || (b % 3 == 0) || ((a + b) % 3 == 0);
    
    //@ assert result_condition(a, b, result);
    
    return result;
}
