#include <stdint.h>

/*@
    predicate valid_params(integer x, integer y, integer z) =
        1 <= x && x <= 100000 &&
        1 <= y && y <= 100000 &&
        1 <= z && z <= 100000 &&
        y + 2 * z <= x;
*/

/*@
    logic integer division_result(integer x, integer y, integer z) =
        (x - z) / (y + z);
*/

/*@
    lemma result_bounds:
        \forall integer x, y, z;
        valid_params(x, y, z) ==>
        0 <= division_result(x, y, z) &&
        division_result(x, y, z) <= x;
*/

/*@
    requires valid_params(x, y, z);
    ensures \result >= 0;
    ensures \result <= x;
    assigns \nothing;
*/
int32_t func(uint32_t x, uint32_t y, uint32_t z) {
    int32_t ans = 0;
    int32_t numerator = (int32_t)x - (int32_t)z;
    int32_t denominator = (int32_t)y + (int32_t)z;

    /*@
        loop invariant 0 <= numerator <= x;
        loop invariant 0 <= ans <= x;
        loop invariant ans <= x - numerator;
        loop invariant valid_params(x, y, z);
        loop assigns numerator, ans;
        loop variant numerator;
    */
    while (numerator >= denominator) {
        //@ assert numerator >= denominator;
        numerator -= denominator;
        ans += 1;
    }

    return ans;
}
