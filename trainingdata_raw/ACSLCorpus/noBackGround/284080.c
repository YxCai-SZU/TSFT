#include <limits.h>

/*@
    requires a >= -100 && a <= 100;
    requires b >= -100 && b <= 100;
    requires c >= -100 && c <= 100;
    requires d >= -100 && d <= 100;
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a || \result >= b || \result >= c || \result >= d;
*/
int func(int a, int b, int c, int d)
{
    int max_val;

    max_val = a;

    if (b > max_val)
    {
        max_val = b;
    }

    //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d));
    //@ assert ((max_val) >= (a) || (max_val) >= (b) || (max_val) >= (c) || (max_val) >= (d));

    if (c > max_val)
    {
        max_val = c;
    }

    //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d));
    //@ assert ((max_val) >= (a) || (max_val) >= (b) || (max_val) >= (c) || (max_val) >= (d));

    if (d > max_val)
    {
        max_val = d;
    }

    //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d));
    //@ assert ((max_val) >= (a) || (max_val) >= (b) || (max_val) >= (c) || (max_val) >= (d));

    return max_val;
}
