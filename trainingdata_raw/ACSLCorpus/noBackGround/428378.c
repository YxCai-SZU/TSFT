#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    uint32_t c;
    uint32_t d;
    uint32_t product;
    
    c = (uint32_t)a;
    d = (uint32_t)b;
    
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= d && d <= 100;
    //@ assert 1 <= c * d && c * d <= 10000;
    
    product = c * d;
    
    //@ assert product == (uint32_t)a * (uint32_t)b;
    //@ assert product <= 10000;
    
    return (int32_t)product;
}
