#include <stdbool.h>

/*@
    requires x > 0;
    requires y > 0;
    requires x * y <= 100;
    ensures \result == x * y + 1;
    ensures \result > 0;
*/
int func(int x, int y)
{
    int result;

    //@ assert x > 0 && y > 0;
    //@ assert x * y <= 100;
    //@ assert x * y + 1 > 0;

    result = x * y + 1;
    return result;
}
