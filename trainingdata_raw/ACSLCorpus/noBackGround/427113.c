#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - ((a) + (b) - 1));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t product;
    uint32_t sum_minus_one;
    uint32_t final_result;
    int32_t signed_result;

    //@ assert (2 <= (a) && (a) <= 100 &&         2 <= (b) && (b) <= 100);
    
    // Verify multiplication bounds
    product = a * b;
    //@ assert product <= 100 * 100;
    
    // Verify addition bounds
    sum_minus_one = a + b - 1;
    //@ assert sum_minus_one <= 100 + 100 - 1;
    
    // Verify subtraction non-negative
    //@ assert product >= sum_minus_one;
    
    final_result = product - sum_minus_one;
    signed_result = (int32_t)final_result;
    
    // Verify i32 bounds
    //@ assert signed_result >= -2147483648;
    //@ assert signed_result <= 2147483647;
    
    return signed_result;
}
