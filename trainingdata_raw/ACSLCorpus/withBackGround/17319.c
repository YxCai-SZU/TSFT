#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 1000000000;

    predicate sum_condition(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;

    lemma no_overflow_a_b:
        \forall integer a, b; valid_range(a) && valid_range(b) ==> a + b <= 2147483647;

    lemma no_overflow_a_c:
        \forall integer a, c; valid_range(a) && valid_range(c) ==> a + c <= 2147483647;

    lemma no_overflow_b_c:
        \forall integer b, c; valid_range(b) && valid_range(c) ==> b + c <= 2147483647;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == true <==> sum_condition(a, b, c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool ans = false;

    //@ assert a + b <= 2147483647;
    if (a + b == c)
    {
        ans = true;
    }

    //@ assert a + c <= 2147483647;
    if (a + c == b)
    {
        ans = true;
    }

    //@ assert b + c <= 2147483647;
    if (b + c == a)
    {
        ans = true;
    }

    return ans;
}
