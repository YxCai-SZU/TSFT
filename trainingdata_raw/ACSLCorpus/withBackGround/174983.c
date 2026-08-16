#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer quotient_calc(integer n) = n / 15;
    
    logic integer expected_result(integer n) = n * 800 - quotient_calc(n) * 200;
*/

/*@
    requires valid_n(n);
    ensures \result == expected_result(n);
    ensures \result >= 0;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y;
    uint32_t quotient;
    uint32_t temp_n;
    int32_t result;
    
    x = 800;
    y = 200;
    quotient = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient;
        loop invariant quotient <= quotient_calc(n);
        loop invariant temp_n == n - quotient * 15;
        loop invariant x == 800;
        loop invariant y == 200;
        loop assigns quotient, temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        quotient += 1;
    }
    
    result = (x * (int32_t)n) - ((int32_t)quotient * y);
    
    //@ assert result == expected_result(n);
    
    return result;
}

int main()
{
    return 0;
}
