#include <stdint.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == ((c) - ((a) - (b))) || \result == 0;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    int32_t res;
    int32_t ret;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    //@ assert -19 <= ((c) - ((a) - (b))) && ((c) - ((a) - (b))) <= 20;

    res = c - (a - b);

    //@ assert ((c) - ((a) - (b))) == res;

    if (res < 0)
    {
        ret = 0;
        //@ assert ret == 0;
    }
    else
    {
        ret = res;
        //@ assert ret == res;
    }

    //@ assert ret >= 0;
    //@ assert ret <= c;
    //@ assert ret == ((c) - ((a) - (b))) || ret == 0;

    return ret;
}
