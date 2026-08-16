#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= ((a) - (b) + (c));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    result = c - a + b;

    if (result > 0)
    {
        //@ assert result <= ((a) - (b) + (c));
        return result;
    }
    else
    {
        return 0;
    }
}
