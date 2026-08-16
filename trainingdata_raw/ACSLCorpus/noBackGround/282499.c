#include <stdint.h>

/*@
    requires (1 <= (k) <= 100000);
    ensures \result >= -1;
    ensures \result <= 7;
    assigns \nothing;
*/
int32_t func(uint32_t k)
{
    uint32_t a;
    uint32_t b;
    
    a = 7 % k;
    b = 0;
    
    /*@
        loop invariant (1 <= (k) <= 100000);
        loop invariant 0 <= a < k;
        loop invariant 0 <= b <= 7;
        loop invariant (7 - (b)) >= 0;
        loop assigns a, b;
        loop variant (7 - (b));
    */
    while (a > 0 && b < 7)
    {
        //@ assert a * 10 < k * 10;
        
        a = (a * 10 + 7) % k;
        b += 1;
    }
    
    if (a == 0)
    {
        return (int32_t)b;
    }
    else
    {
        return -1;
    }
}
