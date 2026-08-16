#include <stdbool.h>

/*@
    requires 0 <= x <= 1;
    ensures (x == 1 ==> \result == 0);
    ensures (x == 0 ==> \result == 1);
    assigns \nothing;
*/
unsigned int func(unsigned int x)
{
    unsigned int result;

    if (x == 1)
    {
        //@ assert ((x) == 1);
        result = 0;
    }
    else
    {
        //@ assert ((x) == 0);
        result = 1;
    }

    return result;
}
