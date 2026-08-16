#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= t * s <= 10000 * 10000;

    if (d <= t * s) {
        result = true;
    } else {
        //@ assert d > t * s;
        result = false;
    }

    return result;
}
