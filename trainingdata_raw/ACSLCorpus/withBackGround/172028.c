#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 10000 &&
        1 <= b <= 10000 &&
        a * b <= 2147483647;

    logic integer product_mod2(integer a, integer b) = (a * b) % 2;

    lemma product_non_overflow: \forall integer a, b; valid_range(a, b) ==> a * b <= 2147483647;
*/

/*@
    requires valid_range(a, b);
    ensures \result == (product_mod2(a, b) == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    int product;
    bool is_even;
    int abs_product;

    product = a * b;
    is_even = true;
    abs_product = product;

    //@ assert product == a * b;

    if (product < 0)
    {
        abs_product = -product;
    }

    //@ assert abs_product >= 0;

    /*@
        loop invariant 0 <= abs_product <= product;
        loop invariant abs_product % 2 == product % 2;
        loop invariant (product % 2 == 0) ==> is_even;
        loop assigns abs_product, is_even;
        loop variant abs_product;
    */
    while (abs_product >= 2)
    {
        abs_product -= 2;
        //@ assert abs_product % 2 == product % 2;
    }

    if (abs_product != 0)
    {
        is_even = false;
    }

    //@ assert is_even == (product_mod2(a, b) == 0);
    return is_even;
}
