#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
long func(long n, long a, long b)
{
    long min_value;
    long product;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;

    // Upper bound for n * a
    //@ assert n * a <= 20 * 50;
    // Lower bound for n * a
    //@ assert n * a >= 1 * 1;
    // Upper bound for b
    //@ assert b <= 50;
    // Lower bound for b
    //@ assert b >= 1;

    product = n * a;

    if (product < b)
    {
        min_value = product;
        //@ assert min_value == n * a;
    }
    else
    {
        min_value = b;
        //@ assert min_value == b;
    }

    //@ assert min_value == n * a || min_value == b;
    //@ assert min_value <= b;

    return min_value;
}
