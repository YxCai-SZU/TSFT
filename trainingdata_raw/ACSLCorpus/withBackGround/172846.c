/*@
    predicate is_valid_range(integer n) = 1 <= n <= 100;
    
    logic integer total_x(integer n) = n * 800;
    logic integer total_y(integer n) = (n / 15) * 200;
    logic integer expected_result(integer n) = total_x(n) - total_y(n);
    
    lemma x_no_overflow: \forall integer n; is_valid_range(n) ==> total_x(n) <= 80000;
    lemma quotient_bound: \forall integer n; is_valid_range(n) ==> 0 <= n/15 <= 6;
*/

/*@
    requires is_valid_range(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at scope top
    int x;
    int quotient = 0;
    int remainder = n;
    int divisor = 15;
    int y;
    int ans;
    
    // Precondition check
    //@ assert is_valid_range(n);
    
    // Calculate x = n * 800
    //@ assert total_x(n) <= 80000;
    x = n * 800;
    
    // Loop for division by 15
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= n / 15;
        loop invariant remainder == n - quotient * 15;
        loop invariant 0 <= quotient * 15 <= 1500;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        quotient += 1;
        remainder -= divisor;
    }
    
    // Verify quotient bounds
    //@ assert 0 <= quotient && quotient <= 6;
    
    y = quotient * 200;
    ans = x - y;
    
    // Final verification
    //@ assert ans == expected_result(n);
    
    return ans;
}
