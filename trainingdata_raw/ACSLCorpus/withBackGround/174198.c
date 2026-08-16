#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;
*/

/*@
    lemma multiplication_bounds: \forall integer s, integer t;
        valid_range(s) && valid_range(t) ==> 
        1 <= s * t <= 10000 * 10000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (d <= s * t);
*/
bool func(int d, int t, int s)
{
    int result;
    
    //@ assert valid_range(d);
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    
    //@ assert 1 <= s * t <= 10000 * 10000;
    
    result = (d <= s * t);
    
    //@ assert result == (d <= s * t);
    return result;
}
