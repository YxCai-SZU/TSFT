#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x && x <= 100;
    
    logic integer sum(integer x, integer y) = x + y;
    
    predicate condition_holds(integer a, integer b, integer c) =
        a == sum(b, c) || sum(a, b) == c || sum(a, c) == b;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == true <==> condition_holds(a, b, c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert sum(b, c) <= 200;
    //@ assert sum(a, b) <= 200;
    //@ assert sum(a, c) <= 200;
    
    if (a == b + c || a + b == c || a + c == b) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
