#include <stdbool.h>

/*@
    requires 1 <= X <= 100;
    ensures \result == (X >= 30);
*/
bool func(int X)
{
    bool result;
    //@ assert X >= 30 ==> X >= 30;
    result = (X >= 30);
    return result;
}
