#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    ensures \result <= 2 * (a + b + c - 1);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    if (a < b)
    {
        if (b < c)
        {
            result = a + b;
        }
        else
        {
            result = a + c;
        }
    }
    else
    {
        if (a < c)
        {
            result = a + b;
        }
        else
        {
            result = b + c;
        }
    }

    //@ assert result <= 2 * (a + b + c - 1);
    return result;
}
