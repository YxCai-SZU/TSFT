#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 20) && (1 <= (c) <= 2000);
    requires ((a) * (b) <= 2147483647);
    ensures \result <= c;
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    int32_t x;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 20;
    //@ assert a * b <= 2147483647;
    
    x = a * b;
    
    if (x < c)
    {
        return x;
    }
    else
    {
        return c;
    }
}
