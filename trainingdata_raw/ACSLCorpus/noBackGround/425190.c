#include <stdbool.h>

/*@
    requires 0 < a && a < 10;
    requires 0 < b && b < 10;
    requires 0 < c && c < 10;
    ensures \result == true <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 0 < a && a < 10;
    //@ assert 0 < b && b < 10;
    //@ assert 0 < c && c < 10;

    if ((a < b && b < c) || (a > b && b > c))
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
    return result;
}
