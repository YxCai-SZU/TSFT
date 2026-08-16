#include <stdbool.h>

/*@
    requires (1 <= (d) && (d) <= 10000 &&
        1 <= (t) && (t) <= 10000 &&
        1 <= (s) && (s) <= 10000);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int x;
    int y;
    int z;
    bool result;

    //@ assert (1 <= (d) && (d) <= 10000 &&         1 <= (t) && (t) <= 10000 &&         1 <= (s) && (s) <= 10000);
    //@ assert ((t) * (s)) <= 100000000;

    x = d;
    y = t;
    z = s;

    //@ assert x == d && y == t && z == s;

    if (x <= y * z)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
