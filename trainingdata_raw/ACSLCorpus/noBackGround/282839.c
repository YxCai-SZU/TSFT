#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (a * b) / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t product;
    uint32_t result = 0;
    uint32_t count;
    uint32_t two = 2;
    
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert a * b <= 10000;
    
    product = a * b;
    count = product;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant result == (product - count) / 2;
        loop invariant count + result * two == product;
        loop invariant product <= 10000;
        loop assigns result, count;
        loop variant count;
    */
    while (count >= two)
    {
        result += 1;
        count -= two;
    }
    
    return result;
}
