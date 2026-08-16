#include <limits.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures ((\result) == (a) || (\result) == (b) || (\result) == (c) || (\result) == (d) ||
        (\result) == (a) + (b) || (\result) == (a) + (c) || (\result) == (a) + (d) ||
        (\result) == (b) + (c) || (\result) == (b) + (d) || (\result) == (c) + (d) ||
        (\result) == (a) + (b) + (c) || (\result) == (a) + (b) + (d) || (\result) == (a) + (c) + (d) || (\result) == (b) + (c) + (d) ||
        (\result) == (a) + (b) + (c) + (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_val = a;

    //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));

    if (b > max_val)
    {
        max_val = b;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (c > max_val)
    {
        max_val = c;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (d > max_val)
    {
        max_val = d;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (a + b > max_val)
    {
        max_val = a + b;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (a + c > max_val)
    {
        max_val = a + c;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (a + d > max_val)
    {
        max_val = a + d;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (b + c > max_val)
    {
        max_val = b + c;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (b + d > max_val)
    {
        max_val = b + d;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (c + d > max_val)
    {
        max_val = c + d;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (a + b + c > max_val)
    {
        max_val = a + b + c;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (a + b + d > max_val)
    {
        max_val = a + b + d;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (a + c + d > max_val)
    {
        max_val = a + c + d;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (b + c + d > max_val)
    {
        max_val = b + c + d;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    if (a + b + c + d > max_val)
    {
        max_val = a + b + c + d;
        //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    }

    //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c) || (max_val) == (d) ||         (max_val) == (a) + (b) || (max_val) == (a) + (c) || (max_val) == (a) + (d) ||         (max_val) == (b) + (c) || (max_val) == (b) + (d) || (max_val) == (c) + (d) ||         (max_val) == (a) + (b) + (c) || (max_val) == (a) + (b) + (d) || (max_val) == (a) + (c) + (d) || (max_val) == (b) + (c) + (d) ||         (max_val) == (a) + (b) + (c) + (d));
    return max_val;
}
