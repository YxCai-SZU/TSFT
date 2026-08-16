#include <stdbool.h>

/*@
    requires 0 <= x <= 1;
    ensures \result == 1 - x;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int x)
{
    int ret;

    //@ assert ((x) == 0 || (x) == 1);
    if (x == 0)
    {
        ret = 1;
    }
    else if (x == 1)
    {
        ret = 0;
    }
    else
    {
        //@ assert false;
        ret = 0;
    }

    //@ assert ret == 1 - x;
    return ret;
}
