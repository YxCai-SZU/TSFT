/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    
    logic integer scaled_pi(integer r) = 2 * r * 314;
    
    logic integer expected_result(integer r) = 2 * r * 314 / 100;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
long func(unsigned int r)
{
    long pi_approx = 314;
    long scale = 100;
    long numerator = 2 * (long)r * pi_approx;
    long quotient = 0;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant pi_approx == 314;
        loop invariant scale == 100;
        loop invariant numerator >= 0;
        loop invariant numerator == scaled_pi(r) - quotient * scale;
        loop invariant quotient >= 0;
        loop invariant quotient <= expected_result(r);
        loop assigns numerator, quotient;
        loop variant numerator;
    */
    while (numerator >= scale)
    {
        numerator -= scale;
        quotient += 1;
    }
    
    //@ assert quotient == expected_result(r);
    
    return quotient;
}

int main(void)
{
    return 0;
}
