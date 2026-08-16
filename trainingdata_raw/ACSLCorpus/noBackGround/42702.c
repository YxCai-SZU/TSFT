#include <stdbool.h>

/*@
    requires (1 <= (d) && (d) <= 10000) && (1 <= (t) && (t) <= 10000) && (1 <= (s) && (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    //@ assert t > 0 && s > 0;
    //@ assert t * s <= 10000 * 10000;
    return d <= t * s;
}
