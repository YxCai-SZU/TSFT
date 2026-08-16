#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int max_value;

    result = c - (a - b);
    max_value = result;

    //@ assert result == ((c) - ((a) - (b)));

    if (max_value < 0)
    {
        max_value = 0;
        //@ assert max_value == 0;
    }
    else
    {
        //@ assert max_value == result;
    }

    //@ assert max_value >= 0;
    //@ assert max_value <= c;

    return max_value;
}
