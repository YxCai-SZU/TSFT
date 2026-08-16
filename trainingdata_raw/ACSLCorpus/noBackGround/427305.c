#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result = 0;
    int b2 = 0;
    int a2 = 0;
    int temp = 0;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);

    if (c > a + b + 1)
    {
        result = c - (a + b + 1);
    }

    if (b > a + 1)
    {
        b2 = b - (a + 1);
    }

    if (a > b + 1)
    {
        a2 = a - (b + 1);
    }

    if (a2 + b2 + 1 <= c)
    {
        temp = a2 + b2 + 1;
    }
    else
    {
        temp = c;
    }

    result = result + temp;

    //@ assert result >= 0;
    //@ assert result <= a + b + c;

    return result;
}
