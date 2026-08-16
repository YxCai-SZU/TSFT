#include <stdbool.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 && (e) >= 0 &&
        (a) <= 123 && (b) <= 123 && (c) <= 123 && (d) <= 123 && (e) <= 123 &&
        (k) >= 0 && (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == ((((b) - (a) <= (k) ? 1 : 0) + ((c) - (a) <= (k) ? 1 : 0) + ((d) - (a) <= (k) ? 1 : 0) + ((e) - (a) <= (k) ? 1 : 0)) >= 1);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    bool good = false;

    //@ assert a < b && b < c && c < d && d < e;

    if (b - a <= k)
    {
        good = true;
    }

    //@ assert good == (b - a <= k);

    if (c - a <= k)
    {
        good = true;
    }

    //@ assert good == ((b - a <= k) || (c - a <= k));

    if (d - a <= k)
    {
        good = true;
    }

    //@ assert good == ((b - a <= k) || (c - a <= k) || (d - a <= k));

    if (e - a <= k)
    {
        good = true;
    }

    //@ assert good == ((((b) - (a) <= (k) ? 1 : 0) + ((c) - (a) <= (k) ? 1 : 0) + ((d) - (a) <= (k) ? 1 : 0) + ((e) - (a) <= (k) ? 1 : 0)) >= 1);

    return good;
}
