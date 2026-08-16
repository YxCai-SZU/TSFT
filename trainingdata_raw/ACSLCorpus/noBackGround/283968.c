#include <limits.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures (\result == 1 && a < b && b < c) ||
            (\result == 0 && !(a < b && b < c));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int res;

    if (a < b)
    {
        if (b < c)
        {
            res = 1;
        }
        else
        {
            res = 0;
        }
    }
    else
    {
        res = 0;
    }

    //@ assert (a < b && b < c) ==> (res == 1);
    //@ assert !(a < b && b < c) ==> (res == 0);

    return res;
}
