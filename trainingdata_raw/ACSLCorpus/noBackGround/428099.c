#include <stdbool.h>

/*@
    requires a >= -2147483648 && a <= 2147483647;
    requires b >= -2147483648 && b <= 2147483647;
    requires c >= -2147483648 && c <= 2147483647;
    ensures \result == true <==> ((a) < (b) && (b) < (c));
*/
bool func(int a, int b, int c)
{
    bool sc;
    sc = true;

    if (a >= b)
    {
        sc = false;
    }

    if (b >= c)
    {
        sc = false;
    }

    //@ assert sc == true <==> ((a) < (b) && (b) < (c));

    return sc;
}
