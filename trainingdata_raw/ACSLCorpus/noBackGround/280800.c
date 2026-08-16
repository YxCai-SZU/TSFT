#include <stdint.h>
#include <stdbool.h>

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures \result == -1 || (\result >= 0 && \result == (int)((a * b + 1) / 2));
    ensures \result >= 0 ==> (a * b + 1) % 2 == 0;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t product;
    bool is_even;
    uint32_t temp;
    
    //@ assert 1 <= a * b <= 400;
    product = a * b + 1;
    is_even = false;
    temp = product;
    
    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }
    
    if (temp == 0)
    {
        is_even = true;
    }
    
    if (is_even)
    {
        uint32_t result;
        result = product / 2;
        return (int32_t)result;
    }
    else
    {
        //@ assert 1 <= a * b + 1 <= 401;
        return -1;
    }
}
