#include <stdbool.h>

/*@
    requires ((((a)) > 0) && (((b)) > 0) && (((c)) > 0) && (((a)) <= ((b))) && (((b)) <= ((c))));
    ensures \result == (c - a <= b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    int d;
    int e;
    bool result;

    //@ assert ((a) > 0);
    //@ assert ((b) > 0);
    //@ assert ((c) > 0);
    //@ assert ((a) <= (b));
    //@ assert ((b) <= (c));

    d = c - a;
    e = b;

    if (d <= e)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
