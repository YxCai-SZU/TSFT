/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer pi_approx = 314159;
    
    logic integer two_pi_r(integer r) = 2 * pi_approx * r;
    
    lemma two_pi_r_positive: 
        \forall integer r; valid_range(r) ==> two_pi_r(r) >= 0;
    
    lemma two_pi_r_bound: 
        \forall integer r; valid_range(r) ==> two_pi_r(r) <= 2 * 314159 * 100;
*/

/*@
    requires valid_range(r);
    ensures \result == (2 * 314159 * r) / 100000;
    assigns \nothing;
*/
long func(long r)
{
    // Variable declarations at scope top
    long pi_approx;
    long two_pi_r_val;
    long quotient;
    long remainder;
    long divisor;
    
    pi_approx = 314159;
    two_pi_r_val = 2 * pi_approx * r;
    
    //@ assert 0 < two_pi_r_val <= 2 * 314159 * 100;
    
    quotient = 0;
    remainder = two_pi_r_val;
    divisor = 100000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314159;
        loop invariant two_pi_r_val == 2 * pi_approx * r;
        loop invariant two_pi_r_val >= 0;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == two_pi_r_val - quotient * divisor;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        quotient += 1;
        remainder -= divisor;
    }
    
    return quotient;
}
