#include <stdbool.h>

/*@
    requires ((x) >= 1 && (y) >= 1 && (x) <= 100 && (y) <= 100);
    ensures \result == x * 2 || \result == x * 2 - 1 || \result == y * 2 - 1;
    ensures \result >= 0;
*/
int func(int x, int y)
{
    int ans;

    if (x == y)
    {
        ans = x * 2;
    }
    else if (x > y)
    {
        ans = x * 2 - 1;
    }
    else
    {
        ans = y * 2 - 1;
    }

    //@ assert ans == x * 2 || ans == x * 2 - 1 || ans == y * 2 - 1;
    //@ assert ans >= 0;

    return ans;
}
