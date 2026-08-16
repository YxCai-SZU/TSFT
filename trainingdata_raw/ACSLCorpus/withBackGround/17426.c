#include <stdbool.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 100;
    
    logic integer left_val(integer x, integer a) = x - a;
    
    predicate condition_holds(integer x, integer a, integer b) =
        left_val(x, a) >= 0 && left_val(x, a) <= b;
*/

/*@
    requires in_range(a);
    requires in_range(b);
    requires in_range(x);
    ensures \result == (left_val(x, a) >= 0 && left_val(x, a) <= b);
*/
bool func(long a, long b, long x)
{
    long left;
    long right;
    bool result;
    
    left = x - a;
    right = b;
    
    //@ assert left == left_val(x, a);
    
    //@ assert 0 <= left && left <= right ==> (left_val(x, a) >= 0 && left_val(x, a) <= b);
    
    if (0 <= left && left <= right) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (left_val(x, a) >= 0 && left_val(x, a) <= b);
    
    return result;
}
