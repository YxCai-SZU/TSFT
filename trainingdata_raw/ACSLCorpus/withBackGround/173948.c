#include <stdint.h>

/*@
    predicate is_valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 1000000000 &&
        1 <= b && b <= 1000000000 &&
        1 <= c && c <= 1000000000;

    logic integer min(integer x, integer y) =
        x <= y ? x : y;

    lemma min_bound1:
        \forall integer x, y; min(x, y) <= x;

    lemma min_bound2:
        \forall integer x, y; min(x, y) <= y;
*/

/*@
    requires is_valid_input(a, b, c);
    ensures \result <= c;
    ensures \result <= b / a;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c)
{
    uint64_t result;

    //@ assert 1 <= a && a <= 1000000000;
    //@ assert 1 <= b && b <= 1000000000;
    //@ assert 1 <= c && c <= 1000000000;

    if (b / a < c)
    {
        //@ assert b / a <= b / a;
        result = b / a;
    }
    else
    {
        //@ assert c <= b / a;
        result = c;
    }

    //@ assert result <= c;
    //@ assert result <= b / a;
    return result;
}
