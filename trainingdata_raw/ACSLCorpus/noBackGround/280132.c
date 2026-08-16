#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= b;
    ensures \result == 0 ==> a > b;
    ensures \result == b ==> a <= b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);

    if (a > b)
    {
        result = 0;
        //@ assert result == 0;
        //@ assert a > b;
    }
    else
    {
        //@ assert a <= b;
        result = b - a + 1;
        //@ assert result == b - a + 1;
    }

    //@ assert result >= 0;
    //@ assert result <= b;
    //@ assert result == 0 ==> a > b;
    //@ assert result == b ==> a <= b;

    return result;
}
