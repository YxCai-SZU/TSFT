#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_product(integer r) = 2 * r * 314159;
    
    logic integer expected_result(integer r) = (2 * r * 314159) / 100000;
    
    lemma product_non_negative: \forall integer r; valid_range(r) ==> calculate_product(r) >= 0;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
*/
int32_t func(uint32_t r)
{
    // Variable declarations
    int32_t precision_factor;
    int32_t pi;
    int32_t product;
    int32_t quotient;
    int32_t remainder;
    int32_t divisor;
    
    // Initialization
    precision_factor = 100000;
    pi = 314159;
    product = 2 * (int32_t)r * pi;
    
    // Division implementation
    quotient = 0;
    remainder = product;
    divisor = precision_factor;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant precision_factor == 100000;
        loop invariant pi == 314159;
        loop invariant product == 2 * (int32_t)r * pi;
        loop invariant quotient * divisor + remainder == product;
        loop invariant 0 <= remainder < divisor + product;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
        //@ assert quotient * divisor + remainder == product;
    }
    
    //@ assert quotient == expected_result(r);
    return quotient;
}

int main(void)
{
    return 0;
}
