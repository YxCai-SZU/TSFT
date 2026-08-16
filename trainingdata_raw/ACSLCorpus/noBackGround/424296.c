#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000 && 1 <= (m) <= 10000);
    ensures \result == ((((n) * (m)) % 2) != 0);
    assigns \nothing;
*/
bool func(unsigned long n, unsigned long m)
{
    // Variable declarations at scope top
    unsigned long product;
    bool is_odd;

    //@ assert (1 <= (n) <= 10000 && 1 <= (m) <= 10000);
    //@ assert n * m <= 10000 * 10000;

    product = n * m;
    is_odd = false;

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 1 <= m <= 10000;
        loop invariant product <= n * m;
        loop invariant product >= 0;
        loop invariant product % 2 == (((n) * (m)) % 2);
        loop assigns product;
        loop variant product;
    */
    while (product >= 2)
    {
        product -= 2;
    }

    if (product == 1)
    {
        is_odd = true;
    }

    //@ assert is_odd == ((((n) * (m)) % 2) != 0);
    return is_odd;
}
