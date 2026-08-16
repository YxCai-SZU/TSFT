#include <stdbool.h>

/*@
    requires 0 <= x <= 100;
    requires 0 <= y <= 100;
    ensures \result == (x * y <= 100);
    assigns \nothing;
*/
bool func(int x, int y)
{
    //@ assert (0 <= (x) <= 100 && 0 <= (y) <= 100);
    //@ assert 0 <= x * y <= 10000;
    return x * y <= 100;
}
