#include <limits.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
long func(long n, long a, long b)
{
    // Variable declarations at scope top
    long product;
    long min_val;

    // Precondition verification
    //@ assert 1 <= n <= 20;
    //@ assert 1 <= a <= 50;
    //@ assert 1 <= b <= 50;

    // Calculate product with overflow protection
    //@ assert 1 <= n * a <= 1000;
    product = n * a;

    // Determine minimum value
    if (product < b)
    {
        min_val = product;
    }
    else
    {
        min_val = b;
    }

    // Postcondition verification
    //@ assert min_val == n * a || min_val == b;
    //@ assert min_val <= b;

    return min_val;
}
