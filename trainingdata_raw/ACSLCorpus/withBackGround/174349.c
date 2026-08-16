#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer multiply_800(integer n) = n * 800;
    
    logic integer divide_by_15(integer n) = n / 15;
    
    logic integer final_result(integer n) = 
        multiply_800(n) - 200 * divide_by_15(n) - 200;
*/

/*@
    requires is_valid_n(n);
    ensures \result == final_result(n);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    uint64_t x;
    uint64_t quotient;
    uint64_t remainder;
    int64_t ans;
    uint64_t y;
    
    //@ assert is_valid_n(n);
    
    //@ assert n * 800 <= 100 * 800;
    x = n * 800;
    
    quotient = 0;
    remainder = n;
    
    /*@
        loop invariant is_valid_n(n);
        loop invariant 0 <= quotient <= n / 15;
        loop invariant remainder == n - quotient * 15;
        loop invariant 0 <= remainder < 15 + n;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15)
    {
        quotient = quotient + 1;
        remainder = remainder - 15;
    }
    
    y = 200 * quotient + 200;
    ans = (int64_t)x - (int64_t)y;
    
    //@ assert ans == final_result(n);
    return ans;
}
