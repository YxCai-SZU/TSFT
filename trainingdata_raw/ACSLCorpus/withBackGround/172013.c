#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sum_equality(integer a, integer b, integer c, integer d) =
        (a + b == c + d || a + c == b + d || a + d == b + c) ? 1 : 0;

    lemma range_lemma:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            a + b >= 2 && a + b <= 200;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == (sum_equality(a, b, c, d) == 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    if (a + b == c + d || a + c == b + d || a + d == b + c) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (sum_equality(a, b, c, d) == 1);
    return result;
}
