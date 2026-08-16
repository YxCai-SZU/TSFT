#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == true <==> (a * b - 1) >= (c * d);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at scope top
    unsigned int ab_product;
    unsigned int cd_product;
    bool result;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert 0 < a * b <= 10000 * 10000;

    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert 0 < c * d <= 10000 * 10000;

    //@ assert a * b - 1 >= 0;

    ab_product = a * b;
    cd_product = c * d;

    //@ assert ab_product - 1 >= 0;

    result = (ab_product - 1) >= cd_product;
    return result;
}
