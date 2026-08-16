#include <stdint.h>

/*@
    predicate subtraction_safe(unsigned int x, unsigned int y) =
        x >= y && y > 0;
*/

/*@
    logic integer subtraction_result(integer x, integer y) =
        x - y;
*/

/*@
    lemma subtraction_lemma:
        \forall unsigned int x, unsigned int y;
            subtraction_safe(x, y) ==> subtraction_result(x, y) >= 0;
*/

/*@
    requires subtraction_safe(x, y);
    ensures \result == subtraction_result(x, y);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t ans;

    //@ assert subtraction_safe(x, y);
    ans = x - y;

    //@ assert ans == subtraction_result(x, y);

    return ans;
}
