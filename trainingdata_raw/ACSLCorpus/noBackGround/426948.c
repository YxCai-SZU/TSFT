#include <stdbool.h>

/*@
    requires 1 <= x <= 9;
    ensures \result == (x == 7 || x == 5 || x == 3);
    assigns \nothing;
 */
bool func(int x)
{
    //@ assert 1 <= x && x <= 9;
    return x == 7 || x == 5 || x == 3;
}
