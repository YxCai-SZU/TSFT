#include <stdbool.h>

/*@ requires (1 <= (d) <= 10000 &&
     1 <= (t) <= 10000 &&
     1 <= (s) <= 10000);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(long d, long t, long s) {
    // Variable declarations at scope top
    bool ans;
    
    //@ assert s <= 10000;
    //@ assert t <= 10000;
    //@ assert s * t <= 10000 * 10000;
    
    if (s * t >= d) {
        ans = true;
    } else {
        ans = false;
    }
    
    return ans;
}
