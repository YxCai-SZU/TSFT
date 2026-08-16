#include <stdbool.h>

/*@
    requires 2 <= x <= 100;
    requires 2 <= y <= 100;
    ensures \result == x * y - (x + y) + 1;
*/
int func(int x, int y)
{
    int res;

    //@ assert (2 <= (x) <= 100 && 2 <= (y) <= 100);
    //@ assert x * y <= 100 * 100;
    //@ assert x * y >= 2 * 2;
    //@ assert x + y <= 100 + 100;
    //@ assert x + y >= 2 + 2;

    res = x * y - (x + y) + 1;

    //@ assert res == ((x) * (y) - ((x) + (y)) + 1);
    return res;
}
