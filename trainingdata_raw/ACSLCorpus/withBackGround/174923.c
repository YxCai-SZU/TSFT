#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate x_in_range(integer x) = 1 <= x <= 200;
    predicate condition_holds(integer a, integer b, integer x) = 
        (a <= x) && (a + b >= x);
*/

/*@
    requires a_in_range(a) && b_in_range(b) && x_in_range(x);
    ensures \result == 1 <==> condition_holds(a, b, x);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result = false;
    
    //@ assert a_in_range(a) && b_in_range(b) && x_in_range(x);
    
    if (a <= x)
    {
        if (a + b >= x)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
        result = false;
    }
    
    //@ assert result == 1 <==> condition_holds(a, b, x);
    
    return result;
}
