#include <stdbool.h>

/*@
    predicate s_in_range(integer s) = 1 <= s <= 100;
    predicate w_in_range(integer w) = 1 <= w <= 100;
    predicate result_condition(integer s, integer w, bool result) = 
        result == (s > w);
*/

/*@
    requires s_in_range(s);
    requires w_in_range(w);
    ensures result_condition(s, w, \result);
*/
bool func(unsigned int s, unsigned int w)
{
    // Variable declarations at scope top
    bool result;

    //@ assert s_in_range(s);
    //@ assert w_in_range(w);
    
    result = s > w;
    
    //@ assert result_condition(s, w, result);
    return result;
}
