#include <stdbool.h>

/*@
    requires \true;
    ensures ((\result) >= (a) && (\result) >= (b) && (\result) >= (c));
    assigns \nothing;
*/
int check_maximum_of_three(int a, int b, int c)
{
    int ret;

    if (a > b && a > c)
    {
        //@ assert a >= b && a >= c;
        ret = a;
    }
    else if (b > c)
    {
        //@ assert b >= a && b >= c;
        ret = b;
    }
    else
    {
        //@ assert c >= a && c >= b;
        ret = c;
    }

    return ret;
}
