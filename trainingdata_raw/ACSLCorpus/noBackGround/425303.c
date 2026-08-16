#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures (a - b >= c) ==> (\result == 0);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int x;
    int res;

    x = a - b;

    //@ assert x == a - b;

    if (c - x < 0)
    {
        //@ assert c - x < 0;
        res = 0;
    }
    else
    {
        //@ assert c - x >= 0;
        res = c - x;
    }

    //@ assert res >= 0;
    //@ assert res <= c;
    //@ assert (a - b >= c) ==> (res == 0);

    return res;
}
