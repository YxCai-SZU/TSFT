#include <stdint.h>

/*@
    predicate valid_radius(integer r) = 1 <= r <= 100;

    logic integer calculate_circumference(integer r) = 6 * r;

    lemma circumference_bounds:
        \forall integer r; valid_radius(r) ==> 
            6 * 1 <= calculate_circumference(r) <= 6 * 100;
*/

/*@
    requires valid_radius(r);
    ensures \result == calculate_circumference(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t circumference;
    
    //@ assert valid_radius(r);
    
    pi = 3;
    circumference = 2 * pi * r;
    
    // Critical verification property
    //@ assert circumference == 6 * r;
    
    return circumference;
}
