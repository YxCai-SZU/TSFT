#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b;
        valid_range(a) && valid_range(b) ==> product(a, b) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (product(a, b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool is_even;
    unsigned int temp_product;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert product(a, b) <= 100000000;

    product = a * b;
    is_even = true;
    temp_product = product;

    /*@
        loop invariant 0 <= temp_product <= product(a, b);
        loop invariant temp_product % 2 == product(a, b) % 2;
        loop invariant (product(a, b) % 2 == 0) ==> is_even;
        loop assigns temp_product, is_even;
        loop variant temp_product;
    */
    while (temp_product > 0)
    {
        if (temp_product == 1)
        {
            is_even = false;
            break;
        }
        temp_product -= 2;
    }

    if (product == 0)
    {
        is_even = true;
    }

    //@ assert is_even == (product(a, b) % 2 == 0);
    return is_even;
}
