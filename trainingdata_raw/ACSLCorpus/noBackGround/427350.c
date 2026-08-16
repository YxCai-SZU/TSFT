#include <stdbool.h>
/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures ((\result) <= (a) && (\result) <= (b) && (\result) >= 1 && (((a)) % ((\result)) == 0) && (((b)) % ((\result)) == 0));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int d;
    unsigned int res;
    unsigned int min_val;

    d = 2;
    res = 1;
    min_val = (a < b) ? a : b;

    /*@
        loop invariant ((1 <= ((a)) <= 100) && (1 <= ((b)) <= 100) &&
        2 <= (d) <= (min_val) + 1 &&
        (((res)) <= ((a)) && ((res)) <= ((b)) && ((res)) >= 1 && ((((a))) % (((res))) == 0) && ((((b))) % (((res))) == 0)));
        loop assigns d, res;
        loop variant min_val + 1 - d;
    */
    while (d < min_val + 1)
    {
        if (a % d == 0 && b % d == 0)
        {
            res = d;
        }
        d += 1;
    }

    //@ assert ((res) <= (a) && (res) <= (b) && (res) >= 1 && (((a)) % ((res)) == 0) && (((b)) % ((res)) == 0));
    return res;
}
