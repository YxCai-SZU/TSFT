#include <stdint.h>


int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t scaled_r_val;
    int64_t numerator;
    int64_t quotient;
    int64_t denominator;
    
    // Variable declarations at top
    pi_approx = 314;
    scaled_r_val = r * 100;
    numerator = 2 * pi_approx * scaled_r_val;
    quotient = 0;
    denominator = 10000;
    
    //@ assert pi_approx == 314;
    //@ assert scaled_r_val == ((r) * 100);
    //@ assert numerator == (2 * 314 * (((r)) * 100));
    //@ assert 0 <= numerator <= 6280000;
    
    
    while (numerator >= denominator)
    {
        numerator -= denominator;
        quotient += 1;
    }
    
    //@ assert quotient == (2 * (r) * 314 / 100);
    return quotient;
}

int main(void)
{
    return 0;
}
