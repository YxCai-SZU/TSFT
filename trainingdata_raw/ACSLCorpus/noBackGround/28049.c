#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures ((\result) == true <==> (d) <= (t) * (s));
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    bool result;
    int product;

    // Preconditions prevent overflow
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    product = t * s;
    if (d <= product) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == true <==> d <= t * s;
    return result;
}
