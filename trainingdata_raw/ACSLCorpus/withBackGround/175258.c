/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    logic integer scaled_pi = 314159;
    logic integer scale_factor = 100000;
    logic integer two = 2;
    
    lemma loop_invariant_maintained:
        \forall integer r, integer circ, integer temp;
        valid_range(r) && temp >= scale_factor && 
        circ * scale_factor + temp == r * two * scaled_pi ==>
        (circ + 1) * scale_factor + (temp - scale_factor) == r * two * scaled_pi;
*/

#include <stdint.h>

/*@
    requires valid_range(r);
    ensures \result == 2 * r * 314159 / 100000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi = 314159;
    int64_t two = 2;
    int64_t scale = 100000;
    int64_t circumference = 0;
    int64_t temp_r = r * two * pi;
    
    //@ assert pi == 314159;
    //@ assert two == 2;
    //@ assert scale == 100000;
    //@ assert temp_r == r * two * pi;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant two == 2;
        loop invariant scale == 100000;
        loop invariant temp_r >= 0;
        loop invariant circumference * scale + temp_r == r * two * pi;
        loop assigns circumference, temp_r;
    */
    while (temp_r >= scale) {
        //@ assert temp_r >= scale;
        circumference += 1;
        temp_r -= scale;
        //@ assert circumference * scale + temp_r == r * two * pi;
    }
    
    //@ assert circumference * scale + temp_r == r * two * pi;
    //@ assert temp_r < scale;
    //@ assert circumference == 2 * r * 314159 / 100000;
    return circumference;
}
