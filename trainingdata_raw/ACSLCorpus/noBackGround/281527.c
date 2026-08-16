#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    int d1;
    int t1;
    int s1;
    bool result;

    //@ assert (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    //@ assert 1 <= t * s <= 10000 * 10000;

    d1 = d;
    t1 = t;
    s1 = s;

    result = (d1 <= t1 * s1);
    return result;
}
