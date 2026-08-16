#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product_mod_2(integer a, integer b) = (a * b) % 2;

    lemma product_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> a * b <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (product_mod_2(a, b) == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product;
    bool is_even = false;
    unsigned int n;

    //@ assert a * b <= 10000 * 10000;
    product = a * b;
    n = product;

    /*@
        loop invariant 1 <= a <= 10000;
        loop invariant 1 <= b <= 10000;
        loop invariant n <= a * b;
        loop invariant n >= 0;
        loop invariant n % 2 == product % 2;
        loop assigns n;
        loop variant n;
    */
    while (n >= 2)
    {
        n -= 2;
    }

    if (n == 0)
    {
        is_even = true;
    }

    //@ assert is_even == (product % 2 == 0);
    return is_even;
}
