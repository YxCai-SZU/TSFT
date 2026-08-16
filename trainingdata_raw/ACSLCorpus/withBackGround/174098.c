#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;

    logic integer multiply_800(integer n) = n * 800;
    logic integer divide_by_15(integer n) = n / 15;
    logic integer multiply_200(integer q) = q * 200;
    logic integer final_result(integer n) = 
        multiply_800(n) - multiply_200(divide_by_15(n)) - 200;

    lemma overflow_bound: \forall integer n; is_valid_n(n) ==> multiply_800(n) <= 80000;
    lemma quotient_bound: \forall integer n; is_valid_n(n) ==> 0 <= divide_by_15(n) && divide_by_15(n) <= 6;
    lemma remainder_property: \forall integer n, q, r; 
        is_valid_n(n) && q == divide_by_15(n) && r == n - q * 15 ==> 0 <= r && r < 15;
*/

/*@
    requires 1 <= n && n <= 100;
    ensures \result == final_result(n);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    uint64_t x;
    uint64_t quotient;
    uint64_t remainder;
    int64_t y;
    int64_t ans;

    //@ assert is_valid_n(n);
    //@ assert multiply_800(n) <= 80000;
    
    x = n * 800;
    
    quotient = 0;
    remainder = n;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= divide_by_15(n);
        loop invariant remainder == n - quotient * 15;
        loop invariant 0 <= remainder;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15)
    {
        //@ assert remainder >= 15;
        quotient = quotient + 1;
        remainder = remainder - 15;
        //@ assert remainder == n - quotient * 15;
    }
    
    //@ assert quotient == divide_by_15(n);
    //@ assert remainder == n - quotient * 15;
    
    y = (int64_t)(quotient * 200);
    ans = (int64_t)x - y - 200;
    
    //@ assert ans == final_result(n);
    return ans;
}
