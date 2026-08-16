#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    ensures \result == (x >= 5);
    assigns \nothing;
*/
bool func(int x)
{
    bool result;
    //@ assert x >= 5 ==> x >= 5;
    result = (x >= 5);
    return result;
}
