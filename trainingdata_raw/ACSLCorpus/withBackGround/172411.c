#include <stdbool.h>

/*@
    predicate in_range(integer val, integer low, integer high) =
        low <= val && val <= high;

    logic integer sum(integer a, integer b) = a + b;
*/

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 0 <= x && x <= 100;
    ensures \result == (x >= a && x <= a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;
    
    //@ assert in_range(a, 0, 100);
    //@ assert in_range(b, 0, 100);
    //@ assert in_range(x, 0, 100);
    
    if (x < a || x > a + b) {
        //@ assert x < a || x > sum(a, b);
        result = false;
    } else {
        //@ assert x >= a && x <= sum(a, b);
        result = true;
    }
    
    //@ assert result == (x >= a && x <= sum(a, b));
    return result;
}
