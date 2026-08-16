/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer compute_result(integer a, integer b) = a * 2 * 3 + b * 1;

    lemma multiplication_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 
        a * 2 <= 200 && b * 1 <= 100 && a * 2 * 3 <= 600 && a * 2 * 3 + b * 1 <= 700;
*/

#include <stdint.h>

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t i = 0;
    int32_t result;

    /*@
        loop invariant 0 <= i <= 1;
        loop invariant valid_range(a) && valid_range(b);
        loop assigns i;
    */
    while (i < 1)
    {
        //@ assert a * 2 <= 200;
        //@ assert b * 1 <= 100;
        //@ assert a * 2 * 3 <= 600;
        //@ assert a * 2 * 3 + b * 1 <= 700;
        i++;
    }

    result = (int32_t)(a * 2 * 3) + (int32_t)(b * 1);
    //@ assert result == compute_result(a, b);
    return result;
}
