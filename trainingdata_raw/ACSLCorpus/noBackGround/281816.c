#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int max_value;
    int result;

    max_value = (a > b) ? a : b;

    if (max_value == a)
    {
        if (b == 3)
        {
            result = a + b;
        }
        else
        {
            result = 2 * a - 1;
        }
    }
    else
    {
        if (a == 3)
        {
            result = a + b;
        }
        else
        {
            result = 2 * b - 1;
        }
    }

    //@ assert result == a + b || result == 2 * a - 1 || result == 2 * b - 1;
    //@ assert result >= 0;

    return result;
}
