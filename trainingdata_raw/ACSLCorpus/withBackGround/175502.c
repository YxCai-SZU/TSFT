#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires valid_range(s);
    requires valid_range(w);
    ensures \result == (s <= w);
*/
bool func(long s, long w) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;
    
    result = (s <= w);
    return result;
}
