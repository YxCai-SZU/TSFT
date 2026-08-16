/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    
    logic integer scaled_value(integer r) = r * 2 * 31415;
    
    logic integer expected_result(integer r) = 2 * 31415 * r / 10000;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
*/
unsigned long func(unsigned long r)
{
    // Variable declarations at scope top
    unsigned long pi_approx;
    unsigned long scaled_r;
    unsigned long divisor;
    unsigned long quotient;
    unsigned long remainder;
    
    pi_approx = 31415;
    scaled_r = r * 2 * pi_approx;
    divisor = 10000;
    quotient = 0;
    remainder = scaled_r;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant pi_approx == 31415;
        loop invariant divisor == 10000;
        loop invariant quotient >= 0;
        loop invariant scaled_r == r * 2 * pi_approx;
        loop invariant remainder + quotient * divisor == scaled_r;
        loop invariant quotient <= 2 * 31415 * 100 / 10000;
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
    }
    
    //@ assert quotient == expected_result(r);
    return quotient;
}
