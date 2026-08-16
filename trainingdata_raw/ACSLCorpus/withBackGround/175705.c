#include <stdint.h>

/*@
    predicate valid_radius(integer r) = 1 <= r && r <= 100;
    
    logic integer pi_approx = 314159;
    
    logic integer expected_circumference(integer r) = 
        2 * pi_approx * r / 100000;
    
    lemma circumference_bounds: 
        \forall integer r; valid_radius(r) ==> 
            0 <= expected_circumference(r) && 
            expected_circumference(r) <= 628318 * r / 100000;
*/

/*@
    requires valid_radius(r);
    ensures \result >= 0;
    ensures \result <= 314159 * 2 * r / 100000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t circumference = 0;
    int64_t temp;
    int64_t divisor;
    int64_t pi_approx_local = 314159;
    
    // Precondition check
    //@ assert 1 <= r && r <= 100;
    
    temp = 2 * pi_approx_local * r;
    divisor = 100000;
    
    // Non-linear arithmetic safety
    //@ assert 2 * pi_approx_local * r <= 2 * 314159 * 100;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant 0 <= circumference;
        loop invariant 0 <= temp;
        loop invariant temp + circumference * divisor == 2 * pi_approx_local * r;
        loop invariant circumference <= 628318 * r / 100000;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        circumference += 1;
    }
    
    // Postcondition verification
    //@ assert circumference >= 0;
    //@ assert circumference <= 314159 * 2 * r / 100000;
    
    return circumference;
}

int main(void)
{
    return 0;
}
