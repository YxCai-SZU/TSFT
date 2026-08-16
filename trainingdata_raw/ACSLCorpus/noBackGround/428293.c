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
    // Variable declarations at scope top
    int result;
    int ab_product;
    int cd_product;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);

    ab_product = a * b;
    cd_product = c * d;

    //@ assert 1 <= ab_product <= 10000 * 10000;
    //@ assert 1 <= cd_product <= 10000 * 10000;

    if (ab_product > cd_product)
    {
        //@ assert ab_product >= 1;
        result = ab_product;
    }
    else
    {
        //@ assert cd_product >= 1;
        result = cd_product;
    }

    //@ assert result == ((a) * (b)) || result == ((c) * (d));
    //@ assert result >= 1;
    return result;
}
