#include <limits.h>

/*@
    requires ((a) >= -10 && (a) <= 10);
    ensures \result == ((a) >= 0 ? 2 * (a) + 1 : -2 * (a));
    assigns \nothing;
*/
int func(int a)
{
    int b;
    //@ ghost int original_a = a;

    //@ assert ((a) >= -10 && (a) <= 10);

    if (a >= 0)
    {
        //@ assert a >= 0;
        //@ assert a <= 10;
        //@ assert 2 * a + 1 <= 21;
        b = 2 * a + 1;
    }
    else
    {
        //@ assert a < 0;
        //@ assert a >= -10;
        //@ assert -2 * a <= 20;
        b = -2 * a;
    }

    //@ assert b == 2 * original_a + 1 || b == -2 * original_a;
    return b;
}
