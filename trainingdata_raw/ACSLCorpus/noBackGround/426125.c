#include <stdint.h>

/*@
    requires (1 <= (k) && (k) <= 99999);
    ensures \result >= 0 || \result == -1;
*/
int32_t func(uint32_t k)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t temp_k = k;
    uint32_t count = 0;
    
    //@ assert (1 <= (k) && (k) <= 99999);
    
    /*@
        loop invariant 1 <= k <= 99999;
        loop invariant temp_k <= k;
        loop invariant temp_k >= 0;
        loop invariant a >= 0;
        loop invariant a <= ((k) / 100);
        loop invariant k == temp_k + 100 * a;
        loop assigns temp_k, a;
        loop variant temp_k;
    */
    while (temp_k >= 100)
    {
        //@ assert temp_k >= 100;
        temp_k -= 100;
        a += 1;
        //@ assert k == temp_k + 100 * a;
    }
    b = temp_k;
    
    uint32_t sum = a + b;
    uint32_t quotient = 0;
    uint32_t remainder = sum;
    
    /*@
        loop invariant 1 <= k <= 99999;
        loop invariant sum == a + b;
        loop invariant a >= 0;
        loop invariant b >= 0;
        loop invariant quotient >= 0;
        loop invariant remainder == sum - 100 * quotient;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100)
    {
        //@ assert remainder >= 100;
        remainder -= 100;
        quotient += 1;
        //@ assert remainder == sum - 100 * quotient;
    }
    
    uint32_t result = quotient * 100 + remainder;
    
    if (result < 1000)
    {
        //@ assert result < 1000;
        return -1;
    }
    else
    {
        //@ assert result >= 1000;
        return (int32_t)result;
    }
}
