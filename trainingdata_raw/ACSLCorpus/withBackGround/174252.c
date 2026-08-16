#include <stdbool.h>

/*@ predicate is_negative(integer number) = number < 0; */

/*@
  requires 1 <= d <= 10000;
  requires 1 <= t <= 10000;
  requires 1 <= s <= 10000;
  requires d <= t * s;
  ensures \result == true;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    
    if (d <= t * s) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
