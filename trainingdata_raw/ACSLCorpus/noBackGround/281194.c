#include <stdbool.h>

/*@
    requires a <= 100 && b <= 100 && c <= 100;
    requires a >= -100 && b >= -100 && c >= -100;
    ensures \result == true <==> ((a) < (b) && (b) < (c));
 */
bool func(int a, int b, int c)
{
    bool less;

    less = false;

    if (a < b)
    {
        less = true;
    }

    if (less && c > b)
    {
        less = true;
    }
    else
    {
        less = false;
    }

    //@ assert less == true <==> ((a) < (b) && (b) < (c));

    return less;
}
