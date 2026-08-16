#include <limits.h>

/*@
    requires (1 <= (x) <= 20) && (1 <= (y) <= 20);
    ensures (x < 10 && y < 10 ==> \result == x * y) &&
            (x >= 10 || y >= 10 ==> \result == -1);
    ensures INT_MIN <= \result <= INT_MAX;
*/
int func(int x, int y)
{
    // Variable declarations at scope top
    int result;

    if (x < 10 && y < 10)
    {
        //@ assert (1 <= (x) <= 9) && (1 <= (y) <= 9);
        //@ assert x * y >= 1;
        //@ assert x * y <= 81;
        result = x * y;
    }
    else
    {
        result = -1;
    }

    return result;
}
