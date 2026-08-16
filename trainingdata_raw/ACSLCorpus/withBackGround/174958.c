#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 100;
    
    logic integer min(integer a, integer b) = a < b ? a : b;
    logic integer max(integer a, integer b) = a > b ? a : b;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    
    result = (c >= a && c <= b);
    
    return result;
}
