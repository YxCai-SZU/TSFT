#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (x) <= 100);
    ensures \result == (x >= 0 && a <= x && x <= a + b);
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    long max_val;
    long min_val;

    //@ assert (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (x) <= 100);
    
    // Calculate max_val
    if (0 > a) {
        max_val = 0;
    } else {
        max_val = a;
    }
    //@ assert max_val == ((0 > (a)) ? 0 : (a));
    
    // Calculate min_val
    if (a + b < 100) {
        min_val = a + b;
    } else {
        min_val = 100;
    }
    //@ assert min_val == (((a) + (b) < 100) ? (a) + (b) : 100);
    
    if (x >= max_val && x <= min_val) {
        //@ assert x >= max_val && x <= min_val;
        return true;
    } else {
        //@ assert !(x >= max_val && x <= min_val);
        return false;
    }
}
