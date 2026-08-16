#include <stdint.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures ((\result) == -1 || (\result) == 0 || (\result) == 1 || (\result) == 2 || (\result) == 3);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t x;
    int64_t y;
    int64_t z;
    int64_t num;
    int64_t i;

    x = a;
    y = b;
    z = c;
    num = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant ((num) == -1 || (num) == 0 || (num) == 1 || (num) == 2 || (num) == 3);
        loop invariant (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
        loop assigns i, num;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        //@ assert -10000 <= x - i * i <= 10000;
        //@ assert -10000 <= y - i * i * i <= 10000;
        //@ assert -10000 <= z - i * i * i * i <= 10000;

        if ((x - i * i) == 0 && (y - i * i * i) == 0 && (z - i * i * i * i) == 0)
        {
            num = i;
            break;
        }
        i += 1;
    }

    if (num == 0)
    {
        num = -1;
    }

    return num;
}
