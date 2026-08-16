#include <limits.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max;
    int sum;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);

    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else
    {
        max = c;
    }

    //@ assert max == a || max == b || max == c;

    sum = max * 2 - (a + b + c);

    if (sum < 0)
    {
        sum = -sum;
    }

    //@ assert sum >= 0;
    //@ assert sum <= a + b + c;

    return sum;
}
