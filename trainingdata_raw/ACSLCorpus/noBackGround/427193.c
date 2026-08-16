#include <stdbool.h>

/*@
    requires 0 <= a < b < c < d < e <= 123;
    requires 0 <= k <= 123;
    ensures \result == true <==> (((e) - (a) <= (k)) || ((k) == 0));
 */
bool func(unsigned long long a, unsigned long long b, unsigned long long c,
          unsigned long long d, unsigned long long e, unsigned long long k)
{
    // Variable declarations at the top
    bool res;

    if (e - a <= k || k == 0) {
        //@ assert (((e) - (a) <= (k)) || ((k) == 0));
        res = true;
    } else {
        //@ assert !(((e) - (a) <= (k)) || ((k) == 0));
        res = false;
    }

    return res;
}
