#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (a) != (c)) ||
        ((a) == (c) && (a) != (b)) ||
        ((b) == (c) && (a) != (b)));
 */
bool func(int a, int b, int c)
{
    bool ans = false;

    //@ assert a >= 1 && a <= 9;
    //@ assert b >= 1 && b <= 9;
    //@ assert c >= 1 && c <= 9;

    if (a == b)
    {
        ans = true;
    }

    if (a == c)
    {
        ans = true;
    }

    if (b == c)
    {
        ans = true;
    }

    if ((a == b) && (b == c))
    {
        ans = false;
    }

    //@ assert ans == true <==> (((a) == (b) && (a) != (c)) ||         ((a) == (c) && (a) != (b)) ||         ((b) == (c) && (a) != (b)));
    return ans;
}
