#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a % 2 != 0 && b % 2 != 0);
*/
bool func(int a, int b)
{
    bool a_is_odd;
    bool b_is_odd;
    bool result;

    a_is_odd = (a % 2 != 0);
    b_is_odd = (b % 2 != 0);

    //@ assert a_is_odd == (a % 2 != 0);
    //@ assert b_is_odd == (b % 2 != 0);

    if (a_is_odd && b_is_odd)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
