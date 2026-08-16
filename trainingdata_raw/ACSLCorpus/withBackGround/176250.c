#include <limits.h>

/*@
    predicate is_valid_input(integer a, integer b) =
        a != b &&
        a >= 1 && a <= 3 &&
        b >= 1 && b <= 3;

    predicate is_valid_output(integer res, integer a, integer b) =
        res >= 1 && res <= 3 &&
        res != a &&
        res != b;
*/

/*@
    requires is_valid_input(a, b);
    ensures is_valid_output(\result, a, b);
*/
int func(int a, int b)
{
    int res;

    if (a == 1)
    {
        if (b == 2)
        {
            res = 3;
        }
        else
        {
            res = 2;
        }
    }
    else if (a == 2)
    {
        if (b == 1)
        {
            res = 3;
        }
        else
        {
            res = 1;
        }
    }
    else
    {
        if (b == 1)
        {
            res = 2;
        }
        else
        {
            res = 1;
        }
    }

    //@ assert res >= 1 && res <= 3;
    //@ assert res != a;
    //@ assert res != b;

    return res;
}
