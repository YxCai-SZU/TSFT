#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures 1 <= \result <= 10000 * 10000;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_val;
    int ab_product;
    int cd_product;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    ab_product = a * b;
    cd_product = c * d;

    //@ assert ab_product <= 10000 * 10000;
    //@ assert cd_product <= 10000 * 10000;

    if (ab_product > cd_product)
    {
        max_val = ab_product;
    }
    else
    {
        max_val = cd_product;
    }

    //@ assert max_val == a * b || max_val == c * d;
    //@ assert 1 <= max_val <= 10000 * 10000;

    return max_val;
}
