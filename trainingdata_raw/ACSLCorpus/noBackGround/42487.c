#include <stdbool.h>

/*@ requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
 */
bool func(int d, int t, int s)
{
    //@ assert ((d) >= 0);
    //@ assert ((t) >= 0);
    //@ assert ((s) >= 0);
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    return d <= t * s;
}
