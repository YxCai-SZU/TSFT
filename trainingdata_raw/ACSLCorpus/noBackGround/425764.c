#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (((a) + (b) + (c)) / 3);
    ensures 1 <= \result <= 100;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t sum;
    uint32_t result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    sum = a + b + c;
    //@ assert sum == a + b + c;
    
    result = sum / 3;
    //@ assert result == sum / 3;
    
    //@ assert sum / 3 == (((a) + (b) + (c)) / 3);
    //@ assert 1 <= a + b + c <= 300;
    //@ assert 0 <= a + b + c - 3 <= 297;
    //@ assert 0 <= (a + b + c - 3) / 3 <= 99;
    //@ assert result >= 1;
    //@ assert result <= 100;
    
    return result;
}
