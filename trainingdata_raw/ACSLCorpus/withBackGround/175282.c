/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    
    logic integer scaled_pi = 314159;
    logic integer scaling_factor = 100000;
    
    logic integer expected_circumference(integer r) = (2 * scaled_pi * r) / scaling_factor;
    
    lemma loop_invariant_maintained:
        \forall integer r, integer temp, integer count, integer circ;
        valid_range(r) && temp == 2 * scaled_pi * r - count * scaling_factor && 
        temp >= 0 && count >= 0 && circ == count ==>
        (temp - scaling_factor) == 2 * scaled_pi * r - (count + 1) * scaling_factor;
*/

#include <stdint.h>

/*@
    requires valid_range(r);
    ensures \result == expected_circumference(r);
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_approx;
    int64_t scale;
    int64_t circumference;
    int64_t temp;
    int64_t count;
    
    pi_approx = 314159;
    scale = 100000;
    circumference = 0;
    temp = 2 * pi_approx * r;
    count = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314159;
        loop invariant scale == 100000;
        loop invariant temp >= 0;
        loop invariant temp == 2 * pi_approx * r - count * scale;
        loop invariant count >= 0;
        loop invariant circumference == count;
        loop assigns circumference, temp, count;
        loop variant temp;
    */
    while (temp >= scale) {
        //@ assert temp == 2 * pi_approx * r - count * scale;
        circumference += 1;
        temp -= scale;
        count += 1;
        //@ assert temp == 2 * pi_approx * r - count * scale;
    }
    
    //@ assert circumference == (2 * pi_approx * r) / scale;
    return circumference;
}
