#include <limits.h>

/*@
    requires 2 <= x <= 100;
    requires 2 <= y <= 100;
    ensures \result == x * y - (x + y) + 1;
    assigns \nothing;
*/
int func(int x, int y)
{
    // Variable declarations at scope top
    int result;

    //@ assert 2 <= x && x <= 100;
    //@ assert 2 <= y && y <= 100;
    //@ assert 4 <= x + y && x + y <= 200;
    //@ assert 4 <= x * y && x * y <= 10000;
    //@ assert -196 <= x * y - (x + y) && x * y - (x + y) <= 9800;
    //@ assert -195 <= x * y - (x + y) + 1 && x * y - (x + y) + 1 <= 9801;

    result = x * y - (x + y) + 1;
    return result;
}
