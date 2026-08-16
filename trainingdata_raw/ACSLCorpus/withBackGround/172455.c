#include <stdbool.h>

/*@
    predicate s_in_range(integer s) = 1 <= s <= 100;
    predicate w_in_range(integer w) = 1 <= w <= 100;
    predicate result_condition(integer s, integer w, bool result) = 
        result == (s <= w);
*/

/*@
    requires s_in_range(s);
    requires w_in_range(w);
    ensures result_condition(s, w, \result);
*/
bool func(int s, int w)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;
    //@ assert s >= 1;
    //@ assert w >= 1;
    //@ assert s <= 100;
    //@ assert w <= 100;
    
    result = (s <= w);
    
    //@ assert result == (s <= w);
    return result;
}
