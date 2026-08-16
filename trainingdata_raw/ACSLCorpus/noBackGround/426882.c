#include <limits.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((a) > (b) ? (a) : (b)) + ((c) > (d) ? (c) : (d));
    ensures \result >= a + c;
    ensures \result >= a + d;
    ensures \result >= b + c;
    ensures \result >= b + d;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int result;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    if (a > b)
    {
        max_ab = a;
    }
    else
    {
        max_ab = b;
    }

    //@ assert max_ab == ((a) > (b) ? (a) : (b));
    //@ assert max_ab >= a && max_ab >= b;

    if (c > d)
    {
        max_cd = c;
    }
    else
    {
        max_cd = d;
    }

    //@ assert max_cd == ((c) > (d) ? (c) : (d));
    //@ assert max_cd >= c && max_cd >= d;

    result = max_ab + max_cd;

    //@ assert result == ((a) > (b) ? (a) : (b)) + ((c) > (d) ? (c) : (d));
    //@ assert result >= a + c;
    //@ assert result >= a + d;
    //@ assert result >= b + c;
    //@ assert result >= b + d;

    return result;
}
