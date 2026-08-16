#include <stdbool.h>

/*@ requires (1 <= (d) && (d) <= 10000 &&
      1 <= (t) && (t) <= 10000 &&
      1 <= (s) && (s) <= 10000);
    ensures \result == (d <= ((t) * (s)));
    assigns \nothing;
*/
bool func(int d, int t, int s) {
    // Variable declarations at scope top
    bool ans;
    
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert ((t) * (s)) <= 10000 * 10000;
    
    ans = (d <= t * s);
    return ans;
}
