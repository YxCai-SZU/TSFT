#include <stdbool.h>

/*@ predicate valid_range(integer x) = 1 <= x <= 10000; */

/*@
  requires valid_range(d) && valid_range(t) && valid_range(s);
  ensures \result == (d <= t * s);
  assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    int product;
    bool result;

    //@ assert valid_range(d);
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    
    //@ assert (long long)t * (long long)s <= (long long)10000 * (long long)10000;
    //@ assert t * s <= 10000 * 10000;

    product = t * s;
    result = d <= product;
    
    return result;
}
