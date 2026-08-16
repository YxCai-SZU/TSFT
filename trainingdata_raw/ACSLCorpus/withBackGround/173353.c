#include <stdbool.h>

/*@ predicate valid_range(integer v) = 1 <= v <= 100; */

/*@
  requires valid_range(s);
  requires valid_range(w);
  ensures \result == (s <= w);
*/
bool func(int s, int w)
{
    // Variable declarations at top of scope
    bool res;

    //@ assert valid_range(s);
    //@ assert valid_range(w);
    
    res = (s <= w);
    return res;
}
