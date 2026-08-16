#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_non_overflow:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> product(x, y) <= 10000 * 10000;

    lemma product_positive:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> product(x, y) >= 1;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= 1;
    ensures \result <= 10000 * 10000;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Declare all variables at the top
    int product1;
    int product2;
    int max_value;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    // Verify product1 calculation
    //@ assert product(a, b) <= 10000 * 10000;
    product1 = a * b;

    // Verify product2 calculation
    //@ assert product(c, d) <= 10000 * 10000;
    product2 = c * d;

    // Verify product1 positivity
    //@ assert product(a, b) >= 1;

    // Verify product2 positivity
    //@ assert product(c, d) >= 1;

    // Calculate max_value
    if (product1 > product2) {
        max_value = product1;
        //@ assert max_value == product(a, b);
    } else {
        max_value = product2;
        //@ assert max_value == product(c, d);
    }

    // Final verification
    //@ assert max_value >= 1;
    //@ assert max_value <= 10000 * 10000;

    return max_value;
}
