#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \exists integer res;
            res == a || res == b || res == c || res == d ||
            res == a + b || res == a + c || res == a + d ||
            res == b + c || res == b + d || res == c + d ||
            res == a + b + c || res == a + b + d ||
            res == a + c + d || res == b + c + d ||
            res == a + b + c + d;
    ensures \result == a || \result == b || \result == c || \result == d ||
            \result == a + b || \result == a + c || \result == a + d ||
            \result == b + c || \result == b + d || \result == c + d ||
            \result == a + b + c || \result == a + b + d ||
            \result == a + c + d || \result == b + c + d ||
            \result == a + b + c + d;
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int max;

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);
    //@ assert (-100 <= (d) <= 100);

    if (a > b)
        max1 = a;
    else
        max1 = b;

    //@ assert max1 == ((a) > (b) ? (a) : (b));

    if (c > d)
        max2 = c;
    else
        max2 = d;

    //@ assert max2 == ((c) > (d) ? (c) : (d));

    if (max1 > max2)
        max = max1;
    else
        max = max2;

    //@ assert max == ((max1) > (max2) ? (max1) : (max2));
    //@ assert max >= -100;

    return max;
}
