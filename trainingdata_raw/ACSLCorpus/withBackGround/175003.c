#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer square(integer x) = x * x;
    logic integer product(integer a, integer b) = a * b;

    lemma square_bound: \forall integer c; valid_range(c) ==> square(c) <= 10000;
    lemma product_bound: \forall integer a, integer b; valid_range(a) && valid_range(b) ==> product(a, b) <= 10000;
    lemma product_positive: \forall integer a, integer b; valid_range(a) && valid_range(b) ==> product(a, b) >= 1;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == square(c) || \result == product(a, b) || \result == square(d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    int product1;
    int product2;
    int product3;
    int max_value;

    // Precondition verification
    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);

    // Bounds verification
    //@ assert a * b <= 10000;
    //@ assert c * c <= 10000;
    //@ assert d * d <= 10000;
    //@ assert a * b >= 1;

    product1 = a * b;
    product2 = c * c;
    product3 = d * d;

    max_value = product1;

    if (product2 > max_value)
    {
        max_value = product2;
    }

    if (product3 > max_value)
    {
        max_value = product3;
    }

    // Postcondition verification
    //@ assert max_value == product2 || max_value == product1 || max_value == product3;

    return max_value;
}
