#include <stdbool.h>

/*@
  requires (1 <= (d) <= 10000 &&
      1 <= (t) <= 10000 &&
      1 <= (s) <= 10000);
  ensures \result == (s * t >= d);
  assigns \nothing;
*/
bool func(long d, long t, long s)
{
    long ds = d;
    long ts = t;
    long ss = s;
    
    //@ assert (1 <= (ds) <= 10000 &&       1 <= (ts) <= 10000 &&       1 <= (ss) <= 10000);
    //@ assert ss <= 10000;
    //@ assert ts <= 10000;
    //@ assert ss * ts <= 10000 * 10000;
    
    long bus_journey = ss * ts;
    
    //@ assert bus_journey == ss * ts;
    return bus_journey >= ds;
}
