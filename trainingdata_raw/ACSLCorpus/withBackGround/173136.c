#include <stdint.h>

/*@
    predicate is_zero(integer x) = x == 0;
    predicate is_one(integer x) = x == 1;
*/

/*@
    requires 0 <= x <= 1;
    ensures is_zero(x) ==> \result == 1;
    ensures is_one(x) ==> \result == 0;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t a;
    //@ ghost int32_t proof_a;

    a = 1 - (int32_t)x;
    //@ ghost proof_a = a;

    /*@
        assert x == 0 ==> proof_a == 1;
    */
    /*@
        assert x == 1 ==> proof_a == 0;
    */

    return a;
}
