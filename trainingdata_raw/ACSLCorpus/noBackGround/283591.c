#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 3 * (r));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_approx;
    int64_t circumference;
    
    pi_approx = 3;
    circumference = 2 * pi_approx * r;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert (2 * 3 * (r)) == 2 * pi_approx * r;
    
    return circumference;
}

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 3 * (r));
    assigns \nothing;
*/
int64_t func2(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_approx;
    int64_t circumference;
    
    pi_approx = 3;
    circumference = 2 * pi_approx * r;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert (2 * 3 * (r)) == 2 * pi_approx * r;
    
    return circumference;
}

