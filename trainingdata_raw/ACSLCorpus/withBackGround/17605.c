/*@
    predicate is_valid_range(integer x) = 1 <= x <= 179;
    
    logic integer target_result(integer x) = (x * 5 + 1) / 9;
    
    lemma division_property: 
        \forall integer x, q, r, d; 
        x >= 0 && d > 0 && q >= 0 && r >= 0 && r == x - q * d ==> 
        q == x / d ==> r < d;
*/

/*@
    requires is_valid_range(x);
    ensures \result == target_result(x);
*/
int func(int x)
{
    // Variable declarations at scope top
    int x_prime;
    int quotient;
    int remainder;
    int divisor;
    
    x_prime = x * 5 + 1;
    quotient = 0;
    remainder = x_prime;
    divisor = 9;
    
    /*@
        loop invariant 0 <= quotient <= x_prime / divisor;
        loop invariant remainder == x_prime - quotient * divisor;
        loop invariant remainder >= 0;
        loop invariant 1 <= x_prime <= 180 * 5 + 1;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
    }
    
    //@ assert quotient == target_result(x);
    return quotient;
}
