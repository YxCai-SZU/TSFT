#include <stdbool.h>

/*@ requires (1 <= (d) && (d) <= 10000 &&
      1 <= (t) && (t) <= 10000 &&
      1 <= (s) && (s) <= 10000);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(long d, long t, long s) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert t >= 1;
    //@ assert s >= 1;
    //@ assert t * s <= 100000000;
    
    result = (t * s >= d);
    return result;
}
