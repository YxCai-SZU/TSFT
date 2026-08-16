#include <stdbool.h>

/*@
    requires (-40 <= (x) <= 40);
    ensures (x < 30 ==> \result == 0) && (x >= 30 ==> \result == x - 30);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int x)
{
    int res;

    //@ assert (-40 <= (x) <= 40);

    if (x < 30)
    {
        res = 0;
    }
    else
    {
        res = x - 30;
    }

    //@ assert res == ((x) < 30 ? 0 : (x) - 30);
    //@ assert res >= 0;

    return res;
}
