#include <stdbool.h>

/*@
    requires 1 <= A <= 3;
    requires 1 <= B <= 3;
    ensures \result == (A * B % 2 != 0);
*/
bool func(unsigned int A, unsigned int B)
{
    bool result;

    //@ assert A * B <= 9;

    if (A == 2 || B == 2 || A == 4 || B == 4)
    {
        result = false;
    }
    else if (A == 1 || B == 1 || A == 3 || B == 3)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
