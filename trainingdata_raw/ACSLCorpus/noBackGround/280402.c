#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (((a) < (c) && (c) < (b)) || ((b) < (c) && (c) < (a)));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool result;

    // Variable declarations at top
    result = false;

    if (a < c && c < b)
    {
        result = true;
    }
    else if (b < c && c < a)
    {
        result = true;
    }
    else
    {
        //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
        result = false;
    }

    return result;
}
