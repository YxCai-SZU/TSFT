#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer remainder_formula(integer b, integer c) =
        (b * 10 + c) % 4;

    lemma remainder_equality:
        \forall integer b, c;
        valid_range(b) && valid_range(c) ==>
        ((b * 2 + c) % 4) == remainder_formula(b, c);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (remainder_formula(b, c) < 1);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int sum;
    unsigned int remainder;

    // Variable declarations at scope top
    sum = b * 2 + c;
    remainder = (unsigned int)sum % 4u;

    //@ assert remainder == remainder_formula(b, c);

    return remainder < 1u;
}
