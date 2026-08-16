#include <stdbool.h>

/*@
    predicate x_in_range(integer x) = x > -2147483648 && x < 2147483647;
    predicate y_in_range(integer y) = y > -2147483648 && y < 2147483647;
    predicate z_in_range(integer z) = z > -2147483648 && z < 2147483647;
    
    predicate condition_holds(integer x, integer y, integer z) = x < y && y < z;
*/

/*@
    requires x_in_range(x) && y_in_range(y) && z_in_range(z);
    ensures \result == (x < y && y < z);
    assigns \nothing;
*/
bool func(int x, int y, int z)
{
    bool result;
    
    //@ assert x_in_range(x) && y_in_range(y) && z_in_range(z);
    
    if (x < y && y < z) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
