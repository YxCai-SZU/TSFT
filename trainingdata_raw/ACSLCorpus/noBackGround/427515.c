#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    int condition;

    condition = a - 2 * b;

    //@ assert (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    //@ assert condition == a - 2 * b;

    if (condition > 0)
    {
        //@ assert condition > 0;
        result = condition;
    }
    else
    {
        //@ assert condition <= 0;
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result == a - 2 * b || result == 0;
    return result;
}
