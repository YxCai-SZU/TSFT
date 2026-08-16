#include <stdbool.h>

/*@
    requires -40 <= x <= 40;
    ensures \result == true ==> x >= 30;
    ensures \result == false ==> x < 30;
*/
bool func(int x)
{
    bool result;
    //@ assert -40 <= x <= 40;
    result = (x >= 30);
    //@ assert result == true ==> x >= 30;
    //@ assert result == false ==> x < 30;
    return result;
}
