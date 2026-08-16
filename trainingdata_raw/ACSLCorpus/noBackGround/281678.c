#include <stdint.h>

/*@
    requires ((x) != (y) &&
        (x) >= -1000000000 && (x) <= 1000000000 &&
        (y) >= -1000000000 && (y) <= 1000000000);
    ensures ((\result) >= 0 &&
        (\result) <= 1000000000 &&
        ((\result) == 0 ==> (x) == (y)) &&
        ((\result) == 1 ==> (x) < (y)) &&
        ((\result) == 2 ==> (x) > (y)));
*/
int64_t func(int64_t x, int64_t y)
{
    int64_t res;

    //@ assert ((x) != (y) &&         (x) >= -1000000000 && (x) <= 1000000000 &&         (y) >= -1000000000 && (y) <= 1000000000);

    if (x < y)
    {
        //@ assert x < y;
        res = 1;
    }
    else if (x > y)
    {
        //@ assert x > y;
        res = 2;
    }
    else
    {
        //@ assert x == y;
        res = 0;
    }

    //@ assert ((res) >= 0 &&         (res) <= 1000000000 &&         ((res) == 0 ==> (x) == (y)) &&         ((res) == 1 ==> (x) < (y)) &&         ((res) == 2 ==> (x) > (y)));
    return res;
}
