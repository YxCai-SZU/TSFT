#include <stdbool.h>

/*@
    requires a < 124 && b < 124 && c < 124 && d < 124 && e < 124 && k < 124;
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (k >= (e - a) || k >= 0);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    // Variable declarations at top of scope
    bool result;

    if (k >= (e - a) || k >= 0)
    {
        result = true;
    }
    else
    {
        //@ assert k < (e - a) && k < 0;
        result = false;
    }

    return result;
}
