#include <stdbool.h>
#include <stdint.h>

/*@
    requires 1 <= n <= 1000000000;
    ensures \result % 2 == 0;
    ensures 2 <= \result <= 2 * n;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t result;
    uint32_t two;
    bool is_even;
    uint32_t temp_n;
    
    result = 0;
    two = 2;
    is_even = false;
    temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n % 2 == n % 2;
        loop assigns temp_n;
        loop variant temp_n;
    */
    while (temp_n >= two)
    {
        //@ assert temp_n >= 2;
        temp_n = temp_n - two;
        //@ assert temp_n % 2 == n % 2;
    }
    
    //@ assert temp_n < 2;
    //@ assert temp_n % 2 == n % 2;
    
    if (temp_n == 0)
    {
        is_even = true;
    }
    
    if (is_even)
    {
        result = n;
        //@ assert result == n;
    }
    else
    {
        result = two * n;
        //@ assert result == 2 * n;
    }
    
    //@ assert result % 2 == 0;
    //@ assert 2 <= result <= 2 * n;
    
    return result;
}
