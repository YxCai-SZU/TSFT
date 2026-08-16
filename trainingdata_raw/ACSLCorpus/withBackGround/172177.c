#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b, integer c) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;

    logic integer tmp_val(integer a, integer b) = a + (b / 2);

    lemma ans_bounds:
        \forall integer a, b, c;
        valid_inputs(a, b, c) ==>
        tmp_val(a, b) <= c || tmp_val(a, b) <= tmp_val(a, b);
*/

/*@
    requires valid_inputs(a, b, c);
    ensures \result <= c;
    ensures \result <= a + (b / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;
    uint32_t tmp;

    ans = c;
    tmp = a + (b / 2);

    //@ assert ans == c;
    //@ assert tmp == a + (b / 2);

    if (ans > tmp)
    {
        ans = tmp;
        //@ assert ans == tmp;
    }

    //@ assert ans <= c;
    //@ assert ans <= a + (b / 2);

    return ans;
}
