#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;

    result = a;

    //@ assert result == a;
    //@ assert (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);

    if (result > b * 2)
    {
        //@ assert result > b * 2;
        result = result - b * 2;
        //@ assert result == a - b * 2;
    }
    else
    {
        //@ assert result <= b * 2;
        result = 0;
        //@ assert result == 0;
    }

    //@ assert result >= 0 && result <= a && (result == a - b * 2 || result == 0);
    return result;
}
