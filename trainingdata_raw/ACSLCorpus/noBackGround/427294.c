#include <stdbool.h>

/*@
    requires x <= 1;
    ensures ((x) == 0) ==> \result == 1;
    ensures ((x) == 1) ==> \result == 0;
*/
int func(unsigned int x)
{
    int result;

    if (x == 0)
    {
        result = 1;
    }
    else if (x == 1)
    {
        result = 0;
    }
    else
    {
        //@ assert x <= 1;
        result = -1;
    }

    return result;
}
