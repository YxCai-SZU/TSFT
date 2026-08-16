#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    //@ assert ((a) + (b) + (c)) <= 300;
    //@ assert ((a) * (b)) <= 10000;
    //@ assert ((a) * (c)) <= 10000;
    
    uint32_t result = a + b + c;
    //@ assert result == ((a) + (b) + (c));
    //@ assert result >= 0;
    //@ assert result <= a + b + c;
    
    return result;
}
