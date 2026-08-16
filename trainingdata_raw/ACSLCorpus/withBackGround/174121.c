#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    logic integer product(integer a, integer b, integer c) = a * b * c;
    logic integer product_ab(integer a, integer b) = a * b;
    logic integer product_ac(integer a, integer c) = a * c;
    logic integer product_bc(integer b, integer c) = b * c;

    lemma product_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            1 <= product_ab(a, b) <= 100 &&
            1 <= product_ac(a, c) <= 100 &&
            1 <= product_bc(b, c) <= 100 &&
            1 <= product(a, b, c) <= 1000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == product(a, b, c) ||
            \result == product_ab(a, b) ||
            \result == product_ac(a, c) ||
            \result == product_bc(b, c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int max;
    int ab;
    int ac;
    int bc;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);

    // Precondition ensures these multiplications don't overflow 32-bit int
    ab = a * b;
    ac = a * c;
    bc = b * c;
    max = a * b * c;

    if (ab > max)
    {
        max = ab;
    }
    if (ac > max)
    {
        max = ac;
    }
    if (bc > max)
    {
        max = bc;
    }

    //@ assert max == product(a, b, c) || max == product_ab(a, b) || max == product_ac(a, c) || max == product_bc(b, c);
    return max;
}
