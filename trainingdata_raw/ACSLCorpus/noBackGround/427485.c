#include <limits.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a && \result >= b && \result >= c && \result >= d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_value = a;

    if (b > max_value)
    {
        max_value = b;
    }

    if (c > max_value)
    {
        max_value = c;
    }

    if (d > max_value)
    {
        max_value = d;
    }

    //@ assert ((max_value) == (a) || (max_value) == (b) || (max_value) == (c) || (max_value) == (d));
    //@ assert ((max_value) >= (a) && (max_value) >= (b) && (max_value) >= (c) && (max_value) >= (d));

    return max_value;
}
