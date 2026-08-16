#include <limits.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    assigns \nothing;
    ensures \result == ((a) + (b) + (c) + (d) - 3 * (((a)) > ((b)) ? ((a)) : ((b))));
*/
int func(int a, int b, int c, int d)
{
    int res;
    int max_ab;
    int sum;

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
    //@ assert 1 <= max_ab <= 10000;

    sum = a + b + c + d;
    //@ assert 1 <= sum <= 40000;

    res = sum - 3 * max_ab;
    //@ assert res == ((a) + (b) + (c) + (d) - 3 * (((a)) > ((b)) ? ((a)) : ((b))));

    return res;
}
