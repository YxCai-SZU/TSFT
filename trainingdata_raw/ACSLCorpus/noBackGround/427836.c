#include <stdbool.h>

/*@
    requires (0 <= (x) <= 9 && 0 <= (a) <= 9);
    ensures (((\result) == 0 || (\result) == 10) &&
        ((\result) == 10 ==> (x) < (a)));
*/
int func(int x, int a)
{
    int result;

    if (x < a)
    {
        result = 10;
        //@ assert result == 10 && x < a;
    }
    else
    {
        //@ assert x >= a;
        result = 0;
        //@ assert result == 0;
    }

    //@ assert (((result) == 0 || (result) == 10) &&         ((result) == 10 ==> (x) < (a)));
    return result;
}
