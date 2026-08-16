#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    bool result;

    // Precondition implies non-negative
    //@ assert d >= 0;
    //@ assert t >= 0;
    //@ assert s >= 0;
    
    // Bounds from preconditions
    //@ assert d <= 10000;
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    
    // Multiplication safety
    //@ assert t * s <= 10000 * 10000;

    if (t == 0) {
        if (d <= 0) {
            result = true;
        } else {
            result = false;
        }
    } else if (s == 0) {
        if (d <= 0) {
            result = true;
        } else {
            result = false;
        }
    } else if (d <= 0) {
        result = true;
    } else if (d > t * s) {
        result = false;
    } else {
        result = true;
    }

    // Postcondition check
    //@ assert result == (d <= t * s);
    return result;
}
