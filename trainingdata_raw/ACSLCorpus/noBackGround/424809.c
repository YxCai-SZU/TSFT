#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    ensures \result >= -200 && \result <= 200;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int res;

    max1 = a;
    //@ assert max1 == (((a) > (a)) ? (a) : (a));
    if (b > max1)
    {
        max1 = b;
    }
    //@ assert max1 == (((a) > (b)) ? (a) : (b));

    max2 = c;
    //@ assert max2 == (((c) > (c)) ? (c) : (c));
    if (d > max2)
    {
        max2 = d;
    }
    //@ assert max2 == (((c) > (d)) ? (c) : (d));

    res = max1 + max2;
    //@ assert res == (((a) > (b)) ? (a) : (b)) + (((c) > (d)) ? (c) : (d));
    //@ assert res == a + c || res == a + d || res == b + c || res == b + d;
    //@ assert res >= -200 && res <= 200;

    return res;
}
