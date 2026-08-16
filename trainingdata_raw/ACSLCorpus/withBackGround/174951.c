#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer product_mod2(integer x, integer y) = (x * y) % 2;

    lemma product_bounds:
        \forall integer x, y;
        valid_range(x) && valid_range(y) ==> 1 <= x * y <= 10000 * 10000;
*/

/*@
    requires valid_range(x) && valid_range(y);
    ensures \result == (product_mod2(x, y) == 0);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations
    unsigned int product;
    bool is_even;
    unsigned int temp;

    // Precondition assertions
    //@ assert valid_range(x);
    //@ assert valid_range(y);

    // Calculate product
    product = x * y;

    // Initialize variables
    is_even = true;
    temp = product;

    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop invariant valid_range(x) && valid_range(y);
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp != 0)
    {
        is_even = false;
    }

    // Postcondition verification
    //@ assert is_even == (product_mod2(x, y) == 0);

    return is_even;
}

int main(void)
{
    return 0;
}
