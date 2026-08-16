#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 10000 &&
        1 <= b <= 10000 &&
        a * b <= 0x7FFFFFFF;

    logic integer product(integer a, integer b) = a * b;

    lemma product_non_negative: \forall integer a, b; valid_range(a, b) ==> product(a, b) >= 0;
*/

/*@
    requires valid_range(a, b);
    ensures \result == (product(a, b) % 2 == 0);
*/
bool func(int a, int b)
{
    int product;
    bool is_even;
    int abs_product;

    product = a * b;
    is_even = true;
    abs_product = product;

    //@ assert product >= 0;

    /*@
        loop invariant 0 <= abs_product <= 0x7FFFFFFF;
        loop invariant abs_product <= product;
        loop invariant (abs_product % 2 == 0) == (product % 2 == 0);
        loop invariant (product % 2 == 0) ==> is_even;
        loop assigns abs_product, is_even;
    */
    while (abs_product > 0)
    {
        if (abs_product == 1)
        {
            is_even = false;
            break;
        }
        abs_product -= 2;
    }

    //@ assert (product % 2 == 0) == is_even;
    return is_even;
}
