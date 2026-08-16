#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    logic integer calculate_circumference(integer r) = 2 * 3 * r;
    lemma circumference_bound: \forall integer r; valid_range(r) ==> calculate_circumference(r) <= 600;
*/

/*@
    requires valid_range(r);
    ensures \result == calculate_circumference(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t circumference;
    
    //@ assert valid_range(r);
    pi = 3;
    circumference = 2 * pi * r;
    
    //@ assert 2 * pi * r == 2 * 3 * r;
    //@ assert calculate_circumference(r) <= 600;
    
    return circumference;
}
