#include <stdbool.h>

/*@
    requires -40 <= x <= 40;
    ensures \result == true ==> ((x) >= 30);
    ensures \result == false ==> ((x) < 30);
*/
bool func(int x)
{
    bool result;
    //@ ghost int proof_temp = x;

    //@ assert -40 <= x <= 40;

    //@ assert x >= 30 ==> ((x) >= 30);
    //@ assert x < 30 ==> ((x) < 30);

    result = (x >= 30);

    //@ assert result == true ==> ((x) >= 30);
    //@ assert result == false ==> ((x) < 30);

    return result;
}
