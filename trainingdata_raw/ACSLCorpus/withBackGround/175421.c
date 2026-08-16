#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer scaled_pi = 3141592653;
    logic integer scale_factor = 1000000000;
    logic integer two_pi_scaled = 2 * scaled_pi;
    
    logic integer expected_result(integer n) = 
        (2 * scaled_pi) * n / scale_factor;
*/

/*@
    requires valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    // Variable declarations at top of scope
    int64_t scale_factor;
    int64_t pi_scaled;
    int64_t two_pi_scaled;
    int64_t result;
    int64_t temp_n;
    
    scale_factor = 1000000000;
    pi_scaled = 3141592653;
    two_pi_scaled = 2 * pi_scaled;
    
    //@ assert 0 < two_pi_scaled * n;
    //@ assert two_pi_scaled * n <= 200 * pi_scaled;
    
    result = 0;
    temp_n = n * two_pi_scaled;
    
    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant result * scale_factor + temp_n == n * two_pi_scaled;
        loop invariant result * scale_factor + temp_n <= 200 * pi_scaled;
        loop invariant temp_n >= 0;
        loop invariant result >= 0;
        loop assigns temp_n, result;
        loop variant temp_n;
    */
    while (temp_n >= scale_factor)
    {
        temp_n -= scale_factor;
        result += 1;
    }
    
    //@ assert result * scale_factor + temp_n == n * two_pi_scaled;
    
    return result;
}

int main(void)
{
    return 0;
}
