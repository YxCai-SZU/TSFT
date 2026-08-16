#include <stdbool.h>

/*@
    requires (-10000 <= (a) && (a) <= 10000 &&
        -10000 <= (b) && (b) <= 10000 &&
        -10000 <= (c) && (c) <= 10000 &&
        -10000 <= (d) && (d) <= 10000 &&
        (a) <= (b) &&
        (c) <= (d));
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long xs[4];
    long max_val;
    int i;
    int xs_len = 4;

    xs[0] = a * c;
    xs[1] = a * d;
    xs[2] = b * c;
    xs[3] = b * d;

    max_val = xs[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= xs_len;
        loop invariant \exists integer k; 0 <= k < i && max_val == xs[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= xs[j];
        loop invariant xs_len == 4;
        loop invariant (-10000 <= (a) && (a) <= 10000 &&
        -10000 <= (b) && (b) <= 10000 &&
        -10000 <= (c) && (c) <= 10000 &&
        -10000 <= (d) && (d) <= 10000 &&
        (a) <= (b) &&
        (c) <= (d));
        loop invariant \forall integer k; 0 <= k < xs_len ==> -100000000 <= xs[k] && xs[k] <= 100000000;
        loop invariant -100000000 <= max_val && max_val <= 100000000;
        loop assigns i, max_val;
        loop variant xs_len - i;
    */
    while (i < xs_len)
    {
        //@ assert 0 <= i < xs_len;
        if (xs[i] > max_val)
        {
            max_val = xs[i];
        }
        i = i + 1;
    }

    //@ assert \exists integer k; 0 <= k < xs_len && max_val == xs[k];
    //@ assert \forall integer j; 0 <= j < xs_len ==> max_val >= xs[j];
    return max_val;
}
