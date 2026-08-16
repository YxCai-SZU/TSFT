#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (((a) * (b)) % 2 != 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert 1 <= ((a) * (b)) && ((a) * (b)) <= 9;

    if (a == 2 || b == 2 || a == 4 || b == 4)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    //@ assert result == (((a) * (b)) % 2 != 0);
    return result;
}
