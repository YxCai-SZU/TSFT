#include <stdbool.h>

/*@
    requires 0 <= a;
    requires ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
    requires 123 <= k;
    requires e <= 123;
    ensures \result == (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int r;
    bool is_enough;

    // Variable declarations at top
    r = e - a;
    is_enough = false;

    //@ assert r == e - a;

    if (r <= k)
    {
        is_enough = true;
    }

    //@ assert is_enough == (r <= k);
    //@ assert r == e - a;
    //@ assert is_enough == (e - a <= k);

    return is_enough;
}
