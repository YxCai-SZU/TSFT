#include <stdbool.h>

/*@
    requires a > -2147483648 && a < 2147483647;
    requires b > -2147483648 && b < 2147483647;
    requires c > -2147483648 && c < 2147483647;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result;

    if (a < b && b < c)
    {
        result = true;
    }
    else
    {
        //@ assert !(a < b && b < c);
        result = false;
    }

    return result;
}
