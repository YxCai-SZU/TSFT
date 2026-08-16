#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result <= a;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> a % b == 0;
    ensures \result == 1 ==> a % b != 0;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int res;

    if (a % b == 0)
    {
        //@ assert a % b == 0;
        res = 0;
    }
    else
    {
        //@ assert a % b != 0;
        res = 1;
    }

    return res;
}
