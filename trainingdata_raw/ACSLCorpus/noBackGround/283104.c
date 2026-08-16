#include <stdint.h>

/*@
    requires 1 <= a <= 10;
    ensures (a <= 3 ==> \result == 400);
    ensures (4 <= a && a <= 6 ==> \result == 200);
    ensures (7 <= a && a <= 9 ==> \result == 100);
    ensures (a == 10 ==> \result == 0);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    int32_t x;

    if (a <= 3)
    {
        x = 400;
        //@ assert ((a) <= 3 ==> (x) == 400);
    }
    else if (a <= 6)
    {
        x = 200;
        //@ assert (4 <= (a) && (a) <= 6 ==> (x) == 200);
    }
    else if (a <= 9)
    {
        x = 100;
        //@ assert (7 <= (a) && (a) <= 9 ==> (x) == 100);
    }
    else
    {
        x = 0;
        //@ assert ((a) == 10 ==> (x) == 0);
    }

    //@ assert ((a) <= 3 ==> (x) == 400) && (4 <= (a) && (a) <= 6 ==> (x) == 200) && (7 <= (a) && (a) <= 9 ==> (x) == 100) && ((a) == 10 ==> (x) == 0);
    return x;
}
