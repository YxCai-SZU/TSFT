#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    int product;
    bool result;

    //@ assert (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    //@ assert t * s >= 1 && t * s <= 10000 * 10000;
    
    product = t * s;
    result = d <= product;
    
    return result;
}
