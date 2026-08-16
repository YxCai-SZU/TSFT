#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
    ensures \result >= a * c;
    ensures \result >= a * d;
    ensures \result >= b * c;
    ensures \result >= b * d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_val;
    int ac;
    int ad;
    int bc;
    int bd;

    //@ assert -100 * 100 <= a * c <= 100 * 100;
    //@ assert -100 * 100 <= a * d <= 100 * 100;
    //@ assert -100 * 100 <= b * c <= 100 * 100;
    //@ assert -100 * 100 <= b * d <= 100 * 100;

    ac = a * c;
    ad = a * d;
    bc = b * c;
    bd = b * d;

    max_val = ac;

    if (ad > max_val)
    {
        max_val = ad;
    }

    if (bc > max_val)
    {
        max_val = bc;
    }

    if (bd > max_val)
    {
        max_val = bd;
    }

    //@ assert max_val >= ac;
    //@ assert max_val >= ad;
    //@ assert max_val >= bc;
    //@ assert max_val >= bd;

    return max_val;
}
