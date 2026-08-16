#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * (r) * 3141593 / 1000000);
*/
int32_t func(int32_t r)
{
    // Variable declarations
    int32_t pi_approx = 3141593;
    int32_t scaled_r = r * pi_approx;
    int32_t scaled_r_doubled = scaled_r * 2;
    int32_t result = 0;
    int32_t temp = scaled_r_doubled;
    int32_t count = 0;
    
    //@ assert pi_approx == 3141593;
    //@ assert scaled_r == r * pi_approx;
    //@ assert scaled_r_doubled == scaled_r * 2;
    //@ assert temp == scaled_r_doubled;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 3141593;
        loop invariant scaled_r == r * pi_approx;
        loop invariant scaled_r_doubled == scaled_r * 2;
        loop invariant temp >= 0;
        loop invariant temp == scaled_r_doubled - count * 1000000;
        loop invariant count >= 0;
        loop assigns temp, count;
    */
    while (temp >= 1000000) {
        //@ assert temp >= 1000000;
        temp -= 1000000;
        count += 1;
        //@ assert temp == scaled_r_doubled - count * 1000000;
    }
    
    result = count;
    //@ assert result == (2 * (r) * 3141593 / 1000000);
    return result;
}
