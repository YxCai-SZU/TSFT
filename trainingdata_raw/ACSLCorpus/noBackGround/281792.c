#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= s * t);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    //@ assert (1 <= (d) <= 10000);
    //@ assert (1 <= (t) <= 10000);
    //@ assert (1 <= (s) <= 10000);
    //@ assert s * t <= 10000 * 10000;
    
    return d <= s * t;
}
