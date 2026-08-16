#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) &&
             (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int s1;
    int s2;
    int res;

    //@ assert ((a) * (b)) <= INT_MAX && ((a) * (b)) >= 1;
    //@ assert ((c) * (d)) <= INT_MAX && ((c) * (d)) >= 1;

    s1 = a * b;
    s2 = c * d;

    //@ assert s1 >= 1 || s2 >= 1;

    if (s1 >= s2)
    {
        res = s1;
    }
    else
    {
        res = s2;
    }

    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    //@ assert res >= 1;

    return res;
}
