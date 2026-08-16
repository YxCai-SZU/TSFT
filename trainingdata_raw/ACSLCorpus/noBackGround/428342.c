#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == (n == 1 || n == 3 || n == 5 || n == 7 || n == 9);
    assigns \nothing;
 */
bool func(int n)
{
    bool result;

    //@ assert 1 <= n <= 100;

    if (n == 1 || n == 3 || n == 5 || n == 7 || n == 9)
    {
        //@ assert n == 1 || n == 3 || n == 5 || n == 7 || n == 9;
        result = true;
    }
    else
    {
        //@ assert n != 1 && n != 3 && n != 5 && n != 7 && n != 9;
        result = false;
    }

    //@ assert result == (n == 1 || n == 3 || n == 5 || n == 7 || n == 9);
    return result;
}
