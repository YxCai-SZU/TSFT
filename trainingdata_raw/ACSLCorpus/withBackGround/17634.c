#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer total_x(integer n) = n * 800;
    logic integer total_y(integer n) = (n / 15) * 200;
    logic integer expected_result(integer n) = total_x(n) - total_y(n);
    
    lemma x_bound: \forall integer n; is_valid_n(n) ==> total_x(n) <= 80000;
    lemma y_bound: \forall integer n; is_valid_n(n) ==> total_y(n) <= 1333;
    lemma result_bound: \forall integer n; is_valid_n(n) ==> expected_result(n) >= 0;
*/

/*@
    requires 1 <= n && n <= 100;
    ensures \result == (long)(n * 800 - (n / 15) * 200);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t x;
    uint64_t quotient = 0;
    uint64_t remainder = n;
    uint64_t y;
    uint64_t ans;
    
    //@ assert is_valid_n(n);
    
    // Verify n*800 doesn't overflow 64-bit
    //@ assert n * 800 <= 100 * 800;
    x = n * 800;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient <= n / 15;
        loop invariant 0 <= remainder < 15 + n;
        loop invariant remainder + 15 * quotient == n;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15)
    {
        //@ assert remainder >= 15;
        quotient += 1;
        remainder -= 15;
        //@ assert remainder + 15 * quotient == n;
    }
    
    // Verify quotient*200 doesn't exceed (n/15)*200
    //@ assert quotient * 200 <= (n / 15) * 200;
    y = quotient * 200;
    
    ans = x - y;
    
    // Final verification
    //@ assert ans == n * 800 - quotient * 200;
    return (int64_t)ans;
}
