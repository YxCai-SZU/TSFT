#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    logic integer expr1(integer a, integer b, integer c) = a + 10 * b + 100 * c;
    logic integer expr2(integer a, integer b, integer c) = a + 100 * b + 10 * c;
    logic integer expr3(integer a, integer b, integer c) = a + 10 * c + 100 * b;

    lemma bound_expr1: \forall integer a, b, c; valid_input(a, b, c) ==> expr1(a, b, c) <= 999;
    lemma bound_expr2: \forall integer a, b, c; valid_input(a, b, c) ==> expr2(a, b, c) <= 999;
    lemma bound_expr3: \forall integer a, b, c; valid_input(a, b, c) ==> expr3(a, b, c) <= 999;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result == expr1(a, b, c) ||
            \result == expr2(a, b, c) ||
            \result == expr3(a, b, c);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;

    //@ assert valid_input(a, b, c);

    if (a >= b && a >= c)
    {
        ans = a + 10 * b + 100 * c;
        //@ assert ans == expr1(a, b, c);
    }
    else if (b >= a && b >= c)
    {
        ans = a + 100 * b + 10 * c;
        //@ assert ans == expr2(a, b, c);
    }
    else
    {
        ans = a + 10 * c + 100 * b;
        //@ assert ans == expr3(a, b, c);
    }

    //@ assert ans == expr1(a, b, c) || ans == expr2(a, b, c) || ans == expr3(a, b, c);
    return ans;
}
