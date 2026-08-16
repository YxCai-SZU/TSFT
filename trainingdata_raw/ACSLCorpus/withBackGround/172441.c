#include <limits.h>

/*@
    predicate in_range(integer v, integer low, integer high) =
        low <= v && v <= high;

    logic integer product(integer n, integer m) = n * m;

    lemma product_range:
        \forall integer n, m;
            in_range(n, 1, 10000) && in_range(m, 1, 10000) ==>
            in_range(product(n, m), 1, 10000 * 10000);
*/

/*@
    requires in_range(n, 1, 10000);
    requires in_range(m, 1, 10000);
    ensures \result == ( (n * m) % 2 != 0 );
    assigns \nothing;
*/
int func(int n, int m)
{
    int product;
    int is_odd;
    int abs_product;

    //@ assert in_range(n, 1, 10000);
    //@ assert in_range(m, 1, 10000);
    //@ assert in_range(n * m, 1, 10000 * 10000);

    product = n * m;

    is_odd = 0;
    if (product < 0)
    {
        abs_product = -product;
    }
    else
    {
        abs_product = product;
    }

    /*@
        loop invariant in_range(abs_product, 0, 10000 * 10000);
        loop invariant in_range(n, 1, 10000);
        loop invariant in_range(m, 1, 10000);
        loop invariant abs_product <= n * m;
        loop invariant (abs_product % 2) == (product % 2);
        loop invariant in_range(n * m, 1, 10000 * 10000);
        loop assigns abs_product;
        loop variant abs_product;
    */
    while (abs_product >= 2)
    {
        abs_product = abs_product - 2;
    }

    if (abs_product == 1)
    {
        is_odd = 1;
    }

    //@ assert is_odd == ( (n * m) % 2 != 0 );
    return is_odd;
}
