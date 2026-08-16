#include <stdbool.h>

/*@
    requires 1 <= d <= 10000;
    requires 1 <= t <= 10000;
    requires 1 <= s <= 10000;
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    //@ assert (1 <= (s) <= 10000 && 1 <= (t) <= 10000 && (s) * (t) <= 10000 * 10000);
    return d <= t * s;
}
