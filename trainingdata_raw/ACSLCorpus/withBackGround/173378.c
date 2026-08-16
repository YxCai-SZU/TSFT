#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer compute_circumference(integer r) = 2 * 3 * r;

    lemma no_overflow: \forall integer r; valid_range(r) ==> 2 * 3 * r <= 9223372036854775807;
*/

/*@
    requires valid_range(r);
    ensures \result == compute_circumference(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t circumference;
    
    pi_approx = 3;
    
    //@ assert pi_approx == 3;
    //@ assert valid_range(r);
    //@ assert 2 * pi_approx * r == compute_circumference(r);
    
    circumference = 2 * pi_approx * r;
    
    return circumference;
}
