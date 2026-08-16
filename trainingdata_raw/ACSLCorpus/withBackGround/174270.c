#include <stdbool.h>

/*@ predicate s_in_range(integer s) = 1 <= s <= 100; */
/*@ predicate w_in_range(integer w) = 1 <= w <= 100; */

/*@
    requires s_in_range(s) && w_in_range(w);
    ensures \result == (s <= w);
    assigns \nothing;
*/
bool func(int s, int w)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert s_in_range(s);
    //@ assert w_in_range(w);
    
    //@ assert s <= w || s > w;
    
    result = (s <= w);
    return result;
}
