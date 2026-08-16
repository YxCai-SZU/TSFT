#include <stdbool.h>

/*@
    requires (1 <= (d) && (d) <= 10000 &&
        1 <= (t) && (t) <= 10000 &&
        1 <= (s) && (s) <= 10000);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s) {
    // Variable declarations at top of scope
    bool result;
    int product;
    
    //@ assert 1 <= t && t <= 10000;
    //@ assert 1 <= s && s <= 10000;
    //@ assert 1 <= t * s && t * s <= 100000000;
    
    product = t * s;
    result = (product >= d);
    
    return result;
}
