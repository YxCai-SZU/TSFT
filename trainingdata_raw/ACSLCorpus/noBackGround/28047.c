#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    bool result;
    int product;

    //@ assert t < 10001;
    //@ assert s < 10001;
    //@ assert d < 10001;

    //@ assert (long long)t * (long long)s <= (long long)10000 * (long long)10000;

    product = t * s;
    result = d <= product;

    return result;
}
