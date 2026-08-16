#include <stdbool.h>

/*@
  requires (1 <= (d) && (d) <= 10000 &&
      1 <= (t) && (t) <= 10000 &&
      1 <= (s) && (s) <= 10000 &&
      (d) >= 0 && (t) >= 0 && (s) >= 0);
  ensures \result == (t * s >= d);
  assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at top of scope
    long speed;
    bool result;
    
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    
    //@ assert t * s <= 10000 * 10000;
    
    speed = t * s;
    result = (d <= speed);
    
    return result;
}
