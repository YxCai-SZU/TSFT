#include <limits.h>

/*@
    requires a != b;
    requires (1 <= (a) <= 3);
    requires (1 <= (b) <= 3);
    ensures (1 <= (\result) <= 3);
    ensures ((\result) != (a));
    ensures ((\result) != (b));
*/
int func(int a, int b)
{
    int result;

    if (a == 1 && b == 2)
    {
        result = 3;
    }
    else if (a == 1 && b == 3)
    {
        result = 2;
    }
    else if (a == 2 && b == 1)
    {
        result = 3;
    }
    else if (a == 2 && b == 3)
    {
        result = 1;
    }
    else if (a == 3 && b == 1)
    {
        result = 2;
    }
    else
    {
        result = 1;
    }

    //@ assert (1 <= (result) <= 3);
    //@ assert ((result) != (a));
    //@ assert ((result) != (b));

    return result;
}
