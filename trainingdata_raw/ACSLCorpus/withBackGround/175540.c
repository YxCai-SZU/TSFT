#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = 1 <= x && x <= 100;
    
    logic integer diff(integer x, integer y) = x - y;
    
    lemma diff_property:
        \forall integer a, b, c;
            is_in_range(a) && is_in_range(b) && is_in_range(c) ==>
            (diff(b, a) == diff(c, b)) == (b - a == c - b);
*/

/*@
    requires is_in_range(a);
    requires is_in_range(b);
    requires is_in_range(c);
    ensures \result == (b - a == c - b);
*/
bool func(long a, long b, long c)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);
    
    //@ assert diff(b, a) == diff(c, b) ==> (b - a == c - b);
    
    result = (b - a == c - b);
    
    //@ assert result == (b - a == c - b);
    
    return result;
}
