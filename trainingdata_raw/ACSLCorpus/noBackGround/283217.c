#include <stdbool.h>

/*@
    requires -40 <= t <= 40;
    ensures \result == true <==> t >= 30;
    assigns \nothing;
*/
bool func(int t)
{
    bool result;
    //@ assert t >= 30 <==> t >= 30;
    result = (t >= 30);
    return result;
}
