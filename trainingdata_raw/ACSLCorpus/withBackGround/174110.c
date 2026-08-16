#include <stdint.h>

/*@
    predicate valid_params(integer k, integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        a + b <= k && k <= 100;

    lemma subtraction_valid: 
        \forall integer k, a, b; 
        valid_params(k, a, b) ==> k - a - b >= 0;
*/

/*@
    requires valid_params(k, a, b);
    ensures \result == k - a - b;
    assigns \nothing;
*/
uint32_t max_circular_track_collisions(uint32_t k, uint32_t a, uint32_t b)
{
    //@ assert valid_params(k, a, b);
    //@ assert k - a >= 0;
    //@ assert k - a - b >= 0;
    return k - a - b;
}
